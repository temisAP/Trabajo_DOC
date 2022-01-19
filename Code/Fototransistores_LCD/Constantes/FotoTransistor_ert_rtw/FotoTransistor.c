/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FotoTransistor.c
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

#include "FotoTransistor.h"
#include "FotoTransistor_private.h"
#include "FotoTransistor_dt.h"

/* Block signals (default storage) */
B_FotoTransistor_T FotoTransistor_B;

/* Block states (default storage) */
DW_FotoTransistor_T FotoTransistor_DW;

/* Real-time model */
static RT_MODEL_FotoTransistor_T FotoTransistor_M_;
RT_MODEL_FotoTransistor_T *const FotoTransistor_M = &FotoTransistor_M_;

/* Forward declaration for local functions */
static void FotoTransistor_cosd(real_T *x);

/*
 * Output and update for atomic system:
 *    '<S3>/Cálculo alpha'
 *    '<S4>/Cálculo alpha'
 */
void FotoTransistor_Clculoalpha(real_T rtu_A, real_T rtu_B, real_T rtu_C, real_T
  rtu_b, real_T rtu_c, real_T rtu_I, real_T *rty_alpha)
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
static void FotoTransistor_cosd(real_T *x)
{
  real_T absx;
  real_T b_x;
  int8_T n;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    b_x = rt_remd_snf(*x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = (b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      b_x = (b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      *x = cos(b_x);
      break;

     case 1:
      *x = -sin(b_x);
      break;

     case -1:
      *x = sin(b_x);
      break;

     default:
      *x = -cos(b_x);
      break;
    }
  }
}

/* Model step function */
void FotoTransistor_step(void)
{
  int16_T rtb_signv;

  /* MATLAB Function: '<S1>/Angle_6FT' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   */
  if (((FotoTransistor_P.Constant_Value + 1.0E-6) /
       (FotoTransistor_P.Constant1_Value + 1.0E-6) < 1.5) &&
      ((FotoTransistor_P.Constant1_Value + 1.0E-6) /
       (FotoTransistor_P.Constant_Value + 1.0E-6) < 1.5) &&
      ((FotoTransistor_P.Constant2_Value > 15.0) &&
       (FotoTransistor_P.Constant5_Value > 15.0))) {
    FotoTransistor_B.bh = 1.7875;
    FotoTransistor_B.ch = 11.77375;
    FotoTransistor_B.dh = 1.57625;
    FotoTransistor_B.bv = 11.77375;
    FotoTransistor_cosd(&FotoTransistor_B.bv);
    FotoTransistor_B.Ish = (FotoTransistor_B.bv + 1.57625) / 3.1396805867825153;
    FotoTransistor_B.signh = 0.0;
  } else if (FotoTransistor_P.Constant_Value > FotoTransistor_P.Constant1_Value)
  {
    if ((FotoTransistor_P.Constant_Value > FotoTransistor_P.Constant2_Value) &&
        (((FotoTransistor_P.Constant1_Value > FotoTransistor_P.Constant2_Value) &&
          (FotoTransistor_P.Constant1_Value > FotoTransistor_P.Constant5_Value))
         || ((FotoTransistor_P.Constant2_Value /
              (FotoTransistor_P.Constant5_Value + 1.0E-6) < 2.5) &&
             (FotoTransistor_P.Constant5_Value /
              (FotoTransistor_P.Constant2_Value + 1.0E-6) < 2.5) &&
             ((FotoTransistor_P.Constant2_Value < 10.0) ||
              (FotoTransistor_P.Constant5_Value < 10.0))))) {
      FotoTransistor_B.bh = 1.0;
      FotoTransistor_B.ch = 0.0;
      FotoTransistor_B.dh = 0.0;
      FotoTransistor_B.Ish = 0.0;
      FotoTransistor_B.signh = 1.0;
    } else {
      FotoTransistor_B.bh = 2.37125;
      FotoTransistor_B.ch = 2.827525;
      FotoTransistor_B.dh = 0.8898;
      FotoTransistor_B.Ish = FotoTransistor_P.Constant2_Value /
        (FotoTransistor_P.Constant2_Value + FotoTransistor_P.Constant_Value);
      FotoTransistor_B.signh = 1.0;
    }
  } else if (FotoTransistor_P.Constant1_Value > FotoTransistor_P.Constant_Value)
  {
    if ((FotoTransistor_P.Constant1_Value > FotoTransistor_P.Constant5_Value) &&
        (((FotoTransistor_P.Constant_Value > FotoTransistor_P.Constant2_Value) &&
          (FotoTransistor_P.Constant_Value > FotoTransistor_P.Constant5_Value)) ||
         ((FotoTransistor_P.Constant2_Value / (FotoTransistor_P.Constant5_Value
            + 1.0E-6) < 2.5) && (FotoTransistor_P.Constant5_Value /
           (FotoTransistor_P.Constant2_Value + 1.0E-6) < 2.5) &&
          ((FotoTransistor_P.Constant2_Value < 15.0) ||
           (FotoTransistor_P.Constant5_Value < 15.0))))) {
      FotoTransistor_B.bh = 1.0;
      FotoTransistor_B.ch = 0.0;
      FotoTransistor_B.dh = 0.0;
      FotoTransistor_B.Ish = 0.0;
      FotoTransistor_B.signh = -1.0;
    } else {
      FotoTransistor_B.bh = 2.316;
      FotoTransistor_B.ch = -21.4075;
      FotoTransistor_B.dh = 0.861975;
      FotoTransistor_B.Ish = FotoTransistor_P.Constant5_Value /
        (FotoTransistor_P.Constant5_Value + FotoTransistor_P.Constant1_Value);
      FotoTransistor_B.signh = -1.0;
    }
  } else if ((FotoTransistor_P.Constant_Value <= 15.0) &&
             (FotoTransistor_P.Constant2_Value <= 5.0) &&
             (FotoTransistor_P.Constant5_Value <= 5.0) &&
             (FotoTransistor_P.Constant1_Value <= 15.0)) {
    FotoTransistor_B.bh = 1.0;
    FotoTransistor_B.ch = 0.0;
    FotoTransistor_B.dh = 0.0;
    FotoTransistor_B.Ish = 1.0;
    FotoTransistor_B.signh = 1.0;
  } else {
    FotoTransistor_B.bh = 1.0;
    FotoTransistor_B.ch = 0.0;
    FotoTransistor_B.dh = 0.0;
    FotoTransistor_B.Ish = 1.0;
    FotoTransistor_B.signh = 0.0;
  }

  if (((FotoTransistor_P.Constant3_Value + 1.0E-6) /
       (FotoTransistor_P.Constant4_Value + 1.0E-6) < 2.0) &&
      ((FotoTransistor_P.Constant2_Value + 1.0E-6) /
       (FotoTransistor_P.Constant5_Value + 1.0E-6) < 2.0)) {
    FotoTransistor_B.bv = 1.7875;
    FotoTransistor_B.cv = 11.77375;
    FotoTransistor_B.dv = 1.57625;
    FotoTransistor_B.Isv = 11.77375;
    FotoTransistor_cosd(&FotoTransistor_B.Isv);
    FotoTransistor_B.Isv = (FotoTransistor_B.Isv + 1.57625) / 3.1396805867825153;
    rtb_signv = 0;
  } else if (FotoTransistor_P.Constant3_Value + 5.0 <
             FotoTransistor_P.Constant4_Value) {
    if ((FotoTransistor_P.Constant3_Value > FotoTransistor_P.Constant5_Value) ||
        ((FotoTransistor_P.Constant5_Value / FotoTransistor_P.Constant3_Value <
          2.5) && (FotoTransistor_P.Constant3_Value < 10.0))) {
      FotoTransistor_B.bv = 1.0;
      FotoTransistor_B.cv = 0.0;
      FotoTransistor_B.dv = 0.0;
      FotoTransistor_B.Isv = 0.0;
      rtb_signv = 1;
    } else {
      FotoTransistor_B.bv = 1.7875;
      FotoTransistor_B.cv = 11.77375;
      FotoTransistor_B.dv = 1.57625;
      FotoTransistor_B.Isv = FotoTransistor_P.Constant5_Value /
        (FotoTransistor_P.Constant4_Value + FotoTransistor_P.Constant5_Value);
      rtb_signv = 1;
    }
  } else if (FotoTransistor_P.Constant4_Value + 5.0 <
             FotoTransistor_P.Constant3_Value) {
    if ((FotoTransistor_P.Constant4_Value > FotoTransistor_P.Constant2_Value) ||
        ((FotoTransistor_P.Constant2_Value / FotoTransistor_P.Constant4_Value <
          2.5) && (FotoTransistor_P.Constant4_Value < 10.0))) {
      FotoTransistor_B.bv = 1.0;
      FotoTransistor_B.cv = 0.0;
      FotoTransistor_B.dv = 0.0;
      FotoTransistor_B.Isv = 0.0;
      rtb_signv = -1;
    } else {
      FotoTransistor_B.bv = 1.7875;
      FotoTransistor_B.cv = 11.77375;
      FotoTransistor_B.dv = 1.57625;
      FotoTransistor_B.Isv = FotoTransistor_P.Constant2_Value /
        (FotoTransistor_P.Constant3_Value + FotoTransistor_P.Constant2_Value);
      rtb_signv = -1;
    }
  } else {
    FotoTransistor_B.bv = 1.7875;
    FotoTransistor_B.cv = 11.77375;
    FotoTransistor_B.dv = 1.57625;
    FotoTransistor_B.Isv = 11.77375;
    FotoTransistor_cosd(&FotoTransistor_B.Isv);
    FotoTransistor_B.Isv = (FotoTransistor_B.Isv + 1.57625) / 3.1396805867825153;
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
  FotoTransistor_Clculoalpha((FotoTransistor_B.Ish -
    FotoTransistor_P.Intensidad1_Value) + FotoTransistor_B.Ish * cos
    (FotoTransistor_B.bh * (FotoTransistor_P.Desfase_Value *
    (FotoTransistor_P.Theta2_Value / FotoTransistor_P.Theta1_Value))),
    FotoTransistor_P.Intensidad1_Value_g * FotoTransistor_B.Ish * sin
    (FotoTransistor_B.bh * (FotoTransistor_P.Desfase_Value *
    (FotoTransistor_P.Theta2_Value_b / FotoTransistor_P.Theta1_Value_n))),
    FotoTransistor_B.dh * (FotoTransistor_P.Intensidad1_Value_p -
    FotoTransistor_B.Ish * FotoTransistor_P.Intensidad3_Value),
    FotoTransistor_B.bh, FotoTransistor_B.ch, FotoTransistor_B.Ish,
    &FotoTransistor_B.alpha);

  /* Product: '<S1>/Product' */
  FotoTransistor_B.Product = FotoTransistor_B.alpha * FotoTransistor_B.signh;

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
  FotoTransistor_Clculoalpha((FotoTransistor_B.Isv -
    FotoTransistor_P.Intensidad1_Value_i) + FotoTransistor_B.Isv * cos
    (FotoTransistor_B.bv * (FotoTransistor_P.Desfase_Value_m *
    (FotoTransistor_P.Theta2_Value_c / FotoTransistor_P.Theta1_Value_h))),
    FotoTransistor_P.Intensidad1_Value_n * FotoTransistor_B.Isv * sin
    (FotoTransistor_B.bv * (FotoTransistor_P.Desfase_Value_m *
    (FotoTransistor_P.Theta2_Value_e / FotoTransistor_P.Theta1_Value_g))),
    FotoTransistor_B.dv * (FotoTransistor_P.Intensidad1_Value_l -
    FotoTransistor_B.Isv * FotoTransistor_P.Intensidad3_Value_m),
    FotoTransistor_B.bv, FotoTransistor_B.cv, FotoTransistor_B.Isv,
    &FotoTransistor_B.alpha);

  /* Product: '<S1>/Product1' */
  FotoTransistor_B.Product1 = FotoTransistor_B.alpha * (real_T)rtb_signv;

  /* S-Function (LCD_Write): '<Root>/S-Function Builder' */
  LCD_Write_Outputs_wrapper(&FotoTransistor_B.Product,
    &FotoTransistor_B.Product1, &FotoTransistor_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (LCD_Write): '<Root>/S-Function Builder' */

  /* S-Function "LCD_Write_wrapper" Block: <Root>/S-Function Builder */
  LCD_Write_Update_wrapper(&FotoTransistor_B.Product, &FotoTransistor_B.Product1,
    &FotoTransistor_DW.SFunctionBuilder_DSTATE);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.2s, 0.0s] */
    rtExtModeUpload(0, (real_T)FotoTransistor_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(FotoTransistor_M)!=-1) &&
        !((rtmGetTFinal(FotoTransistor_M)-FotoTransistor_M->Timing.taskTime0) >
          FotoTransistor_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(FotoTransistor_M, "Simulation finished");
    }

    if (rtmGetStopRequested(FotoTransistor_M)) {
      rtmSetErrorStatus(FotoTransistor_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  FotoTransistor_M->Timing.taskTime0 =
    ((time_T)(++FotoTransistor_M->Timing.clockTick0)) *
    FotoTransistor_M->Timing.stepSize0;
}

/* Model initialize function */
void FotoTransistor_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(FotoTransistor_M, 10.0);
  FotoTransistor_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  FotoTransistor_M->Sizes.checksums[0] = (3377036808U);
  FotoTransistor_M->Sizes.checksums[1] = (3262309270U);
  FotoTransistor_M->Sizes.checksums[2] = (3963740898U);
  FotoTransistor_M->Sizes.checksums[3] = (4045911440U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    FotoTransistor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(FotoTransistor_M->extModeInfo,
      &FotoTransistor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(FotoTransistor_M->extModeInfo,
                        FotoTransistor_M->Sizes.checksums);
    rteiSetTPtr(FotoTransistor_M->extModeInfo, rtmGetTPtr(FotoTransistor_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    FotoTransistor_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* InitializeConditions for S-Function (LCD_Write): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        FotoTransistor_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void FotoTransistor_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
