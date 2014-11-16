#ifndef ATT_SPARK_H
#define ATT_SPARK_H

#include "MQTT/MQTT.h"

// This class represents the ATT cloud platform.
// Based on the Arduino standard library
class ATTDevice
{
	public:
		//create the object
		ATTDevice(String deviceId, String clientId, String clientKey);

		/*connect with the http server (call first)
		-mac: the mac address of the arduino (4 bytes)
		-httpServer: the name of the http server to use, kept in memory until after calling 'Subscribe'
		returns: true when subscribe was succesfulll, otherwise false.*/
		bool Connect(char httpServer[]);

		//create or update the specified asset. (call after connecting)
		//note: after this call, the name will be in lower case, so that it can be used to compare with the topic of incomming messages.
		void AddAsset(char id, String name, String description, bool isActuator, String type);

		/*Stop http processing & make certain that we can receive data from the mqtt server. */
		void Subscribe(MQTT& mqttclient);

		//send a data value to the cloud server for the sensor with the specified id.
		void Send(String value, char id);

		//check for any new mqtt messages.
		void Process();
	private:
		char* _serverName;				//stores the name of the http server that we should use.
		String _deviceId;				//the device id provided by the user.
		String _clientId;				//the client id provided by the user.
		String _clientKey;				//the client key provided by the user.
		TCPClient  _client;			    //raw tcp client. Possible to save some memory here: pass the client as a param in connect, put the object local in the setup function.
		MQTT* _mqttclient;		        //provides mqtt support

		//subscribe to the mqtt topic so we can receive data from the server.
		void MqttSubscribe();

		//tries to create a connection with the mqtt broker. also used to try and reconnect.
		void MqttConnect();

		//read all the data from the ethernet card and display on the debug screen.
		void GetHTTPResult();
};

#endif
