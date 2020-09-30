bool DEBUG = false;
char BTdata;
int LEDs[4] ={3,4,5,6}; // pin 3 4 5 6 are LED1 LED2 .... 

void setup(){
    Serial.begin(9600);
    for(int i=0;i<4; i++) pinMode(LEDs[i],OUTPUT); // make all pins output
}


void loop(){
    if(Serial.available()){
     // if bluetooth provides data 
        BTdata=Serial.read();

        switch (BTdata){
            
            case 'F':
                digitalWrite(LEDs[0],HIGH);
                break;
            case 'B':
                digitalWrite(LEDs[1],HIGH);
                break;
            case 'L':
                digitalWrite(LEDs[2],HIGH);
                break;
            case 'R':
                digitalWrite(LEDs[3],HIGH);
                break;
            default:
                // if bluetooth gets data but unexpected one turn all LEDS for indication
                digitalWrite(LEDs[0],HIGH);
                digitalWrite(LEDs[1],HIGH);
                digitalWrite(LEDs[2],HIGH);
                digitalWrite(LEDs[3],HIGH);
                break;
        }
        delay(1000);

    }else {
        // if bluetooth wont get any data turn off all
        digitalWrite(LEDs[0],LOW);
        digitalWrite(LEDs[1],LOW);
        digitalWrite(LEDs[2],LOW);
        digitalWrite(LEDs[3],LOW);
    }

}
