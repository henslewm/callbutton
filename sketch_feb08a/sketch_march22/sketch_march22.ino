#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <strings.h>

////////////////// Define Variables //////////
// Configure the device's network info
String ID("T3A11/A12");

//Configure the WiFi router authentication parameters
//const char ssid[] = "PemCafe1";
//const char pw[] = "3au5j75^s7lk";
const char ssid[] = "simple";
const char pw[] = "spacecase";
const uint16_t port = 6341;
const char* host = "192.168.43.37";  //"CO-OPS-L-191268"; // ip or hostname
float vccVolt;

//Setup the LED pin number and ON/OFF Buttons
//GPIO2 - D4 - BUILT_IN_LED2 = 2;
const short int RST_DISABLE = 3;
const short int CALL_BUTTON = 4; //GPIO4 - D2 ; GPIO0 - D3
String ON = ID + ",ON";
String OFF = ID + ",OFF";
bool LED_ON = false;
ADC_MODE(ADC_VCC);
////////////////////////////////////////////
//FOR THIS IMPLEMENTATION, USING D0 AS A RESET AND 
// Use WiFiClient class to create TCP connections
WiFiClient client;

//////////////////// Pre-Running Setup and Configuration of PINS //////////////////
void setup()
{

  //RST Enable IO as an OUTPUT and disable reset(LOW)
  pinMode(RST_DISABLE, OUTPUT);
  digitalWrite(RST_DISABLE, LOW);
  
  // Digital pin for LED as an OUTPUT, turn the LED ON (LOW is the voltage level)
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  //Call buttons Digital Pin as INPUT
  pinMode(CALL_BUTTON, INPUT);
  
  // Setup the Serial output for debugging
  Serial.begin(115200);
  Serial.println();
  
  //Connect to network
  WiFiON();
  
  //Connect to Host Server Application-Send "ID,ON"
  Serial.print("connecting to server: ");
  Serial.println(host);

  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    Serial.println("wait 5 sec...");
    delay(5000);

    //Attempt to reconnect to host router
    WiFi.disconnect();
    delay(1000);
    WiFi.begin(ssid, pw);
    return;
  }

  client.println(ON);
  delay(2000);

  //Turn Wifi OFF
  WiFiOFF();
  delay(100);

  //Turn the LED back on.
  digitalWrite(LED_BUILTIN, LOW);
}
///////////////////////////////////////////////////////////////////////////////////////

void loop() {
  
  //Turn the LED ON.
  digitalWrite(LED_BUILTIN, LOW);

  //Get battery voltage
  vccVolt = ((float)ESP.getVcc())/1024;
  Serial.printf("Vcc: %f \n",vccVolt);
  
  //SOMEONE PUSHED THE BUTTON
  if(digitalRead(CALL_BUTTON)==LOW){
      //For Debug
      Serial.println("CALL_BUTTON PRESSED");  
      
      //Turn OFF LED
      digitalWrite(LED_BUILTIN, HIGH);

      //Connect to network
      WiFiON();
      
      //Connect to Server
      if (!client.connect(host, port)) {
        Serial.println("connection failed");
        Serial.println("wait 5 sec...");
        delay(5000);
    
        //Attempt to reconnect to host router
        WiFi.disconnect();
        delay(1000);
        WiFi.begin(ssid, pw);
        return;
      }

    //Send ID,OFF message to server
    client.println(ID+",OFF");
    delay(3000);
    
    //Enable Reset from Deep Sleep
    digitalWrite(RST_DISABLE, HIGH);
    
    //Go to Deep Sleep
    ESP.deepSleep(0);
    
    } //endif for SOMEONE PUSHED THE BUTTON
}

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

void WiFiON(){
  //Attempt to connect to host router
  WiFi.begin(ssid, pw);
  WiFi.mode(WIFI_STA);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    //ESP.restart();
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  delay(100);

}
void WiFiOFF() {

    //Disconnect the client & Wifi
    Serial.println("Diconnecting WiFi...");
    WiFi.disconnect();
    WiFi.mode(WIFI_OFF);

    //Check if it's disconnected.
    CheckWiFiStatus();
}