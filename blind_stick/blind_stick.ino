int trigPin = 5;    // Trigger
int echoPin = 4;    // Echo
int buzzerPin = 3;
int limit = 10; // 10cm

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

long getDistance(int trigPin, int echoPin) {
  long duration, cm, inches;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration / 2) / 29.1;   // Divide by 29.1 or multiply by 0.0343
  //inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.013

  delay(250);

  return cm;
}
void loop() {
  long distance = getDistance(trigPin, echoPin);
  Serial.print("\ndistance is : ");
  Serial.print(distance);
  
  if (distance < limit) {
    digitalWrite(buzzerPin,HIGH);
  } else {
    digitalWrite(buzzerPin,LOW);
  }

}
