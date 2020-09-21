int moisture_pin= A0; // declaring moisture sensor pin A0 
int moisture; //store the moisture value.
const int limit = 20;
const int Delay = 3000;
int relayPin = 6;

void setup() {
  Serial.begin(9600); // serial transmission at 9600 baud rate
  pinMode(moisture_pin,INPUT);
  pinMode(relayPin,INPUT);
  digitalWrite(relayPin,HIGH);
}

void loop() {
  
  moisture= analogRead(moisture_pin); // analog read of sensor
  moisture=map(moisture,0,1024,100,0); // map readings into percentages
  Serial.println(moisture);
  if (moisture < limit) {
      digitalWrite(relayPin,LOW);
      delay(Delay);
      
    }else {
       digitalWrite(relayPin,HIGH);
    }
}
