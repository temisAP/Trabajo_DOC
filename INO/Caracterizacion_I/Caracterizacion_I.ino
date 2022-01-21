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

  float list[6] = {I1,I2,I3,I4,I5,I6};
  float max_val = get_max(list);

  float thld_0    = 15.0*max_val/500.0;
  float thld_90   = 15.0*max_val/500.0;
  float thld_180  = 15.0*max_val/500.0;
  float div0H = 1.2;  // Para 0 grados horizontal
  float div0V = 1.2;  // Para 0 grados vertical

  // *** Plano horizontal ***

  // Frontal (0 grados)
  if ( (I1+1.0e-6)/(I6+1.0e-6) < div0H && (I6+1.0e-6)/(I1+1.0e-6) < div0H && ((I6<thld_0)&&(I1<thld_0))){
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
    alpha = 191919; // Por si acaso
  }
  else {
    alpha = 999;
  }

  Serial.println("***** End report *****");

}

void writeInLDC(int angle){

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Angle");
  lcd.setCursor(0, 1);
  lcd.print(angle);
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

  Serial.print(I);

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
