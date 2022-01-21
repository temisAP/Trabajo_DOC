/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FotoTransistor_private.h
 *
 * Code generated for Simulink model 'FotoTransistor'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Jan 19 15:57:41 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FotoTransistor_private_h_
#define RTW_HEADER_FotoTransistor_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "FotoTransistor.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void LCD_Write_Start_wrapper(real_T *xD);
  extern void LCD_Write_Outputs_wrapper(const real_T *H_Angle,
    const real_T *V_Angle,
    const real_T *xD);
  extern void LCD_Write_Update_wrapper(const real_T *H_Angle,
    const real_T *V_Angle,
    real_T *xD);
  extern void LCD_Write_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

extern real_T rt_remd_snf(real_T u0, real_T u1);
extern void FotoTransistor_Clculoalpha(real_T rtu_A, real_T rtu_B, real_T rtu_C,
  real_T rtu_b, real_T rtu_c, real_T rtu_I, real_T *rty_alpha);

#endif                                /* RTW_HEADER_FotoTransistor_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
