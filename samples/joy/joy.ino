#define PIN_VRx A0
#define PIN_VRy A1
#define PIN_SW 2

int x, y;
int x_ang, y_ang;

void setup() {
 
  Serial.begin(9600);
  
  pinMode( PIN_SW, INPUT_PULLUP );

}
void loop() {
  
  x = analogRead(PIN_VRx);
  y = analogRead(PIN_VRy);
  x_ang = map( x, 0, 1023, 0, 180 );
  y_ang = map( y, 0, 1023, 0, 180 );

  Serial.print( "X_ang:" );
  Serial.print(x_ang);
  Serial.print("  ");

  Serial.print( "Y_ang:" );
  Serial.print(y_ang);
  Serial.print( " SW:");
  Serial.print( digitalRead(PIN_SW) );
  Serial.println();
  delay(50);
  }
