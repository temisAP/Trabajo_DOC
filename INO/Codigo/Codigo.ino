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
float theta_R = 0;      // Relative angle between sensors and sun
float theta_R_prev = 0; // Previous angle between sensors and sun
float theta_T = 0;      // Target angle
float theta_E = 0;      // Error between R and T
float theta_E_prev = 0; // Previous error
float d_theta_E = 0;    // Derivate of error
float S_theta_E = 0;    // Cumulative error

// PID constants
float Kp = 1;
float Ki = 0;
float Kd = 1;

void setup() {
  // LCD setup
  lcd.begin(16, 2);   // set up the LCD's number of columns and rorws:
  lcd.print("Angle"); // print a message to the LCD
  // Servo setup
  myservo.attach(servoPin);     // attaches the servo on servoPin
  myservo.write(0,12,true);    // set the intial position of the servo, as fast as possible, wait until done
  // Serial
  Serial.begin(9600);
  // Switcher (modes);
  pinMode(switchPin, INPUT);
}

void loop() {
  // delay(1000); // Uncomment this line to be able to read serial

  // Get angle and time
  theta_R = get_angle();
  if (theta_R-theta_R_prev >= 5) {S_theta_E = 0;} // Reset time origin for PID

  // Write angle in LCD
  writeInLDC(theta_R);

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

  // Compare six ldrs to determine where the light is

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
