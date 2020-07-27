#define IS_ATTINY
// comment above if you are using Nano

#define DEBUG
// comment above if you dont want print on serial monitor

#ifdef IS_ATTINY // for attiny
  byte trigPin = 1; //  pin P1
  byte echoPin = 3; // Pin P3
  byte pump = 0;  // Pin P0
#endif

#ifndef IS_ATTINY // for nano
  byte trigPin = 5;
  byte echoPin = 7;
  byte pump = 2;
#endif


byte limit = 5; // change it if needed
int del = 3000; // how long pump should ON 
long duration, cm, inches;


void setup() {
  #ifdef DEBUG
  Serial.begin (9600);
  #endif
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pump,OUTPUT);
  digitalWrite(pump,HIGH);

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

    digitalWrite(pump,LOW); // tip32 is pnp so complient value should be used
    delay(del);
    digitalWrite(pump,HIGH);
  }
  Serial.print("\n");

}
