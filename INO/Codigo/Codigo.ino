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

// Falcon variables
float theta_F;      // Falcon angle
float omega_F;      // Falcon speed rate
// Servo variables
float theta_S;      // Servo angle
float omega_S;      // Servo speed rate
// Time variables
float now;          // Current time
float prev;         // Previous time
// PID angles
float theta_R = 0;      // Relative longitude angle between sensors and sun
float theta_R_prev = 0; // Previous angle between sensors and sun
float theta_V;          // Relative latitude angle between sensors and sunS
float angles[2];   // Array to contain {theta_R,theta_V}
float theta_E = 0;      // Error between R and T
float theta_E_prev = 0; // Previous error
float d_theta_E = 0;    // Derivate of error
float S_theta_E = 0;    // Cumulative error

// PID constants
float theta_T = 0;      // Target angle
float Kp = 1;
float Ki = 0;
float Kd = 1;

void setup() {
  // LCD setup
  lcd.begin(16, 2);   // set up the LCD's number of columns and rorws:
  lcd.print("Angle"); // print a message to the LCD
  // Servo setup
  myservo.attach(servoPin);     // attaches the servo on servoPin
  myservo.write(90,12,true);    // set the intial position of the servo, as fast as possible, wait until done
  // Serial
  Serial.begin(9600);
  // Switcher (modes);
  pinMode(switchPin, INPUT);
}

void loop() {
  // delay(1000); // Uncomment this line to be able to read serial

  // Get angle and time
  get_angle(&angles);
  theta_R = angles[0];
  theta_V = angles[1];
  if (theta_R-theta_R_prev >= 5) {S_theta_E = 0;} // Reset time origin for PID

  // Write angle in LCD
  writeInLDC(theta_R,theta_V);

  // Move servo if switcher is on
  if (digitalRead(switchPin) == HIGH){
    // Time and error
    now = 1000 * millis()
    theta_E = theta_T - theta_R;
    d_theta_E =  (theta_E - theta_E_prev) / (now-prev);
    S_theta_E += (theta_E + theta_E_prev) / 2.0 * (now-prev)
    // Get movement of the falcon
    theta_F = theta_F + theta_E;
    omega_F = kp*theta_E + kd*d_theta_E + ki*S_theta_E;
    // Servo movement
    theta_S = (180.0 - theta_F)/2.0;
    omega_S = 2*omega_F
    if (omega_S >= 20) {omega_S = 20;}   // Para que no salga volando
    // Move servo
    myservo.write(theta_S,omega_S,true); // True overwrites angle
    // Store previous error state
    theta_E_prev = theta_E;
    prev = now;
  }


}

void writeInLDC(float longitude ,float latitude){
  // Function write current angle in the LDC display
  //
  //    input latitude : angle in xy plane
  //    input longitude: angle in verical

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Latitude : ");
  lcd.print(latitude);
  lcd.setCursor(0,1);
  lcd.print("Longitude : ");
  lcd.print(longitude);
  lcd.setCursor(16,1);
  lcd.print(digitalRead(switchPin))
}

void get_angle(float *angles){
  // Function to get current angle between sensor and light source
  //
  //    input angle:  by reference, it will be modificated if passed like get_angle(&angles)
  //

  float alpha;
  float beta;
  float gamma;

  // Current intensities

  float I0 = analogRead(ldr0);
  float I1 = analogRead(ldr1);
  float I2 = analogRead(ldr2);
  float I3 = analogRead(ldr3);
  float I4 = analogRead(ldr4);
  float I5 = analogRead(ldr5);

  float threshold = (I0+I1+I2+I3+I4+I5) * 0.01 // Value to determine number of sensors activated

  // Determine the number of sensors above threshold

  int n = 0;
  if (I0 > threshold) n++;
  if (I1 > threshold) n++;
  if (I2 > threshold) n++;
  if (I3 > threshold) n++;
  if (I4 > threshold) n++;
  if (I5 > threshold) n++;

  // If no sensors are above threshold, return 999,999

  if (n == 0) {
    angles[0] = 999;
    angles[1] = 999;
    return;
  }

  // Determine where the light is

  // Lateral cuadrant
  if (n==3){
    // Down right
    if (I5+I4+I3 > I1+I0+I2) {
      alpha = 0.00 + fotocouple(ldr5,ldr4, 90);
      beta  = -1.0 * fotocouple(ldr4,ldr3, 90);
      gamma = 0.00 + fotocouple(ldr5,ldr3, 90);
    }
    // Up left
    else if (I5+I4+I3 > I1+I0+I2) {
      alpha = 90.0 + fotocouple(ldr5,ldr4, 90);
      beta  = +1.0 * fotocouple(ldr4,ldr3, 90);
      gamma = 90.0 + fotocouple(ldr5,ldr3, 90);
    }
  }
  // Frontal light
  else if ( n == 2 && I1 > threshold &&  I4 > threshold) {
      alpha = 90.0;
      if (I2>I3)      {beta= 1.0 * fotocouple(ldr1,ldr2,90);}
      else if (I2>I3) {beta=-1.0 * fotocouple(ldr4,ldr3,90);}
      gamma = 0.0;
  }
  // Left lateral light
  else if (n==1 && I5 > threshold){
      alpha = 0.0;
      beta  = 0.0;
      gamma = 0.0;
  }
  // Right lateral light
  else if (n==1 && I0 > threshold){
      alpha = 180.0;
      beta  = 0.0;
      gamma = 0.0;
  }
  // Upper light
  else if (n==1 && I2 > threshold){
      alpha = 90.0;
      beta  = 90.0;
      gamma = 90.0;
  }
  // Upper light
  else if (n==1 && I3 > threshold){
      alpha = 90.0;
      beta  = -90.0;
      gamma = -90.0;
  }


  longitude = alpha;
  latidude  = beta;

  angle[0] = latitude;
  angle[1] = longitude;


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

  // if (pin1==0 || pin1 == 2){}

  float b = 1.7875;
  float c = 11.77375;
  float d = 1.57625;

  // Get input

  float I1 = analogRead(pin1);
  float I2 = analogRead(pin2);

  // Determine coeficients

  float I = I1/(I1+I2);

  float A = I-1+I*cos(b*theta);
  float B = -I*sin(b*theta);
  float C = (1-2*I)*d;

  // Solve equation

  if (A+C != 0.0 && -B*sqrt(pow(A,2.0)+pow(B,2.0)-pow(C,2.0))+pow(A,2.0)+A*C+pow(B,2.0) != 0.0) {

     alpha = 2.0*atan((B-sqrt(pow(A,2.0)+pow(B,2.0)-pow(C,2.0)))/(A+C));

  }
  else if( A+C != 0.0 &&  B*sqrt(pow(A,2.0)+pow(B,2.0)-pow(C,2.0))+pow(A,2.0)+A*C+pow(B,2.0) != 0.0 ){

     alpha = 2.0*atan((B+sqrt(pow(A,2.0)+pow(B,2.0)-pow(C,2.0)))/(A+C));

  }
  else if( B != 0.0  && pow(A,2.0)+pow(B,2.0)!=0.0 && C == -A){

    alpha = -2.0*atan(A/B);

  }
  else if( A == -C){
    alpha = 3.1416;
  }

  alpha = (alpha - c*3.1416/180.0)/b;

  alpha = alpha*180.0/3.1416;

  return alpha;

}
