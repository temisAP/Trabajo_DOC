/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled_private.h
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Jan 19 16:04:36 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_untitled_private_h_
#define RTW_HEADER_untitled_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "untitled.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void LCD_W_Start_wrapper(real_T *xD);
  extern void LCD_W_Outputs_wrapper(const real_T *H_Angle,
    const real_T *V_Angle,
    const real_T *xD);
  extern void LCD_W_Update_wrapper(const real_T *H_Angle,
    const real_T *V_Angle,
    real_T *xD);
  extern void LCD_W_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

extern real_T rt_remd_snf(real_T u0, real_T u1);
extern void untitled_Clculoalpha(real_T rtu_A, real_T rtu_B, real_T rtu_C,
  real_T rtu_b, real_T rtu_c, real_T rtu_I, real_T *rty_alpha);

#endif                                 /* RTW_HEADER_untitled_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
