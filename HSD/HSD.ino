#define IS_ATTINY 
// comment above if you are using Nano 

#define DEBUG 
// comment above if you dont want print on serial monitor

#ifdef IS_ATTINY // for attiny
  byte trigPin = 2; 
  byte echoPin = 3;
  byte pump = 1;
#endif

#ifndef IS_ATTINY // for nano
  byte trigPin = 5;
  byte echoPin = 7;
  byte pump = 2;
#endif


byte limit = 5; // change it if needed
long duration, cm, inches;


void setup() {
  #ifdef DEBUG
  Serial.begin (9600);
  #endif 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pump,OUTPUT);
  
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration / 2) / 29.1;  

  #ifdef DEBUG
    Serial.print(cm);
    Serial.print("cm\t");
  #endif
  
  delay(250);
  
  if (cm <= limit) {
    #ifdef DEBUG
      Serial.print("Hand detected !");
    #endif
    
    digitalWrite(pump,LOW);
  }
  Serial.print("\n");

}
