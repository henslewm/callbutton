#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <strings.h>

////////////////// Define Variables //////////
// Configure the device's network info
String ID("T3I5");

//Configure the WiFi router authentication parameters
const char ssid[] = "PemCafe1";
const char pw[] = "3au5j75^s7lk";

const uint16_t port = 6341;
const char* host = "192.168.1.213";  //ip only
float vccVolt;

//Setup the LED pin number and ON/OFF Buttons
//const short int GPIO2 - D4 - BUILT_IN_LED2 = 2; 
//USE LED_BUILTIN instead FOR WEMOS D1 MINI
//const short int RST_DISABLE = 4;  // GPIO4 - D2
const short int BUILT_IN_LED = 2;   //USE LED_BUILTIN instead
const short int CALL_BUTTON = 4;    //GPIO16 - D0 Dude... ; GPIO0 - D3
String ON = ID + ",ON";
String OFF = ID + ",OFF";
bool LED_ON = false;
ADC_MODE(ADC_VCC);
bool WAITINGONSERVER = false;

////////////////////////////////////////////
//FOR THIS IMPLEMENTATION, USING D0 AS A RESET AND
// Use WiFiClient class to create TCP connections
WiFiClient client;

//////////////////// Pre-Running Setup and Configuration of PINS //////////////////
void setup()
{

  WiFi.mode(WIFI_STA);

  //RST Enable IO as an OUTPUT and disable reset(LOW)
  //pinMode(RST_DISABLE, OUTPUT);
  //digitalWrite(RST_DISABLE, LOW);

  // Digital pin for LED as an OUTPUT, turn the LED ON (LOW is the voltage level)
  pinMode(BUILT_IN_LED, OUTPUT);
  digitalWrite(BUILT_IN_LED, HIGH);

  //Call buttons Digital Pin as INPUT
  pinMode(CALL_BUTTON, INPUT_PULLUP);

  //Setup the Serial output for debugging
  Serial.begin(115200);
  Serial.println();
}
///////////////////////////////////////////////////////////////////////////////////////

void loop() {
  delay(0);
  yield();
  //SOMEONE PUSHED THE BUTTON
  if(digitalRead(CALL_BUTTON)==LOW){
      //For Debug
      Serial.println("CALL_BUTTON PRESSED");
      
      //CALL THE SERVER
      if(!WAITINGONSERVER){
        
          WAITINGONSERVER=true;
          
          //Turn on the LED
          digitalWrite(BUILT_IN_LED, LOW);
          
          //Get battery voltage
          vccVolt = ((float)ESP.getVcc()) / 1024;
          Serial.printf("Vcc: %f \n",vccVolt);
          
          //Connect to network
          WiFiON();

          //Connect to Host Server Application-Send "ID,ON"
          Serial.print("connecting to server: ");
          Serial.println(host);
        
          if (!client.connect(host, port)) {
            Serial.println("connection failed");
            Serial.println("wait 3 sec...");
            delay(3000);
        
            //Attempt to reconnect to host router
            //WiFi.disconnect();
            WiFi.begin(ssid, pw);
            return;
          }else {
            
          //Send ON to server
          Serial.print("Sending ");
          Serial.print(ON);
          Serial.println(" to Server");
        
          for(int i = 0; i<20; i++){
            client.println(ON); 
          }
          
            //Turn Wifi OFF
            delay(1000);
            WiFiOFF();
          }
      } else {
    
    //Turn OFF LED
    digitalWrite(BUILT_IN_LED, HIGH);

    //No longer waiting on server, set False
    WAITINGONSERVER=false;
    
    //Connect to network
    WiFiON();

    //Connect to Server
    if (!client.connect(host, port)) {
      Serial.println("connection failed");
      Serial.println("wait 3 sec...");
      delay(3000);

      //Attempt to reconnect to host router
      WiFi.disconnect();
      WiFi.begin(ssid, pw);
      return;
    }

    //Send ID,OFF message to server
    Serial.print("Sending ");
    Serial.print(OFF);
    Serial.println(" to Server");
    for(int i=0;i<20;i++){
       client.println(OFF);         
    }

      delay(1000);
      
    //Turn WiFi Off
    WiFiOFF();
    } 
  }//endif for SOMEONE PUSHED THE BUTTON
}//end loop
void CheckWiFiStatus()
{
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi Connected");
    // don't continue:
  }
  if (WiFi.status() == WL_IDLE_STATUS) {
    Serial.println("WiFi WL_IDLE_STATUS");
    // don't continue:
  }
  if (WiFi.status() == WL_CONNECT_FAILED) {
    Serial.println("WL_CONNECT_FAILED");
    // don't continue:
  }
  if (WiFi.status() == WL_CONNECTION_LOST) {
    Serial.println("WL_CONNECTION_LOST");
    // don't continue:
  }
  if (WiFi.status() == WL_DISCONNECTED) {
    Serial.println("WL_DISCONNECTED");
    // don't continue:
  }
}

void WiFiON() {
  //Attempt to connect to host router
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pw);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

}
void WiFiOFF() {

  //Disconnect the client & Wifi
  Serial.println("Diconnecting WiFi...");
  WiFi.disconnect();
  WiFi.mode(WIFI_OFF);
  
  //Check if it's disconnected.
  CheckWiFiStatus();
}
