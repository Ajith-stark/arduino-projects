int base =3;
int collector = 4;
int emitter =5;

void setup(){
  pinMode(base,INPUT);
  pinMode(collector,OUTPUT);
  pinMode(emitter,OUTPUT);
  Serial.begin (9600);
}

void loop(){


// ------------- test 1 -----------------------
  digitalWrite(base,LOW); // making closed circuit
  digitalWrite(collector,HIGH);
  delay(100);
  if (digitalRead(emitter)== HIGH){ // open ?
    Serial.print("Haaaay test1 Detected !\n");
  }else{
    Serial.print("Oops.. test1 not detected !\n");
  }
  delay(300);



  // ------------- test 2 -----------------------
  digitalWrite(base,HIGH); // making open circuit
  digitalWrite(collector,HIGH);
  delay(100);
  if (digitalRead(emitter) == LOW){ // close ?
    Serial.print("Haaaay test2 Detected + !\n");
  }else{
    Serial.print("Oops.. test2 not detected !\n");
  }
  delay(300);





}
