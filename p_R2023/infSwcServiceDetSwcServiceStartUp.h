#pragma once
/******************************************************************************/
/* File   : infSwcServiceDetSwcServiceStartUp.h                               */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_SwcServiceDet.h"

#include "Types_SwcServiceDet.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define infSwcServiceDetSwcServiceStartUp_dIdInstance_TBD                      0
#define infSwcServiceDetSwcServiceStartUp_dIdApi_TBD                           0

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef enum{
      SwcServiceStartUp_eError_None
   ,  SwcServiceStartUp_eError_HeaderREAD_FAILED
   ,  SwcServiceStartUp_eError_HeaderMAGIC_FAILED
   ,  SwcServiceStartUp_eError_HeaderVERSION_FAILED
   ,  SwcServiceStartUp_eError_HeaderLENGTH_FAILED
   ,  SwcServiceStartUp_eError_VALIDITY_FAILED
   ,  SwcServiceStartUp_eError_SWCSERVICESTARTUP_BMHEADER_INCORRECT
   ,  SwcServiceStartUp_eError_SWCSERVICESTARTUP_VERIFICATION_FAILED
   ,  SwcServiceStartUp_eError_KEY_NOT_AVAILABLE
   ,  SwcServiceStartUp_eError_UpdaterSEARCH_INIT_FAILED
   ,  SwcServiceStartUp_eError_UpdaterSEARCH_NEXT_FINISHED
   ,  SwcServiceStartUp_eError_UpdaterHEADER_ADDRESS
   ,  SwcServiceStartUp_eError_UpdaterHEADER_READ_ERROR
   ,  SwcServiceStartUp_eError_UpdaterHEADER_CONSISTENCY
   ,  SwcServiceStartUp_eError_UpdaterHEADER_TYPE
   ,  SwcServiceStartUp_eError_UpdaterBLOCK_VALIDITY
   ,  SwcServiceStartUp_eError_UpdaterHEADER_CMAC_READ
   ,  SwcServiceStartUp_eError_UpdaterHEADER_CMAC_VERIFY
   ,  SwcServiceStartUp_eError_UpdaterVERIFY
   ,  SwcServiceStartUp_eError_LoaderPOINTER_NULL
   ,  SwcServiceStartUp_eError_LoaderTOO_LARGE
   ,  SwcServiceStartUp_eError_LoaderSIZE
   ,  SwcServiceStartUp_eError_LoaderGET_MAC
   ,  SwcServiceStartUp_eError_LoaderGET_SWCSERVICESTARTUP_MAC
   ,  SwcServiceStartUp_eError_ReProgLoaderDESCR
   ,  SwcServiceStartUp_eError_ReProgLoaderINVALID
   ,  SwcServiceStartUp_eError_ReProgLoaderBMHEADER_INCORRECT
   ,  SwcServiceStartUp_eError_ReProgLoaderVERIFY_HEADER
   ,  SwcServiceStartUp_eError_ReProgLoaderVERIFY_AREAS
   ,  SwcServiceStartUp_eError_ReProgLoaderMAGIC_FLAG
   ,  SwcServiceStartUp_eError_ReProgLoaderBLOCK_COUNT
   ,  SwcServiceStartUp_eError_TargetLIST_INIT
   ,  SwcServiceStartUp_eError_TargetINVALID
   ,  SwcServiceStartUp_eError_TargetNO_VALID_HEADER
   ,  SwcServiceStartUp_eError_TargetVERIFICATION_FAILED
   ,  SwcServiceStartUp_eError_TargetINVALID_ADDRESS
   ,  SwcServiceStartUp_eError_TargetDEP_MANDATORY_MISSING
   ,  SwcServiceStartUp_eError_TargetDEP_NO_VALID_HEADER
   ,  SwcServiceStartUp_eError_TargetDEP_VERIFY_FAILED
   ,  SwcServiceStartUp_eError_END_OF_MAIN_REACHED
   ,  SwcServiceStartUp_eError_ApplCheckMAC_READ_FAIL
   ,  SwcServiceStartUp_eError_ApplCheckMAC_BUF_LENGTH
   ,  SwcServiceStartUp_eError_ApplCheckMAC_READ_FAIL_LENGTH
   ,  SwcServiceStartUp_eError_MissingForcedRCRRP
   ,  SwcServiceStartUp_eError_InitializationFailed
   ,  SwcServiceStartUp_eError_ServiceReqBeforeResp
   ,  SwcServiceStartUp_eError_ServiceMainHandlerInvalid
   ,  SwcServiceStartUp_eError_Det
   ,  SwcServiceStartUp_eError_WdBufferOverflow
   ,  SwcServiceStartUp_eError_ParameterOutOfRange
   ,  SwcServiceStartUp_eError_RepeatedCallOnConcludedService
   ,  SwcServiceStartUp_eError_StateNotIdle
   ,  SwcServiceStartUp_eError_NoBufferAvailable
}Type_infSwcServiceDetSwcServiceStartUp_eIdError;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
extern FUNC(Std_ReturnType, SWCSERVICEDET_CODE) SwcServiceDet_tReportError(
      Type_SwcServiceDet_eIdModule leIdModule
   ,  uint8                        u8IdInstance
   ,  uint8                        leIdApi
   ,  uint8                        leIdError
);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
