//char BTdata;
#include <SoftwareSerial.h> 
SoftwareSerial Bluetooth(2, 3);  // RX, TX   (arduino's pin 2 is RX & pin 3 is TX)

// IF THIS CODE WORKS change above (2,3) to (2,13) because adafruit shield uses pin 3 but not pin 2 

int LEDs[4] ={3,4,5,6};

void setup(){
    Serial.begin(9600); // for serial monitor
    Bluetooth.begin(9600); // for bluetooth
    pinMode(LEDs[0],OUTPUT); 
	pinMode(LEDs[1],OUTPUT);
	pinMode(LEDs[2],OUTPUT);  
	pinMode(LEDs[3],OUTPUT); 
}


void loop(){
    if(Bluetooth.available()>0){

        char data=Bluetooth.read();

        Serial.print(data);
        Serial.print("\n");

        switch (data){
            
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
    }else {
        digitalWrite(LEDs[0],LOW);
        digitalWrite(LEDs[1],LOW);
        digitalWrite(LEDs[2],LOW);
        digitalWrite(LEDs[3],LOW);
    }

}
