#define PIN_VRx A0
#define PIN_VRy A1
#define PIN_SW 2
#define PIN_RELAY 12
#define PIN_FC1 3
#include <Stepper.h>

const int stepsPerRevolution = 200; 
// change this to fit the number of steps per revolution

// initialize the stepper library on pins 8 through 11:
Stepper myStepperX(stepsPerRevolution, 4, 5, 6, 7);
Stepper myStepperY(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;  
// number of steps the motor has taken

void setup() {

    Serial.begin(9600);

   

    int motorSpeed = 10;
    
    myStepperX.setSpeed(motorSpeed);
    myStepperY.setSpeed(motorSpeed);

    pinMode( PIN_SW, INPUT_PULLUP );
    pinMode( PIN_RELAY, OUTPUT );
    pinMode( PIN_FC1, INPUT );

}

void loop() {

    int stepsX = map(analogRead(PIN_VRx), 0, 1023, -5, 5 );
    int stepsY = map(analogRead(PIN_VRy), 0, 1023, -5, 5 );
    int button = digitalRead(PIN_SW);
    int fc_now = digitalRead(PIN_FC1);
    int fc_prev = 0;
    if (stepsX == -1 || stepsX == +1) {
        stepsX = 0;
    }
    if (stepsY == -1 || stepsY == +1) {
        stepsY = 0;
    }
    
    myStepperX.step(stepsX);
    myStepperY.step(stepsY);
    
     Serial.print( "X_ang:" );
     Serial.print(stepsX );
     Serial.print("  ");
     Serial.print( "Y_ang:" );
     Serial.print(stepsY);
     Serial.print( " SW:");
     Serial.print( button );
     Serial.println();
      
    //Turn on second machine
     
     digitalWrite(PIN_RELAY, button);
     int relay; 
     if (button == 1 && fc_now == 0){
        relay = 0;
     } else {
        relay = 1;
     }
     if (relay == 0 && fc_prev == 0 && fc_now == 1){
        relay = 1;
     }
     fc_prev = fc_now;

     
  
     /*if (stepsX == 0 && stepsX == -1 ){
      return;
     }
     else (){
      return;
     }
     
     else (stepY == 0){
      return;
     }
     
     else (stepY == -1){
      return;
     }
     }
     */
     delay(50);

  }
