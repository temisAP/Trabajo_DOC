/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
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

#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Forward declaration for local functions */
static void untitled_cosd(real_T *x);

/*
 * Output and update for atomic system:
 *    '<S3>/Cálculo alpha'
 *    '<S4>/Cálculo alpha'
 */
void untitled_Clculoalpha(real_T rtu_A, real_T rtu_B, real_T rtu_C, real_T rtu_b,
  real_T rtu_c, real_T rtu_I, real_T *rty_alpha)
{
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  if ((rtu_I < 0.2) && (rtu_I > 0.8)) {
    *rty_alpha = 200.0;
  } else {
    tmp_0 = rtu_A + rtu_C;
    guard1 = false;
    guard2 = false;
    if (tmp_0 != 0.0) {
      tmp_1 = rtu_A * rtu_A;
      tmp_2 = rtu_B * rtu_B;
      tmp = sqrt((tmp_1 + tmp_2) - rtu_C * rtu_C);
      if (((-rtu_B * tmp + tmp_1) + rtu_A * rtu_C) + tmp_2 != 0.0) {
        *rty_alpha = atan((rtu_B - tmp) / tmp_0) * 2.0;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      if (tmp_0 != 0.0) {
        tmp_2 = rtu_A * rtu_A;
        tmp = rtu_B * rtu_B;
        tmp_1 = sqrt((tmp_2 + tmp) - rtu_C * rtu_C);
        if (((rtu_B * tmp_1 + tmp_2) + rtu_A * rtu_C) + tmp != 0.0) {
          *rty_alpha = atan((rtu_B + tmp_1) / tmp_0) * 2.0;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }

    if (guard1) {
      if ((rtu_B != 0.0) && (rtu_A * rtu_A + rtu_B * rtu_B != 0.0) && (rtu_C ==
           -rtu_A)) {
        *rty_alpha = atan(rtu_A / rtu_B) * -2.0;
      } else if (rtu_A == -rtu_C) {
        *rty_alpha = 3.1415926535897931;
      } else {
        *rty_alpha = 1000.0;
      }
    }
  }

  *rty_alpha = (*rty_alpha - rtu_c * 3.1415926535897931 / 180.0) / rtu_b;
  *rty_alpha = *rty_alpha * 180.0 / 3.1415926535897931;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T u1_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = fabs(u0 / u1);
      if (!(fabs(u1_0 - floor(u1_0 + 0.5)) > DBL_EPSILON * u1_0)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S1>/Angle_6FT' */
static void untitled_cosd(real_T *x)
{
  int8_T n;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    untitled_B.b_x = rt_remd_snf(*x, 360.0);
    untitled_B.absx = fabs(untitled_B.b_x);
    if (untitled_B.absx > 180.0) {
      if (untitled_B.b_x > 0.0) {
        untitled_B.b_x -= 360.0;
      } else {
        untitled_B.b_x += 360.0;
      }

      untitled_B.absx = fabs(untitled_B.b_x);
    }

    if (untitled_B.absx <= 45.0) {
      untitled_B.b_x *= 0.017453292519943295;
      n = 0;
    } else if (untitled_B.absx <= 135.0) {
      if (untitled_B.b_x > 0.0) {
        untitled_B.b_x = (untitled_B.b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        untitled_B.b_x = (untitled_B.b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (untitled_B.b_x > 0.0) {
      untitled_B.b_x = (untitled_B.b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      untitled_B.b_x = (untitled_B.b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      *x = cos(untitled_B.b_x);
      break;

     case 1:
      *x = -sin(untitled_B.b_x);
      break;

     case -1:
      *x = sin(untitled_B.b_x);
      break;

     default:
      *x = -cos(untitled_B.b_x);
      break;
    }
  }
}

/* Model step function */
void untitled_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  int16_T rtb_signv;
  uint16_T rtb_Down_0;
  uint16_T rtb_Front_Left_0;
  uint16_T rtb_Front_Right_0;
  uint16_T rtb_Left_0;
  uint16_T rtb_Right_0;
  uint16_T rtb_UP_0;

  /* MATLABSystem: '<Root>/Right' */
  if (untitled_DW.obj_i.SampleTime != untitled_P.Right_SampleTime) {
    untitled_DW.obj_i.SampleTime = untitled_P.Right_SampleTime;
  }

  obj = &untitled_DW.obj_i;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (untitled_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_Right_0, 3);

  /* MATLABSystem: '<Root>/Front_Right' */
  if (untitled_DW.obj_b.SampleTime != untitled_P.Front_Right_SampleTime) {
    untitled_DW.obj_b.SampleTime = untitled_P.Front_Right_SampleTime;
  }

  obj = &untitled_DW.obj_b;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
  MW_AnalogInSingle_ReadResult
    (untitled_DW.obj_b.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_Front_Right_0,
     3);

  /* MATLABSystem: '<Root>/Down' */
  if (untitled_DW.obj_p.SampleTime != untitled_P.Down_SampleTime) {
    untitled_DW.obj_p.SampleTime = untitled_P.Down_SampleTime;
  }

  obj = &untitled_DW.obj_p;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(16UL);
  MW_AnalogInSingle_ReadResult
    (untitled_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_Down_0, 3);

  /* MATLABSystem: '<Root>/UP' */
  if (untitled_DW.obj.SampleTime != untitled_P.UP_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.UP_SampleTime;
  }

  obj = &untitled_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(17UL);
  MW_AnalogInSingle_ReadResult
    (untitled_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_UP_0, 3);

  /* MATLABSystem: '<Root>/Front_Left' */
  if (untitled_DW.obj_h.SampleTime != untitled_P.Front_Left_SampleTime) {
    untitled_DW.obj_h.SampleTime = untitled_P.Front_Left_SampleTime;
  }

  obj = &untitled_DW.obj_h;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
  MW_AnalogInSingle_ReadResult
    (untitled_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_Front_Left_0,
     3);

  /* MATLABSystem: '<Root>/Left' */
  if (untitled_DW.obj_o.SampleTime != untitled_P.Left_SampleTime) {
    untitled_DW.obj_o.SampleTime = untitled_P.Left_SampleTime;
  }

  obj = &untitled_DW.obj_o;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);
  MW_AnalogInSingle_ReadResult
    (untitled_DW.obj_o.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &rtb_Left_0, 3);

  /* MATLAB Function: '<S1>/Angle_6FT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  DataTypeConversion: '<S1>/Data Type Conversion4'
   *  DataTypeConversion: '<S1>/Data Type Conversion5'
   *  DataTypeConversion: '<S1>/Data Type Conversion6'
   *  MATLABSystem: '<Root>/Down'
   *  MATLABSystem: '<Root>/Front_Left'
   *  MATLABSystem: '<Root>/Front_Right'
   *  MATLABSystem: '<Root>/Left'
   *  MATLABSystem: '<Root>/Right'
   *  MATLABSystem: '<Root>/UP'
   */
  if ((((real_T)rtb_Right_0 + 1.0E-6) / ((real_T)rtb_Left_0 + 1.0E-6) < 1.5) &&
      (((real_T)rtb_Left_0 + 1.0E-6) / ((real_T)rtb_Right_0 + 1.0E-6) < 1.5) &&
      ((rtb_Front_Right_0 > 15U) && (rtb_Front_Left_0 > 15U))) {
    untitled_B.bh = 1.7875;
    untitled_B.ch = 11.77375;
    untitled_B.dh = 1.57625;
    untitled_B.bv = 11.77375;
    untitled_cosd(&untitled_B.bv);
    untitled_B.Ish = (untitled_B.bv + 1.57625) / 3.1396805867825153;
    untitled_B.signh = 0.0;
  } else if (rtb_Right_0 > rtb_Left_0) {
    if ((rtb_Right_0 > rtb_Front_Right_0) && (((rtb_Left_0 > rtb_Front_Right_0) &&
          (rtb_Left_0 > rtb_Front_Left_0)) || (((real_T)rtb_Front_Right_0 /
           ((real_T)rtb_Front_Left_0 + 1.0E-6) < 2.5) && ((real_T)
           rtb_Front_Left_0 / ((real_T)rtb_Front_Right_0 + 1.0E-6) < 2.5) &&
          ((rtb_Front_Right_0 < 10U) || (rtb_Front_Left_0 < 10U))))) {
      untitled_B.bh = 1.0;
      untitled_B.ch = 0.0;
      untitled_B.dh = 0.0;
      untitled_B.Ish = 0.0;
      untitled_B.signh = 1.0;
    } else {
      untitled_B.bh = 2.37125;
      untitled_B.ch = 2.827525;
      untitled_B.dh = 0.8898;
      untitled_B.Ish = (real_T)rtb_Front_Right_0 / (real_T)((int32_T)
        rtb_Front_Right_0 + rtb_Right_0);
      untitled_B.signh = 1.0;
    }
  } else if (rtb_Left_0 > rtb_Right_0) {
    if ((rtb_Left_0 > rtb_Front_Left_0) && (((rtb_Right_0 > rtb_Front_Right_0) &&
          (rtb_Right_0 > rtb_Front_Left_0)) || (((real_T)rtb_Front_Right_0 /
           ((real_T)rtb_Front_Left_0 + 1.0E-6) < 2.5) && ((real_T)
           rtb_Front_Left_0 / ((real_T)rtb_Front_Right_0 + 1.0E-6) < 2.5) &&
          ((rtb_Front_Right_0 < 15U) || (rtb_Front_Left_0 < 15U))))) {
      untitled_B.bh = 1.0;
      untitled_B.ch = 0.0;
      untitled_B.dh = 0.0;
      untitled_B.Ish = 0.0;
      untitled_B.signh = -1.0;
    } else {
      untitled_B.bh = 2.316;
      untitled_B.ch = -21.4075;
      untitled_B.dh = 0.861975;
      untitled_B.Ish = (real_T)rtb_Front_Left_0 / (real_T)((int32_T)
        rtb_Front_Left_0 + rtb_Left_0);
      untitled_B.signh = -1.0;
    }
  } else if ((rtb_Right_0 <= 15U) && (rtb_Front_Right_0 <= 5U) &&
             (rtb_Front_Left_0 <= 5U) && (rtb_Left_0 <= 15U)) {
    untitled_B.bh = 1.0;
    untitled_B.ch = 0.0;
    untitled_B.dh = 0.0;
    untitled_B.Ish = 1.0;
    untitled_B.signh = 1.0;
  } else {
    untitled_B.bh = 1.0;
    untitled_B.ch = 0.0;
    untitled_B.dh = 0.0;
    untitled_B.Ish = 1.0;
    untitled_B.signh = 0.0;
  }

  if ((((real_T)rtb_Down_0 + 1.0E-6) / ((real_T)rtb_UP_0 + 1.0E-6) < 2.0) &&
      (((real_T)rtb_Front_Right_0 + 1.0E-6) / ((real_T)rtb_Front_Left_0 + 1.0E-6)
       < 2.0)) {
    untitled_B.bv = 1.7875;
    untitled_B.cv = 11.77375;
    untitled_B.dv = 1.57625;
    untitled_B.Isv = 11.77375;
    untitled_cosd(&untitled_B.Isv);
    untitled_B.Isv = (untitled_B.Isv + 1.57625) / 3.1396805867825153;
    rtb_signv = 0;
  } else if (rtb_Down_0 + 5L < rtb_UP_0) {
    if ((rtb_Down_0 > rtb_Front_Left_0) || (((real_T)rtb_Front_Left_0 / (real_T)
          rtb_Down_0 < 2.5) && (rtb_Down_0 < 10U))) {
      untitled_B.bv = 1.0;
      untitled_B.cv = 0.0;
      untitled_B.dv = 0.0;
      untitled_B.Isv = 0.0;
      rtb_signv = 1;
    } else {
      untitled_B.bv = 1.7875;
      untitled_B.cv = 11.77375;
      untitled_B.dv = 1.57625;
      untitled_B.Isv = (real_T)rtb_Front_Left_0 / (real_T)((int32_T)rtb_UP_0 +
        rtb_Front_Left_0);
      rtb_signv = 1;
    }
  } else if (rtb_UP_0 + 5L < rtb_Down_0) {
    if ((rtb_UP_0 > rtb_Front_Right_0) || (((real_T)rtb_Front_Right_0 / (real_T)
          rtb_UP_0 < 2.5) && (rtb_UP_0 < 10U))) {
      untitled_B.bv = 1.0;
      untitled_B.cv = 0.0;
      untitled_B.dv = 0.0;
      untitled_B.Isv = 0.0;
      rtb_signv = -1;
    } else {
      untitled_B.bv = 1.7875;
      untitled_B.cv = 11.77375;
      untitled_B.dv = 1.57625;
      untitled_B.Isv = (real_T)rtb_Front_Right_0 / (real_T)((int32_T)rtb_Down_0
        + rtb_Front_Right_0);
      rtb_signv = -1;
    }
  } else {
    untitled_B.bv = 1.7875;
    untitled_B.cv = 11.77375;
    untitled_B.dv = 1.57625;
    untitled_B.Isv = 11.77375;
    untitled_cosd(&untitled_B.Isv);
    untitled_B.Isv = (untitled_B.Isv + 1.57625) / 3.1396805867825153;
    rtb_signv = 0;
  }

  /* End of MATLAB Function: '<S1>/Angle_6FT' */

  /* MATLAB Function: '<S3>/Cálculo alpha' incorporates:
   *  Constant: '<S3>/Desfase'
   *  Constant: '<S5>/Intensidad1'
   *  Constant: '<S5>/Theta1'
   *  Constant: '<S5>/Theta2'
   *  Constant: '<S6>/Intensidad1'
   *  Constant: '<S6>/Theta1'
   *  Constant: '<S6>/Theta2'
   *  Constant: '<S7>/Intensidad1'
   *  Constant: '<S7>/Intensidad3'
   *  Product: '<S5>/Divide1'
   *  Product: '<S5>/Product1'
   *  Product: '<S5>/Product2'
   *  Product: '<S5>/Product3'
   *  Product: '<S6>/Divide1'
   *  Product: '<S6>/Product1'
   *  Product: '<S6>/Product2'
   *  Product: '<S6>/Product3'
   *  Product: '<S6>/Product4'
   *  Product: '<S7>/Product1'
   *  Product: '<S7>/Product4'
   *  Sum: '<S5>/Add'
   *  Sum: '<S7>/Add'
   *  Trigonometry: '<S5>/Trigonometric Function'
   *  Trigonometry: '<S6>/Trigonometric Function'
   */
  untitled_Clculoalpha((untitled_B.Ish - untitled_P.Intensidad1_Value) +
                       untitled_B.Ish * cos(untitled_B.bh *
    (untitled_P.Desfase_Value * (untitled_P.Theta2_Value /
    untitled_P.Theta1_Value))), untitled_P.Intensidad1_Value_b * untitled_B.Ish *
                       sin(untitled_B.bh * (untitled_P.Desfase_Value *
    (untitled_P.Theta2_Value_b / untitled_P.Theta1_Value_g))), untitled_B.dh *
                       (untitled_P.Intensidad1_Value_f - untitled_B.Ish *
                        untitled_P.Intensidad3_Value), untitled_B.bh,
                       untitled_B.ch, untitled_B.Ish, &untitled_B.alpha);

  /* Product: '<S1>/Product' */
  untitled_B.Product = untitled_B.alpha * untitled_B.signh;

  /* MATLAB Function: '<S4>/Cálculo alpha' incorporates:
   *  Constant: '<S10>/Intensidad1'
   *  Constant: '<S10>/Theta1'
   *  Constant: '<S10>/Theta2'
   *  Constant: '<S11>/Intensidad1'
   *  Constant: '<S11>/Intensidad3'
   *  Constant: '<S4>/Desfase'
   *  Constant: '<S9>/Intensidad1'
   *  Constant: '<S9>/Theta1'
   *  Constant: '<S9>/Theta2'
   *  Product: '<S10>/Divide1'
   *  Product: '<S10>/Product1'
   *  Product: '<S10>/Product2'
   *  Product: '<S10>/Product3'
   *  Product: '<S10>/Product4'
   *  Product: '<S11>/Product1'
   *  Product: '<S11>/Product4'
   *  Product: '<S9>/Divide1'
   *  Product: '<S9>/Product1'
   *  Product: '<S9>/Product2'
   *  Product: '<S9>/Product3'
   *  Sum: '<S11>/Add'
   *  Sum: '<S9>/Add'
   *  Trigonometry: '<S10>/Trigonometric Function'
   *  Trigonometry: '<S9>/Trigonometric Function'
   */
  untitled_Clculoalpha((untitled_B.Isv - untitled_P.Intensidad1_Value_m) +
                       untitled_B.Isv * cos(untitled_B.bv *
    (untitled_P.Desfase_Value_m * (untitled_P.Theta2_Value_i /
    untitled_P.Theta1_Value_e))), untitled_P.Intensidad1_Value_c *
                       untitled_B.Isv * sin(untitled_B.bv *
    (untitled_P.Desfase_Value_m * (untitled_P.Theta2_Value_p /
    untitled_P.Theta1_Value_n))), untitled_B.dv *
                       (untitled_P.Intensidad1_Value_p - untitled_B.Isv *
                        untitled_P.Intensidad3_Value_a), untitled_B.bv,
                       untitled_B.cv, untitled_B.Isv, &untitled_B.alpha);

  /* Product: '<S1>/Product1' */
  untitled_B.Product1 = untitled_B.alpha * (real_T)rtb_signv;

  /* S-Function (LCD_W): '<Root>/S-Function Builder' */
  LCD_W_Outputs_wrapper(&untitled_B.Product, &untitled_B.Product1,
                        &untitled_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (LCD_W): '<Root>/S-Function Builder' */

  /* S-Function "LCD_W_wrapper" Block: <Root>/S-Function Builder */
  LCD_W_Update_wrapper(&untitled_B.Product, &untitled_B.Product1,
                       &untitled_DW.SFunctionBuilder_DSTATE);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, (real_T)untitled_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.taskTime0) >
          untitled_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled_M)) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.taskTime0 =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(untitled_M, 10.0);
  untitled_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (2297852557U);
  untitled_M->Sizes.checksums[1] = (2216972510U);
  untitled_M->Sizes.checksums[2] = (2953674817U);
  untitled_M->Sizes.checksums[3] = (3809376532U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* InitializeConditions for S-Function (LCD_W): '<Root>/S-Function Builder' */

    /* S-Function Block: <Root>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          untitled_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* Start for MATLABSystem: '<Root>/Right' */
    untitled_DW.obj_i.matlabCodegenIsDeleted = true;
    untitled_DW.obj_i.isInitialized = 0L;
    untitled_DW.obj_i.SampleTime = -1.0;
    untitled_DW.obj_i.matlabCodegenIsDeleted = false;
    untitled_DW.obj_i.SampleTime = untitled_P.Right_SampleTime;
    obj = &untitled_DW.obj_i;
    untitled_DW.obj_i.isSetupComplete = false;
    untitled_DW.obj_i.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(14UL);
    untitled_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Front_Right' */
    untitled_DW.obj_b.matlabCodegenIsDeleted = true;
    untitled_DW.obj_b.isInitialized = 0L;
    untitled_DW.obj_b.SampleTime = -1.0;
    untitled_DW.obj_b.matlabCodegenIsDeleted = false;
    untitled_DW.obj_b.SampleTime = untitled_P.Front_Right_SampleTime;
    obj = &untitled_DW.obj_b;
    untitled_DW.obj_b.isSetupComplete = false;
    untitled_DW.obj_b.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(15UL);
    untitled_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Down' */
    untitled_DW.obj_p.matlabCodegenIsDeleted = true;
    untitled_DW.obj_p.isInitialized = 0L;
    untitled_DW.obj_p.SampleTime = -1.0;
    untitled_DW.obj_p.matlabCodegenIsDeleted = false;
    untitled_DW.obj_p.SampleTime = untitled_P.Down_SampleTime;
    obj = &untitled_DW.obj_p;
    untitled_DW.obj_p.isSetupComplete = false;
    untitled_DW.obj_p.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16UL);
    untitled_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/UP' */
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    untitled_DW.obj.isInitialized = 0L;
    untitled_DW.obj.SampleTime = -1.0;
    untitled_DW.obj.matlabCodegenIsDeleted = false;
    untitled_DW.obj.SampleTime = untitled_P.UP_SampleTime;
    obj = &untitled_DW.obj;
    untitled_DW.obj.isSetupComplete = false;
    untitled_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17UL);
    untitled_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Front_Left' */
    untitled_DW.obj_h.matlabCodegenIsDeleted = true;
    untitled_DW.obj_h.isInitialized = 0L;
    untitled_DW.obj_h.SampleTime = -1.0;
    untitled_DW.obj_h.matlabCodegenIsDeleted = false;
    untitled_DW.obj_h.SampleTime = untitled_P.Front_Left_SampleTime;
    obj = &untitled_DW.obj_h;
    untitled_DW.obj_h.isSetupComplete = false;
    untitled_DW.obj_h.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(18UL);
    untitled_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Left' */
    untitled_DW.obj_o.matlabCodegenIsDeleted = true;
    untitled_DW.obj_o.isInitialized = 0L;
    untitled_DW.obj_o.SampleTime = -1.0;
    untitled_DW.obj_o.matlabCodegenIsDeleted = false;
    untitled_DW.obj_o.SampleTime = untitled_P.Left_SampleTime;
    obj = &untitled_DW.obj_o;
    untitled_DW.obj_o.isSetupComplete = false;
    untitled_DW.obj_o.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(19UL);
    untitled_DW.obj_o.isSetupComplete = true;
  }
}

/* Model terminate function */
void untitled_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Right' */
  obj = &untitled_DW.obj_i;
  if (!untitled_DW.obj_i.matlabCodegenIsDeleted) {
    untitled_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_i.isInitialized == 1L) &&
        untitled_DW.obj_i.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close(untitled_DW.obj_i.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Right' */

  /* Terminate for MATLABSystem: '<Root>/Front_Right' */
  obj = &untitled_DW.obj_b;
  if (!untitled_DW.obj_b.matlabCodegenIsDeleted) {
    untitled_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_b.isInitialized == 1L) &&
        untitled_DW.obj_b.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close(untitled_DW.obj_b.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Front_Right' */

  /* Terminate for MATLABSystem: '<Root>/Down' */
  obj = &untitled_DW.obj_p;
  if (!untitled_DW.obj_p.matlabCodegenIsDeleted) {
    untitled_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_p.isInitialized == 1L) &&
        untitled_DW.obj_p.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(16UL);
      MW_AnalogIn_Close(untitled_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Down' */

  /* Terminate for MATLABSystem: '<Root>/UP' */
  obj = &untitled_DW.obj;
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj.isInitialized == 1L) && untitled_DW.obj.isSetupComplete)
    {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(17UL);
      MW_AnalogIn_Close(untitled_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/UP' */

  /* Terminate for MATLABSystem: '<Root>/Front_Left' */
  obj = &untitled_DW.obj_h;
  if (!untitled_DW.obj_h.matlabCodegenIsDeleted) {
    untitled_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_h.isInitialized == 1L) &&
        untitled_DW.obj_h.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
      MW_AnalogIn_Close(untitled_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Front_Left' */

  /* Terminate for MATLABSystem: '<Root>/Left' */
  obj = &untitled_DW.obj_o;
  if (!untitled_DW.obj_o.matlabCodegenIsDeleted) {
    untitled_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_o.isInitialized == 1L) &&
        untitled_DW.obj_o.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(19UL);
      MW_AnalogIn_Close(untitled_DW.obj_o.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Left' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
