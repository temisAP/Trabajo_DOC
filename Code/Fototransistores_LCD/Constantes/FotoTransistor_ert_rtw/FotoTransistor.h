/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FotoTransistor.h
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

#ifndef RTW_HEADER_FotoTransistor_h_
#define RTW_HEADER_FotoTransistor_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef FotoTransistor_COMMON_INCLUDES_
#define FotoTransistor_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* FotoTransistor_COMMON_INCLUDES_ */

#include "FotoTransistor_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Product;                      /* '<S1>/Product' */
  real_T Product1;                     /* '<S1>/Product1' */
  real_T Ish;                          /* '<S1>/Angle_6FT' */
  real_T signh;                        /* '<S1>/Angle_6FT' */
  real_T bh;                           /* '<S1>/Angle_6FT' */
  real_T ch;                           /* '<S1>/Angle_6FT' */
  real_T dh;                           /* '<S1>/Angle_6FT' */
  real_T bv;                           /* '<S1>/Angle_6FT' */
  real_T cv;                           /* '<S1>/Angle_6FT' */
  real_T dv;                           /* '<S1>/Angle_6FT' */
  real_T Isv;                          /* '<S1>/Angle_6FT' */
  real_T alpha;                        /* '<S4>/C?lculo alpha' */
} B_FotoTransistor_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T SFunctionBuilder_DSTATE;      /* '<Root>/S-Function Builder' */
} DW_FotoTransistor_T;

/* Parameters (default storage) */
struct P_FotoTransistor_T_ {
  real_T Intensidad1_Value;            /* Expression: 1
                                        * Referenced by: '<S5>/Intensidad1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Desfase_Value;                /* Expression: 90
                                        * Referenced by: '<S3>/Desfase'
                                        */
  real_T Theta2_Value;                 /* Expression: pi
                                        * Referenced by: '<S5>/Theta2'
                                        */
  real_T Theta1_Value;                 /* Expression: 180
                                        * Referenced by: '<S5>/Theta1'
                                        */
  real_T Intensidad1_Value_g;          /* Expression: -1
                                        * Referenced by: '<S6>/Intensidad1'
                                        */
  real_T Theta2_Value_b;               /* Expression: pi
                                        * Referenced by: '<S6>/Theta2'
                                        */
  real_T Theta1_Value_n;               /* Expression: 180
                                        * Referenced by: '<S6>/Theta1'
                                        */
  real_T Intensidad1_Value_p;          /* Expression: 1
                                        * Referenced by: '<S7>/Intensidad1'
                                        */
  real_T Intensidad3_Value;            /* Expression: 2
                                        * Referenced by: '<S7>/Intensidad3'
                                        */
  real_T Intensidad1_Value_i;          /* Expression: 1
                                        * Referenced by: '<S9>/Intensidad1'
                                        */
  real_T Desfase_Value_m;              /* Expression: 90
                                        * Referenced by: '<S4>/Desfase'
                                        */
  real_T Theta2_Value_c;               /* Expression: pi
                                        * Referenced by: '<S9>/Theta2'
                                        */
  real_T Theta1_Value_h;               /* Expression: 180
                                        * Referenced by: '<S9>/Theta1'
                                        */
  real_T Intensidad1_Value_n;          /* Expression: -1
                                        * Referenced by: '<S10>/Intensidad1'
                                        */
  real_T Theta2_Value_e;               /* Expression: pi
                                        * Referenced by: '<S10>/Theta2'
                                        */
  real_T Theta1_Value_g;               /* Expression: 180
                                        * Referenced by: '<S10>/Theta1'
                                        */
  real_T Intensidad1_Value_l;          /* Expression: 1
                                        * Referenced by: '<S11>/Intensidad1'
                                        */
  real_T Intensidad3_Value_m;          /* Expression: 2
                                        * Referenced by: '<S11>/Intensidad3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_FotoTransistor_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_FotoTransistor_T FotoTransistor_P;

/* Block signals (default storage) */
extern B_FotoTransistor_T FotoTransistor_B;

/* Block states (default storage) */
extern DW_FotoTransistor_T FotoTransistor_DW;

/* Model entry point functions */
extern void FotoTransistor_initialize(void);
extern void FotoTransistor_step(void);
extern void FotoTransistor_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FotoTransistor_T *const FotoTransistor_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion6' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FotoTransistor'
 * '<S1>'   : 'FotoTransistor/Subsystem'
 * '<S2>'   : 'FotoTransistor/Subsystem/Angle_6FT'
 * '<S3>'   : 'FotoTransistor/Subsystem/Horizontal Angle'
 * '<S4>'   : 'FotoTransistor/Subsystem/Vertical Angle'
 * '<S5>'   : 'FotoTransistor/Subsystem/Horizontal Angle/C?lculo A'
 * '<S6>'   : 'FotoTransistor/Subsystem/Horizontal Angle/C?lculo B'
 * '<S7>'   : 'FotoTransistor/Subsystem/Horizontal Angle/C?lculo C'
 * '<S8>'   : 'FotoTransistor/Subsystem/Horizontal Angle/C?lculo alpha'
 * '<S9>'   : 'FotoTransistor/Subsystem/Vertical Angle/C?lculo A'
 * '<S10>'  : 'FotoTransistor/Subsystem/Vertical Angle/C?lculo B'
 * '<S11>'  : 'FotoTransistor/Subsystem/Vertical Angle/C?lculo C'
 * '<S12>'  : 'FotoTransistor/Subsystem/Vertical Angle/C?lculo alpha'
 */
#endif                                 /* RTW_HEADER_FotoTransistor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
