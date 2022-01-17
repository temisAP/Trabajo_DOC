#include <Arduino.h>
#include <VarSpeedServo.h>
#include <LiquidCrystal.h>
#include <math.h>

// Objects
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // create LCD objet to display
VarSpeedServo myservo;                  // create servo object to control a servo

// Pins
const int servoPin  = 9;     // the digital pin used for the servo
const int ldr0      = A0;
const int ldr1      = A1;
const int ldr2      = A2;
const int ldr3      = A3;
const int ldr4      = A4;
const int ldr5      = A5;

int i = 0;
int angle = 45;
int spd = 15;

void setup() {
  // Servo setup
  myservo.attach(servoPin);      // attaches the servo on servoPin
  myservo.write(angle,spd,false);    // set the intial position of the servo, wait until done
  // Serial setup
  Serial.begin(9600);
  // LCD setup
  lcd.begin(16, 2);   // set up the LCD's number of columns and rorws:
  lcd.print("Angle"); // print a message to the LCD
  // Let 5s to start
  delay(5000);
  Serial.println("*** Start characterization ***");

  
}

void loop() {

  // Print in lcd
  writeInLDC(angle);
  
  // Print angle and readings by serial each 250 miliseconds
  if (i>=5) {get_angle(angle);}
  
  // Move servo each 1000 miliseconds
  if (i==20) {
    if (angle <= 135) {myservo.write(angle,spd,false);}
    if (angle > 135) {Serial.println("*** End characterization ***");}
    angle = angle+5;
    i = 0;
  }
  
  delay(50);
  i = i+1;

}

void get_angle(int angle){

  Serial.println("***** Begin report *****");

  Serial.print("angle = ");
  Serial.print(angle);
  Serial.println();

  Serial.print("ldr0 = ");
  Serial.print(analogRead(ldr0));
  Serial.println();

  Serial.print("ldr1 = ");
  Serial.print(analogRead(ldr1));
  Serial.println();

  Serial.print("ldr2 = ");
  Serial.print(analogRead(ldr2));
  Serial.println();

  Serial.print("ldr3 = ");
  Serial.print(analogRead(ldr3));
  Serial.println();

  Serial.print("ldr4 = ");
  Serial.print(analogRead(ldr4));
  Serial.println();

  Serial.print("ldr5 = ");
  Serial.print(analogRead(ldr5));
  Serial.println();

  Serial.println("***** End report *****");

}

void writeInLDC(int angle){

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Angle");
  lcd.setCursor(0, 1);
  lcd.print(angle);
}
