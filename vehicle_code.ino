#include <SPI.h>
#include "RF24.h"

bool radioNumber = 1;

RF24 radio(7,8);

byte addresses[][6] = {"1Node","2Node"};

int motor_left[] = {9, 10};
int motor_right[] = {5, 6};

void setup() {
  Serial.begin(115200);
  
  radio.begin();

  // Set the PA Level low to prevent power supply related issues since this is (was) a
 // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);
  
  // Open a writing and reading pipe on each radio, with opposite addresses
  if (radioNumber) {
    radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1,addresses[0]);
  } else {
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1,addresses[1]);
  }
  
  // Start the radio listening for data
  radio.startListening();
} // end of setup

void loop() {
    unsigned long got_time;
    
    int num;
    
    if (radio.available()){                                                                    
      while (radio.available()) { // While there is data ready
        radio.read( &num, sizeof(num) ); // Get the payload
      }   
      Serial.print(F("Received "));
      Serial.println(num);  
   }

   if (num == 1) {
    motor_stop();
    } else if (num == 2) {
      drive_forward(255);
      
      } else if (num == 3) {
        turn_right(255);
        
        } else if (num == 4) {
          turn_left(255);
          
          } else if (num == 5) {
            drive_backward(255);
            
            } else {
              motor_stop();
              }


} // end of loop


//------------- MOTOR FUNCTIONS --------------

void motor_stop(){
  analogWrite(motor_left[0], LOW); 
  analogWrite(motor_left[1], LOW); 

  analogWrite(motor_right[0], LOW); 
  analogWrite(motor_right[1], LOW);
  delay(25);
}

void drive_forward(int speed){
  analogWrite(motor_left[0], speed); 
  analogWrite(motor_left[1], LOW); 

   analogWrite(motor_right[0], speed); 
  analogWrite(motor_right[1], LOW); 
}

void drive_backward(int speed){
  analogWrite(motor_left[0], LOW); 
  analogWrite(motor_left[1], speed); 

  analogWrite(motor_right[0], LOW); 
  analogWrite(motor_right[1], speed); 
}

void turn_left(int speed){
  analogWrite(motor_left[0], LOW); 
  analogWrite(motor_left[1], speed); 

  analogWrite(motor_right[0], speed); 
  analogWrite(motor_right[1], LOW);
}

void turn_right(int speed){
  analogWrite(motor_left[0], speed); 
  analogWrite(motor_left[1], LOW); 

  analogWrite(motor_right[0], LOW); 
  analogWrite(motor_right[1], speed); 
}

//--------------- END OF MOTOR FUNCTIONS ---------------
