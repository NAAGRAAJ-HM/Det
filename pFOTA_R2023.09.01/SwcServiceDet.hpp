#ifndef DET_H
#define DET_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "Std_Types.hpp"
#include "CfgSwcServiceDet.hpp"

#define DET_VENDOR_ID         (1u)
#define DET_MODULE_ID         (15u)

#if !defined (DET_AR_MAJOR_VERSION)
#define DET_AR_MAJOR_VERSION  (4u)
#define DET_AR_MINOR_VERSION  (3u)
#define DET_AR_PATCH_VERSION  (0u)
#endif

#if !defined (DET_AR_RELEASE_MAJOR_VERSION)
#define DET_AR_RELEASE_MAJOR_VERSION  (4u)
#define DET_AR_RELEASE_MINOR_VERSION  (3u)
#define DET_AR_RELEASE_PATCH_VERSION  (0u)
#define DET_AR_RELEASE_REVISION_VERSION  DET_AR_RELEASE_PATCH_VERSION
#endif

#define DET_SW_MAJOR_VERSION  (11u)
#define DET_SW_MINOR_VERSION  (0u)
#define DET_SW_PATCH_VERSION  (0u)

#define DET_E_PARAM_POINTER  (1u)

#define DET_E_CANNOT_REPORT  (1u)
#define DET_E_WRONG_MODULE   (2u)
#define DET_E_WRONG_INSTANCE (3u)
#define DET_E_WRONG_API      (4u)
#define DET_E_WRONG_ERROR    (5u)

#define DET_E_UNAVAILABLE    (1u)

#define DET_SID_INIT                         (0x00u)
#define DET_SID_START                        (0x02u)
#define DET_SID_REPORTERROR                  (0x01u)
#define DET_SID_REPORTRUNTIMEERROR           (0x04u)
#define DET_SID_REPORTTRANSIENTFAULT         (0x05u)
#define DET_SID_GETVERSIONINFO               (0x03u)

#define DET_INSTANCE_ID                      (0x00u)

#if(DET_ENABLED == STD_ON)

#if(DET_DEBUG_ENABLED == STD_ON)

#define DET_DONTCARE_8  (0xFFu)
#define DET_DONTCARE_16 (0xFFFFu)

typedef struct{
  uint16 mModuleId;
  uint8 mInstanceId;
  uint8 mApiId;
  uint8 mErrorId;
}DetInfoType;

typedef struct{
  boolean globalFilterActive;
  boolean logActive;
  boolean breakOnLogOverrun;
  boolean breakFilterActive;
  boolean unlockBreak;
  boolean dltFilterActive;
  uint8 logIndex;
}DetStatusType;

#define DET_START_SEC_VAR_NOINIT_UNSPECIFIED
#   include "MemMap.hpp"

#if(DET_GLOBALFILTERSIZE > 0)

extern volatile VAR(DetInfoType, DET_VAR) detGlobalFilter[DET_GLOBALFILTERSIZE];
#endif
#if(DET_BREAKFILTERSIZE > 0)

extern volatile VAR(DetInfoType, DET_VAR) detBreakFilter[DET_BREAKFILTERSIZE];
#endif
#if(DET_DLTFILTERSIZE > 0)

extern volatile VAR(DetInfoType, DET_VAR) detDltFilter[DET_DLTFILTERSIZE];
#endif
#if(DET_LOGBUFFERSIZE > 0)

extern volatile VAR(DetInfoType, DET_VAR) detLogBuffer[DET_LOGBUFFERSIZE];
#endif

extern volatile VAR(DetStatusType, DET_VAR) detStatus;
#define DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#   include "MemMap.hpp"

#endif

#define DET_START_SEC_CODE
#include "MemMap.hpp"

FUNC(void, DET_CODE) Det_Init( CONSTP2CONST( Det_ConfigType, AUTOMATIC, DET_CONST ) ConfigPtr );
FUNC(void, DET_CODE) Det_Start(void);
FUNC(void, DET_CODE) Det_InitMemory(void);
FUNC(Std_ReturnType, DET_CODE) Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );
FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );
FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientFault( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );

#if(DET_VERSION_INFO_API == STD_ON)
FUNC(void, DET_CODE) Det_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA ) versioninfo );
#endif

#define DET_STOP_SEC_CODE
#include "MemMap.hpp"
#endif

#ifdef __cplusplus
}
#endif
#endif

