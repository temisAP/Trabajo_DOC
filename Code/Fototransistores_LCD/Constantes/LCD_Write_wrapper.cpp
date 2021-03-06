
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>

#ifndef MATLAB_MEX_FILE
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal.cpp>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
extern "C" void LCD_Write_Outputs_wrapper(const real_T *H_Angle,
			const real_T *V_Angle,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0] == 1)
{
#ifndef MATLAB_MEX_FILE
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Angle");
lcd.setCursor(0, 1);
lcd.print("H: ");
lcd.print(H_Angle[0]);
lcd.print(" V: ");
lcd.print(V_Angle[0]);

#endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void LCD_Write_Update_wrapper(const real_T *H_Angle,
			const real_T *V_Angle,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0] != 1)
{
    #ifndef MATLAB_MEX_FILE
      // set up the LCD's number of columns and rorws:
    lcd.begin(16, 2);
      // print a message to the LCD
    lcd.print("Angle");
    #endif
      // done with initialization
xD[0] = 1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

