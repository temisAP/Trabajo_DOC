#include <Arduino.h>
#include <LiquidCrystal.h>
#include <VarSpeedServo.h>
#include <math.h>

// Objects
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // create LCD objet to display
VarSpeedServo myservo;                  // create servo object to control a servo

// Pins
const int switchPin = 0;     // analog pin used to change between modes
const int servoPin  = 9;     // the digital pin used for the servo
const int ldr0      = A0;
const int ldr1      = A1;
const int ldr2      = A2;
const int ldr3      = A3;
const int ldr4      = A4;
const int ldr5      = A5;

// Constants
float theta_R;      // Relative angle between sensors and sun
float theta_T = 0;  // Target angle
float theta_E;      // Error between

float theta_S;      // Servo angle
float omega_S;      // Servo speed rate


// PID
float Kp = 1;
float Ki = 1;
float Kd = 1;


void setup() {
  // LCD setup
  lcd.begin(16, 2);   // set up the LCD's number of columns and rorws:
  lcd.print("Angle"); // print a message to the LCD
  // Servo setup
  myservo.attach(servoPin);     // attaches the servo on servoPin
  myservo.write(0,255,true);    // set the intial position of the servo, as fast as possible, wait until done
  // Serial
  Serial.begin(9600);
  // Switcher (modes);
  pinMode(switchPin, INPUT);
}

void loop() {
  // delay(500); // Uncomment this line to be able to read serial
  // Get angle
  theta_R = get_angle();
  theta_E = theta_T - theta_R;
  // Write angle in LCD
  writeInLDC(theta_R);

  // Move servo if switcher is on
  if (digitalRead(inPin) == HIGH){
    // Get angle to move from PID
    theta_S = Kp*theta_E;
    omega_S = Kd*theta_E;
    // Move servo
    myservo.write(theta_S,omega_S,false);
  }


}

void writeInLDC(float angle){
  // Function write current angle in the LDC display
  //
  //    input angle: angle to be displayed
  //

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Angle");
  lcd.setCursor(0, 1);
  lcd.print(angle);
}

float get_angle(){
  // Function to get current angle between sensor and light source
  //
  //    return alpha:  angle between sensor and light source
  //


  // Should compare readings between six ldrs

  float theta = 90;
  float alpha = fotocouple(ldr0,ldr1,theta);
  return alpha;

}

float fotocouple (int pin1, int pin2, int theta){

  // Function to compute angle out of two LDRs/Phototransistors
  //
  //    input pin1:   pin where sensor no1 is attached
  //    input pin2:   pin where sensor no2 is attached
  //    input theta:  current angle between sensors [deg]
  //
  //    return alpha:  angle
  //

  float alpha;
  theta = theta*3.1416/180;

  // MODEL PARAMETERS

  float b = 1.7875;
  float c = 11.77375;
  float d = 1.57625;

  // Get input

  float I1 = analogRead(pin1);
  Serial.print("I1 = ");
  Serial.print(I1);
  Serial.println();
  float I2 = analogRead(pin2);
  Serial.print("I2 = ");
  Serial.print(I2);
  Serial.println();

  // Determine coeficients

  float I = I1/(I1+I2);

  float A = I-1+I*cos(b*theta);
  float B = -I*sin(b*theta);
  float C = (1-2*I)*d;

  // Solve equation

  if (A+C != 0 && -B*sqrt(pow(A,2.0)+pow(B,2.0)-pow(C,2.0))+pow(A,2.0)+A*C+pow(B,2.0) != 0) {

     alpha = 2*atan((B-sqrt(pow(A,2.0)+pow(B,2.0)-pow(C,2.0)))/(A+C));

  }
  else if( A+C != 0 &&  B*sqrt(pow(A,2.0)+pow(B,2.0)-pow(C,2.0))+pow(A,2.0)+A*C+pow(B,2.0) != 0 ){

     alpha = 2*atan((B+sqrt(pow(A,2.0)+pow(B,2.0)-pow(C,2.0)))/(A+C));

  }
  else if( B != 0  && pow(A,2.0)+pow(B,2.0)!=0 && C == -A){

    alpha = -2*atan(A/B);

  }
  else if( A == -C){
    alpha = 3.1416;
  }

  alpha = (alpha - c*3.1416/180)/b;

  alpha = alpha*180/3.1416;

  return alpha;

}
