#include <Arduino.h>
#include <LiquidCrystal.h>
#include <VarSpeedServo.h>
#include <math.h>

// Objects
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // create LCD objet to display
VarSpeedServo myservo;                  // create servo object to control a servo

// Pins
const int switchPin = A8;     // analog pin used to change between modes
const int servoPin  = 9;     // the digital pin used for the servo
const int ldr0      = A0;
const int ldr1      = A1;
const int ldr2      = A2;
const int ldr3      = A3;
const int ldr4      = A4;
const int ldr5      = A5;

// Falcon variables
float theta_F = 0;      // Falcon angle
float omega_F = 0;      // Falcon speed rate
// Servo variables
float theta_S = 90;      // Servo angle
float omega_S = 12;      // Servo speed rate
// Time variables
float now = 0;          // Current time
float prev = 0;         // Previous time
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
float kp = 0.5;
float kd = 1;
float ki = 1;


void setup() {
  // LCD setup
  lcd.begin(16, 2);   // set up the LCD's number of columns and rorws:
  lcd.print("Hello"); // print a message to the LCD
  // Servo setup
  myservo.attach(servoPin);     // attaches the servo on servoPin
  myservo.write(theta_S,omega_S,true);    // set the intial position of the servo, as fast as possible, wait until done
  // Serial
  Serial.begin(9600);
  //while (!Serial);
  //Serial.println("ldr0,ldr1,ldr2,ldr3,ldr4,ldr5");
  // Switcher (modes);
  pinMode(switchPin, INPUT);
}

void loop() {
   delay(1000); // Uncomment this line to be able to read serial

  // Get angle and time
  get_angle(angles);
  theta_R = angles[0];
  theta_V = angles[1];
  if (abs(theta_R-theta_R_prev) >= 70.0) {S_theta_E = 0.0;} // Reset time origin for PID

  // Write angle in LCD
  writeInLDC(theta_R,theta_V);

  // Move servo if switcher is on
  if (analogRead(switchPin) > 900.0){
    // Time and error
    now = 1000.0 * millis();
    theta_E = theta_T - theta_R;
    d_theta_E =  (theta_E - theta_E_prev) / (now-prev);
    S_theta_E += (theta_E + theta_E_prev) / 2.0 * (now-prev);
    // Get movement of the falcon
    theta_F = theta_F + theta_E;
    if (theta_F > 180.0) {theta_F = 180.0;}  // Para que deje de acumular error
    if (theta_F < -180.0) {theta_F = -180.0;}      // Para que deje de acumular error
    omega_F = kp*theta_E + kd*d_theta_E + ki*S_theta_E;
    // Servo movement
    theta_S = (180.0 - theta_F)/2.0;
    omega_S = 0.5*omega_F;
    // Survival
    if (omega_S >= 30.0) {omega_S = 30.0;}   // Para que no salga volando
    // Move servo
    myservo.write(theta_S,omega_S,false); // True overwrites angle
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
  lcd.print("Lon: ");
  lcd.print(longitude);
  lcd.setCursor(0,1);
  lcd.print("Lat: ");
  lcd.print(latitude);

}

void get_angle(float angle[]){
  // Function to get current angle between sensor and light source
  //
  //    input angle:  by reference, it will be modificated if passed like get_angle(&angles)
  //

  float alpha;
  float beta;
  float gamma;

  // Current intensities

  float I1 = analogRead(ldr0);
  float I2 = analogRead(ldr1);
  float I3 = analogRead(ldr2);
  float I4 = analogRead(ldr3);
  float I5 = analogRead(ldr4);
  float I6 = analogRead(ldr5);

  // To be commented

  //Serial.print(analogRead(ldr0));
  //Serial.print(",");
  //Serial.print(analogRead(ldr1));
  //Serial.print(",");
  //Serial.print(analogRead(ldr2));
  //Serial.print(",");
  //Serial.print(analogRead(ldr3));
  //Serial.print(",");
  //Serial.print(analogRead(ldr4));
  //Serial.print(",");
  //Serial.print(analogRead(ldr5));
  //Serial.println();

  float list[6] = {I1,I2,I3,I4,I5,I6};
  float max_val = get_max(list);

  float thld_0    = 15.0*max_val/500.0;
  float thld_90   = 15.0*max_val/500.0;
  float thld_180  = 15.0*max_val/500.0;
  float div0V = 1.2;  // Para 0 grados vertical

  // *** Plano horizontal ***

  // Frontal (0 grados)
  if ( (I1+1.0e-6)/(I6+1.0e-6) < 1.3 && (I6+1.0e-6)/(I1+1.0e-6) < 1.1 ){
    alpha = 0.0;
  }
  // Lateral (entre 0 y +90 grados)
  else if (I1>I6){
    alpha = +1.0 * fotocouple(ldr1,ldr0,90.0);
  }
  // Lateral (entre 0 y -90 grados)
  else if (I6>I1){
    alpha = -1.0 * fotocouple(ldr4,ldr5,90.0);
  }
  // Detrás (180 grados)
  else if (I1<thld_180 && I2<thld_180 && (I5<thld_180 && I6<thld_180)){
    alpha = 180.0; // Por si acaso
  }
  // Eclipse
  else if (I1<thld_180 && I2<thld_180 && I5<thld_180 && I6<thld_180){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Eclipse!");  
  }
  else {
    alpha = 0.0;
  }

  // *** Plano vertical ***
  //
  if ( (I3+1.0e-6)/(I4+1.0e-6) < div0V && (I4+1.0e-6)/(I3+1.0e-6) < div0V){
    beta = 0.0;
  }
  else if (I3>I4){
    if (I1>I2){beta = +1.0 * fotocouple(ldr0,ldr2,90.0);}
    else      {beta = +1.0 * fotocouple(ldr1,ldr2,90.0);}
  }
  else if (I4>I3){
    if (I6>I5){beta = -1.0 * fotocouple(ldr5,ldr3,90.0);}
    else      {beta = -1.0 * fotocouple(ldr4,ldr3,90.0);}
  }
  else {
    beta = 999;
  }

  // Avoid nan
  if (isnan(alpha)){
  alpha = 0.0;
  }
  if (isnan(beta)){
  beta = 0.0;
  }

  float longitude = alpha;
  float latitude  = beta;

  angle[0] = alpha; // alpha
  angle[1] = beta;  // beta

}

float fotocouple (int pin1, int pin2, float theta){

  // Function to compute angle out of two LDRs/Phototransistors
  //
  //    input pin1:   pin where sensor no1 is attached
  //    input pin2:   pin where sensor no2 is attached
  //    input theta:  current angle between sensors [deg]
  //
  //    return alpha:  angle
  //


  float alpha;
  theta = theta*3.1416/180.0; // deg2rad

  // MODEL PARAMETERS

  float b;
  float c;
  float d;

  // Front-right
  if (pin1 == ldr0 && pin2 == ldr1 || pin1 == ldr1 && pin2 == ldr0){
    b = 2; //2.371250;
    c = 2.827525;
    d = 0.889800;
  }
  // Frontal-left
  else if (pin1 == ldr4 && pin2 == ldr5 || pin1 == ldr5 && pin2 == ldr4) {
    b = 2; // 2.316000;
    c = -5.0; //-21.4075;
    d = 0.861975;
  }
  else {
    b = 1.7875;
    c = 11.77375;
    d = 1.57625;
  }

  d = 1;

  // Get input

  float I1 = analogRead(pin1);
  float I2 = analogRead(pin2);

  // Determine coeficients

  float I = I1/(I1+I2);

  float A = I-1.0+I*cos(b*theta);
  float B = -1.0 * I*sin(b*theta);
  float C = (1.0-2.0*I)*d;
  

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

float get_max(float a[6])
{
    float max = a[0];
    for (int i = 1; i < 6; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
