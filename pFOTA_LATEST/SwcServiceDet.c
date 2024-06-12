#define DET_SOURCE
#ifdef __cplusplus
extern "C"
{
#endif

#include "SwcServiceDet.hpp"

#include "Compiler.hpp"
#if defined (_MICROSOFT_C_CANOE_) || defined (_MICROSOFT_C_VTT_)
#define DET_COMP_ANSI_CANOE
#endif

#if defined (DET_COMP_ANSI_CANOE)
#include <stdio.h>
#include "SwcServiceOs.hpp"
#include "CANoeApi.hpp"
#if(_MSC_VER >= 1400)
#include <string.h>
#include <time.h>
#endif
#endif

#if(DET_DEBUG_ENABLED == STD_ON)
#include "SchM_Det.hpp"
#endif

#if(DET_FORWARD_TO_DLT == STD_ON)
#include "Dlt.hpp"
#endif

#if(DET_SW_MAJOR_VERSION != 11)
# error "Source and Header file are inconsistent!"
#endif

#if(DET_SW_MINOR_VERSION != 0)
# error "Source and Header file are inconsistent!"
#endif

#if(DET_SW_PATCH_VERSION != 0)
# error "Source and Header file are inconsistent!"
#endif

#if !defined (DET_LOCAL)
#define DET_LOCAL  static
#endif

#if !defined (DET_LOCAL_INLINE)
#if defined (LOCAL_INLINE)
#define DET_LOCAL_INLINE  LOCAL_INLINE
#else
#define DET_LOCAL_INLINE  DET_LOCAL
#endif
#endif

#if(DET_ENABLED == STD_ON)

#define Det_EnterCritical() SchM_Enter_Det_DET_EXCLUSIVE_AREA_0()
#define Det_LeaveCritical() SchM_Exit_Det_DET_EXCLUSIVE_AREA_0()

#define DET_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.hpp"

DET_LOCAL volatile VAR(boolean, DET_VAR) detModuleInit = FALSE;

#define DET_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.hpp"

#define DET_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.hpp"

#if(DET_REPORT_ERROR_RECURSIONLIMIT > 0)
DET_LOCAL volatile VAR(uint8, DET_VAR) detRecursionCounterReportError;
#endif

#if(DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT > 0)
DET_LOCAL volatile VAR(uint8, DET_VAR) detRecursionCounterReportRuntimeError;
#endif

#if(DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT > 0)
DET_LOCAL volatile VAR(uint8, DET_VAR) detRecursionCounterReportTransientFault;
#endif

#define DET_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.hpp"

#define DET_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"

#if(DET_DEBUG_ENABLED == STD_ON)

#if(DET_GLOBALFILTERSIZE > 0)
volatile VAR(DetInfoType, DET_VAR) detGlobalFilter[DET_GLOBALFILTERSIZE];
#endif
#if(DET_BREAKFILTERSIZE > 0)
volatile VAR(DetInfoType, DET_VAR) detBreakFilter[DET_BREAKFILTERSIZE];
#endif
#if(DET_DLTFILTERSIZE > 0)
volatile VAR(DetInfoType, DET_VAR) detDltFilter[DET_DLTFILTERSIZE];
#endif
#if(DET_LOGBUFFERSIZE > 0)
volatile VAR(DetInfoType, DET_VAR) detLogBuffer[DET_LOGBUFFERSIZE];
#endif
volatile VAR(DetStatusType, DET_VAR) detStatus;

#endif

#define DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.hpp"

#define DET_START_SEC_CODE
#include "MemMap.hpp"

#if(DET_DEBUG_ENABLED == STD_ON)

#if(DET_GLOBALFILTERSIZE > 0) || (DET_BREAKFILTERSIZE > 0)
DET_LOCAL_INLINE FUNC(boolean, DET_CODE) Det_CheckFilterMatch( volatile P2CONST( DetInfoType, AUTOMATIC, DET_VAR ) filter, uint8 size, boolean active, P2CONST( DetInfoType, AUTOMATIC, DET_VAR ) detInfo );
#endif

#if(DET_LOGBUFFERSIZE > 0)
DET_LOCAL_INLINE FUNC(boolean, DET_CODE) Det_LogError( boolean active, P2CONST( DetInfoType, AUTOMATIC, DET_VAR ) detInfo );
#endif

#endif

#if defined (DET_COMP_ANSI_CANOE)
DET_LOCAL_INLINE FUNC(void, DET_CODE) Det_CanoeOutput( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );
#endif

DET_LOCAL FUNC(void, DET_CODE) Det_EndlessLoop(void);

#if(DET_DEBUG_ENABLED == STD_ON)

#if(DET_GLOBALFILTERSIZE > 0) || (DET_BREAKFILTERSIZE > 0)
DET_LOCAL_INLINE FUNC(boolean, DET_CODE) Det_CheckFilterMatch( volatile P2CONST( DetInfoType, AUTOMATIC, DET_VAR ) filter, uint8 size, boolean active, P2CONST( DetInfoType, AUTOMATIC, DET_VAR ) detInfo ){
  VAR(uint8_least, AUTOMATIC) i;
  VAR (boolean, AUTOMATIC) retval = FALSE;

  if(active == TRUE){
    for(i = 0; i < size; i++){
      if(
        ((filter[i].mModuleId == detInfo->mModuleId) || (filter[i].mModuleId == DET_DONTCARE_16)) &&
        ((filter[i].mInstanceId == detInfo->mInstanceId) || (filter[i].mInstanceId == DET_DONTCARE_8)) &&
        ((filter[i].mApiId == detInfo->mApiId) || (filter[i].mApiId == DET_DONTCARE_8)) &&
        ((filter[i].mErrorId == detInfo->mErrorId) || (filter[i].mErrorId == DET_DONTCARE_8))
        )
      {
        retval = TRUE;
        break;
      }
    }
  }
  return retval;
}
#endif

#if(DET_LOGBUFFERSIZE > 0)
DET_LOCAL_INLINE FUNC(boolean, DET_CODE) Det_LogError( boolean active, P2CONST( DetInfoType, AUTOMATIC, DET_VAR ) detInfo ){
  VAR (boolean, AUTOMATIC) forceBreakHandler = FALSE;

  if(active == TRUE){
      Det_EnterCritical();
      detStatus.logIndex++;

      if(detStatus.logIndex >= DET_LOGBUFFERSIZE)
      {
        detStatus.logIndex = 0;

        if(detStatus.breakOnLogOverrun == TRUE)
        {
          forceBreakHandler = TRUE;
        }
      }

      detLogBuffer[detStatus.logIndex].mModuleId = detInfo->mModuleId;
      detLogBuffer[detStatus.logIndex].mInstanceId = detInfo->mInstanceId;
      detLogBuffer[detStatus.logIndex].mApiId = detInfo->mApiId;
      detLogBuffer[detStatus.logIndex].mErrorId = detInfo->mErrorId;
      Det_LeaveCritical();
  }
  return forceBreakHandler;
}
#endif

#endif

#if defined (DET_COMP_ANSI_CANOE)
DET_LOCAL_INLINE FUNC(void, DET_CODE) Det_CanoeOutput( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId ){
#if defined (_MICROSOFT_C_VTT_)

  (void) CANoeAPI_DetReportError(ModuleId, InstanceId, ApiId, ErrorId);
#else

  {
    char str[255];

#if(_MSC_VER >= 1400)
    time_t timeVal;
    struct tm timeS;

    (void) time(&timeVal);
    (void) localtime_s(&timeS, &timeVal);

    (void) strftime(str, sizeof(str), "%H:%M:%S", &timeS);

    (void) sprintf_s(str + strlen(str), sizeof(str) - strlen(str)
   ,      " DET Error: ModuleId 0x%x, InstanceId 0x%x, ApiId 0x%x, ErrorId 0x%x", ModuleId, InstanceId, ApiId, ErrorId);
#   else
    (void) sprintf(str, "DET Error: ModuleId 0x%x, InstanceId 0x%x, ApiId 0x%x, ErrorId 0x%x"
   ,      ModuleId, InstanceId, ApiId, ErrorId);
#endif
    CANoeAPI_WriteString((const char *)str);
  }
#endif
}
#endif

DET_LOCAL FUNC(void, DET_CODE) Det_EndlessLoop(void){
#if(DET_DEBUG_ENABLED == STD_ON)
#if ! defined (DET_REGRESSION_TEST)
  while(detStatus.unlockBreak == FALSE)
#endif
#else
#if ! defined (DET_REGRESSION_TEST)
  while(1)
#endif
#endif
  {
    ;
#if defined (DET_COMP_ANSI_CANOE)
#if(CANOEAPI_VERSION < 200)
            break;
#else
            CANoeAPI_ConsumeTicks(1);
#endif
#endif
  }
#if(DET_DEBUG_ENABLED == STD_ON)
#if ! defined (DET_REGRESSION_TEST)
  detStatus.unlockBreak = FALSE;
#else
  detStatus.unlockBreak = TRUE;
#endif
#endif
}

FUNC(void, DET_CODE) Det_Init( CONSTP2CONST( Det_ConfigType, AUTOMATIC, DET_CONST ) ConfigPtr ){
#if(DET_DEBUG_ENABLED == STD_ON)
#if(DET_GLOBALFILTERSIZE > 0) || (DET_BREAKFILTERSIZE > 0) || (DET_LOGBUFFERSIZE > 0)
  VAR(uint8_least, AUTOMATIC) i;
#endif
  detStatus.globalFilterActive = FALSE;
  detStatus.logActive = FALSE;
  detStatus.logIndex = 0;
  detStatus.breakOnLogOverrun = FALSE;
  detStatus.breakFilterActive = FALSE;
  detStatus.unlockBreak = FALSE;
#if(DET_GLOBALFILTERSIZE > 0)
  for(i = 0; i < DET_GLOBALFILTERSIZE; i++){
    detGlobalFilter[i].mModuleId = 0;
    detGlobalFilter[i].mInstanceId = 0;
    detGlobalFilter[i].mApiId = 0;
    detGlobalFilter[i].mErrorId = 0;
  }
#endif
#if(DET_BREAKFILTERSIZE > 0)
  for(i = 0; i < DET_BREAKFILTERSIZE; i++){
    detBreakFilter[i].mModuleId = 0;
    detBreakFilter[i].mInstanceId = 0;
    detBreakFilter[i].mApiId = 0;
    detBreakFilter[i].mErrorId = 0;
  }
#endif
#if(DET_DLTFILTERSIZE > 0)
  for(i = 0; i < DET_DLTFILTERSIZE; i++){
    detDltFilter[i].mModuleId = 0;
    detDltFilter[i].mInstanceId = 0;
    detDltFilter[i].mApiId = 0;
    detDltFilter[i].mErrorId = 0;
  }
#endif
#if(DET_LOGBUFFERSIZE > 0)
  for(i = 0; i < DET_LOGBUFFERSIZE; i++){
    detLogBuffer[i].mModuleId = 0;
    detLogBuffer[i].mInstanceId = 0;
    detLogBuffer[i].mApiId = 0;
    detLogBuffer[i].mErrorId = 0;
  }
#endif
#endif

#if(DET_REPORT_ERROR_RECURSIONLIMIT > 0)
  detRecursionCounterReportError = 0;
#endif

#if(DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT > 0)
  detRecursionCounterReportRuntimeError = 0;
#endif

#if(DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT > 0)
  detRecursionCounterReportTransientFault = 0;
#endif

  DET_DUMMY_STATEMENT_CONST(ConfigPtr);

  detModuleInit = TRUE;
}

FUNC(void, DET_CODE) Det_Start(void){
}

FUNC(void, DET_CODE) Det_InitMemory(void){
  detModuleInit = FALSE;
}

FUNC(Std_ReturnType, DET_CODE) Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId ){
#if(DET_ERROR_HOOK_ENABLED == STD_ON )
  VAR(Std_ReturnType, AUTOMATIC) calloutReturn = E_OK;
  VAR(uint8_least, AUTOMATIC) index;
#endif
#if(DET_DEBUG_ENABLED == STD_ON)
#if(DET_LOGBUFFERSIZE > 0)
  VAR(boolean, AUTOMATIC) forceBreakHandler;
#endif
#if(DET_GLOBALFILTERSIZE > 0) || (DET_BREAKFILTERSIZE > 0) || (DET_LOGBUFFERSIZE > 0) || ((DET_FORWARD_TO_DLT == STD_ON) && (DET_DLTFILTERSIZE > 0))
  VAR(DetInfoType, AUTOMATIC) detInfo;
  detInfo.mModuleId = ModuleId;
  detInfo.mInstanceId = InstanceId;
  detInfo.mApiId = ApiId;
  detInfo.mErrorId = ErrorId;
#endif
#endif

#if defined (DET_COMP_ANSI_CANOE)

  Det_CanoeOutput(ModuleId, InstanceId, ApiId, ErrorId);
#else
#if(DET_FORWARD_TO_DLT == STD_OFF) && (DET_ERROR_HOOK_ENABLED == STD_OFF ) && ((DET_DEBUG_ENABLED == STD_OFF) || \
    ((DET_DEBUG_ENABLED == STD_ON) && (DET_GLOBALFILTERSIZE==0) && (DET_LOGBUFFERSIZE==0) && (DET_BREAKFILTERSIZE==0)))
  DET_DUMMY_STATEMENT(ModuleId);
  DET_DUMMY_STATEMENT(InstanceId);
  DET_DUMMY_STATEMENT(ApiId);
  DET_DUMMY_STATEMENT(ErrorId);
#endif
#endif

  if(detModuleInit == TRUE){
#if(DET_REPORT_ERROR_RECURSIONLIMIT > 0)
    Det_EnterCritical();
    detRecursionCounterReportError++;
    Det_LeaveCritical();
    if(detRecursionCounterReportError > DET_REPORT_ERROR_RECURSIONLIMIT){
      Det_EndlessLoop();
    }
    else
#endif
    {
#if(DET_ERROR_HOOK_ENABLED == STD_ON )
      for(index = 0; index < Det_GetSizeOfErrorHookTable(); index++)
      {
        calloutReturn = Det_GetErrorHookTable(index)(ModuleId, InstanceId, ApiId, ErrorId);
      }
#endif

#if(DET_FORWARD_TO_DLT == STD_ON)

#if(DET_DEBUG_ENABLED == STD_ON) && (DET_DLTFILTERSIZE > 0)
      if(Det_CheckFilterMatch(detDltFilter, DET_DLTFILTERSIZE, detStatus.dltFilterActive, &detInfo) == FALSE)
#endif
      {
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
      }
#endif

#if(DET_ERROR_HOOK_ENABLED == STD_ON )

      if(calloutReturn == E_OK)
#endif
      {
#if(DET_DEBUG_ENABLED == STD_ON)

#if(DET_GLOBALFILTERSIZE > 0)
        if(Det_CheckFilterMatch(detGlobalFilter, DET_GLOBALFILTERSIZE, detStatus.globalFilterActive, &detInfo) == FALSE)
#endif
        {
#if(DET_LOGBUFFERSIZE > 0)

          forceBreakHandler = Det_LogError(detStatus.logActive, &detInfo);
#endif

#if(DET_BREAKFILTERSIZE > 0)
          if((Det_CheckFilterMatch(detBreakFilter, DET_BREAKFILTERSIZE, detStatus.breakFilterActive, &detInfo) == FALSE)
#if(DET_LOGBUFFERSIZE > 0)
               || (forceBreakHandler == TRUE)
#endif
               )
#endif
          {
            Det_EndlessLoop();
          }
        }
#else

        Det_EndlessLoop();
#endif

      }
    }

#if(DET_REPORT_ERROR_RECURSIONLIMIT > 0)
    Det_EnterCritical();
    detRecursionCounterReportError--;
    Det_LeaveCritical();
#endif
  }

  return E_OK;
}

FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId ){
#if(DET_RUNTIME_ERROR_CALLOUT_ENABLED == STD_ON)
  VAR(Std_ReturnType, AUTOMATIC) calloutReturn = E_OK;
  VAR(uint8_least, AUTOMATIC) index;
#endif
#if(DET_DEBUG_ENABLED == STD_ON)
#if(DET_LOGBUFFERSIZE > 0) || ((DET_FORWARD_TO_DLT == STD_ON) && (DET_DLTFILTERSIZE > 0))
  VAR(DetInfoType, AUTOMATIC) detInfo;
  detInfo.mModuleId = ModuleId;
  detInfo.mInstanceId = InstanceId;
  detInfo.mApiId = ApiId;
  detInfo.mErrorId = ErrorId;
#endif
#endif

#if defined (DET_COMP_ANSI_CANOE)

  Det_CanoeOutput(ModuleId, InstanceId, ApiId, ErrorId);
#else
#if(DET_FORWARD_TO_DLT == STD_OFF) && (DET_RUNTIME_ERROR_CALLOUT_ENABLED == STD_OFF ) && ((DET_DEBUG_ENABLED == STD_OFF) || \
    ((DET_DEBUG_ENABLED == STD_ON) && (DET_LOGBUFFERSIZE==0) ))
  DET_DUMMY_STATEMENT(ModuleId);
  DET_DUMMY_STATEMENT(InstanceId);
  DET_DUMMY_STATEMENT(ApiId);
  DET_DUMMY_STATEMENT(ErrorId);
#endif
#endif

  if(detModuleInit == TRUE){
#if(DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT > 0)
    Det_EnterCritical();
    detRecursionCounterReportRuntimeError++;
    Det_LeaveCritical();
    if(detRecursionCounterReportRuntimeError > DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT){
      Det_EndlessLoop();
    }
    else
#endif
    {
#if(DET_RUNTIME_ERROR_CALLOUT_ENABLED == STD_ON)
      for(index = 0; index < Det_GetSizeOfRuntimeErrorCalloutTable(); index++)
      {
        calloutReturn = Det_GetRuntimeErrorCalloutTable(index)(ModuleId, InstanceId, ApiId, ErrorId);
      }
#endif

#if(DET_FORWARD_TO_DLT == STD_ON)

#if(DET_DEBUG_ENABLED == STD_ON) && (DET_DLTFILTERSIZE > 0)
      if(Det_CheckFilterMatch(detDltFilter, DET_DLTFILTERSIZE, detStatus.dltFilterActive, &detInfo) == FALSE)
#endif
      {
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
      }
#endif

#if(DET_RUNTIME_ERROR_CALLOUT_ENABLED == STD_ON )

      if(calloutReturn == E_OK)
#endif
      {
#if(DET_DEBUG_ENABLED == STD_ON)
#if(DET_LOGBUFFERSIZE > 0)

        (void) Det_LogError(detStatus.logActive, &detInfo);
#endif
#endif
      }
    }

#if(DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT > 0)
    Det_EnterCritical();
    detRecursionCounterReportRuntimeError--;
    Det_LeaveCritical();
#endif
  }

  return E_OK;
}

FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientFault( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId ){
#if(DET_TRANSIENT_FAULT_CALLOUT_ENABLED == STD_ON)
  VAR(Std_ReturnType, AUTOMATIC) calloutReturn = E_OK;
  VAR(uint8_least, AUTOMATIC) index;
#endif
#if(DET_DEBUG_ENABLED == STD_ON)
#if(DET_LOGBUFFERSIZE > 0) || ((DET_FORWARD_TO_DLT == STD_ON) && (DET_DLTFILTERSIZE > 0))
  VAR(DetInfoType, AUTOMATIC) detInfo;
  detInfo.mModuleId = ModuleId;
  detInfo.mInstanceId = InstanceId;
  detInfo.mApiId = ApiId;
  detInfo.mErrorId = ErrorId;
#endif
#endif

#if defined (DET_COMP_ANSI_CANOE)

  Det_CanoeOutput(ModuleId, InstanceId, ApiId, ErrorId);
#else
#if(DET_FORWARD_TO_DLT == STD_OFF) && (DET_TRANSIENT_FAULT_CALLOUT_ENABLED == STD_OFF ) && ((DET_DEBUG_ENABLED == STD_OFF) || \
    ((DET_DEBUG_ENABLED == STD_ON) && (DET_LOGBUFFERSIZE==0) ))
  DET_DUMMY_STATEMENT(ModuleId);
  DET_DUMMY_STATEMENT(InstanceId);
  DET_DUMMY_STATEMENT(ApiId);
  DET_DUMMY_STATEMENT(ErrorId);
#endif
#endif

  if(detModuleInit == TRUE){
#if(DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT > 0)
    Det_EnterCritical();
    detRecursionCounterReportTransientFault++;
    Det_LeaveCritical();
    if(detRecursionCounterReportTransientFault > DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT){
      Det_EndlessLoop();
    }
    else
#endif
    {
#if(DET_TRANSIENT_FAULT_CALLOUT_ENABLED == STD_ON)
      for(index = 0; index < Det_GetSizeOfTransientFaultCalloutTable(); index++)
      {
        calloutReturn = Det_GetTransientFaultCalloutTable(index)(ModuleId, InstanceId, ApiId, ErrorId);
      }
#endif

#if(DET_FORWARD_TO_DLT == STD_ON)

#if(DET_DEBUG_ENABLED == STD_ON) && (DET_DLTFILTERSIZE > 0)
      if(Det_CheckFilterMatch(detDltFilter, DET_DLTFILTERSIZE, detStatus.dltFilterActive, &detInfo) == FALSE)
#endif
      {
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
      }
#endif

#if(DET_DEBUG_ENABLED == STD_ON)
#if(DET_LOGBUFFERSIZE > 0)

      (void) Det_LogError(detStatus.logActive, &detInfo);
#endif
#endif
    }

#if(DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT > 0)
    Det_EnterCritical();
    detRecursionCounterReportTransientFault--;
    Det_LeaveCritical();
#endif
  }

#if(DET_TRANSIENT_FAULT_CALLOUT_ENABLED == STD_ON)

  return calloutReturn;
#else
  return E_OK;
#endif
}

#if(DET_VERSION_INFO_API == STD_ON)
FUNC(void, DET_CODE) Det_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA ) versioninfo ){
  if(versioninfo != NULL_PTR){
    versioninfo->vendorID           = DET_VENDOR_ID;
    versioninfo->moduleID           = DET_MODULE_ID;
    versioninfo->sw_major_version   = DET_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version   = DET_SW_MINOR_VERSION;
    versioninfo->sw_patch_version   = DET_SW_PATCH_VERSION;
  }
  else{
    (void) Det_ReportError(DET_MODULE_ID, DET_INSTANCE_ID, DET_SID_GETVERSIONINFO, DET_E_PARAM_POINTER);
  }
}
#endif

#define DET_STOP_SEC_CODE
#include "MemMap.hpp"

#ifdef __cplusplus
}
#endif
#endif

