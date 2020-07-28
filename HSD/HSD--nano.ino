
byte trigPin = 5;
byte echoPin = 7;
byte pump = 2;


byte limit = 5; // change it if needed
int del = 3000; // how long pump should ON
long duration, cm, inches;


void setup() {
  Serial.begin (9600);
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

    Serial.print(cm);
    Serial.print("cm\t");

  delay(250);

  if (cm <= limit) {
      Serial.print("Hand detected !");

    digitalWrite(pump,LOW); // tip32 is pnp so complient value should be used
    delay(del);
    digitalWrite(pump,HIGH);
  }
  Serial.print("\n");

}
