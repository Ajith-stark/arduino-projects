#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;
int redLED = D0;
int blueLED = D3;
int greenLED = D7;
int relayPin = D8;

char* ssid = "YOUR_SSID";
char* password = "YOUR_PASSWORD";
char* page ="<!DOCTYPE html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>Home automation | TechParts</title></head><style>a{display: block;text-decoration: none;font-size: 18px;color : white;padding:10px 8px;border:1px solid gray;border-radius:4px;background-color:red;margin: 0 auto;margin-bottom:6px;width: 200px;}</style><body style=\"text-align:center;padding:0px;margin:0px ;height:90vh;\"><h2>Home automation</h2><div style=\"text-align:center;place-items: center; \"><a href=\"/red\" style=\"background-color: red;\" >RED LED</a><a href=\"/blue\" style=\"background-color: darkblue;\" >BLUE LED</a><a href=\"/green\" style=\"background-color: green;\" >GREEN LED</a><a href=\"/bulb\" style=\"background-color: orchid;\" >BULB</a></div></body></html>" ;

void setup(){
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(relayPin, OUTPUT);
  
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/",[](){server.send(200,"text/plain",page);});
  server.on("/red",toggleRedLED);  
  server.on("/blue",toggleBlueLED);
  server.on("/green",toggleGreenLED);
  server.on("/blub",toggleBulb);
  server.begin();
}

void loop()
{
  server.handleClient();
}


void toggleRedLED(){
  digitalWrite(redLED,!digitalRead(redLED));
  server.send(200,"text/plain",page);
}

void toggleBlueLED(){
  digitalWrite(blueLED,!digitalRead(blueLED));
  server.send(200,"text/plain",page);
}

void toggleGreenLED(){
  digitalWrite(greenLED,!digitalRead(greenLED));
  server.send(200,"text/plain",page);
}

void toggleBulb(){
  digitalWrite(relayPin,!digitalRead(relayPin));
  server.send(200,"text/plain",page);
}
