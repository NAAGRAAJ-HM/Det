#pragma once
/******************************************************************************/
/* File   : infSwcServiceDetSwcServiceStartUp.h                               */
/*                                                                            */
/* Author : Raajnaag HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* git@github.com:RaajnaagHuliyapuradaMata/<module_name>.git                  */
/*                                                                            */
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
      SwcApplStartUp_eError_None
   ,  SwcApplStartUp_eError_HeaderREAD_FAILED
   ,  SwcApplStartUp_eError_HeaderMAGIC_FAILED
   ,  SwcApplStartUp_eError_HeaderVERSION_FAILED
   ,  SwcApplStartUp_eError_HeaderLENGTH_FAILED
   ,  SwcApplStartUp_eError_VALIDITY_FAILED
   ,  SwcApplStartUp_eError_SWCSERVICESTARTUP_BMHEADER_INCORRECT
   ,  SwcApplStartUp_eError_SWCSERVICESTARTUP_VERIFICATION_FAILED
   ,  SwcApplStartUp_eError_KEY_NOT_AVAILABLE
   ,  SwcApplStartUp_eError_UpdaterSEARCH_INIT_FAILED
   ,  SwcApplStartUp_eError_UpdaterSEARCH_NEXT_FINISHED
   ,  SwcApplStartUp_eError_UpdaterHEADER_ADDRESS
   ,  SwcApplStartUp_eError_UpdaterHEADER_READ_ERROR
   ,  SwcApplStartUp_eError_UpdaterHEADER_CONSISTENCY
   ,  SwcApplStartUp_eError_UpdaterHEADER_TYPE
   ,  SwcApplStartUp_eError_UpdaterBLOCK_VALIDITY
   ,  SwcApplStartUp_eError_UpdaterHEADER_CMAC_READ
   ,  SwcApplStartUp_eError_UpdaterHEADER_CMAC_VERIFY
   ,  SwcApplStartUp_eError_UpdaterVERIFY
   ,  SwcApplStartUp_eError_LoaderPOINTER_NULL
   ,  SwcApplStartUp_eError_LoaderTOO_LARGE
   ,  SwcApplStartUp_eError_LoaderSIZE
   ,  SwcApplStartUp_eError_LoaderGET_MAC
   ,  SwcApplStartUp_eError_LoaderGET_SWCSERVICESTARTUP_MAC
   ,  SwcApplStartUp_eError_ReProgLoaderDESCR
   ,  SwcApplStartUp_eError_ReProgLoaderINVALID
   ,  SwcApplStartUp_eError_ReProgLoaderBMHEADER_INCORRECT
   ,  SwcApplStartUp_eError_ReProgLoaderVERIFY_HEADER
   ,  SwcApplStartUp_eError_ReProgLoaderVERIFY_AREAS
   ,  SwcApplStartUp_eError_ReProgLoaderMAGIC_FLAG
   ,  SwcApplStartUp_eError_ReProgLoaderBLOCK_COUNT
   ,  SwcApplStartUp_eError_TargetLIST_INIT
   ,  SwcApplStartUp_eError_TargetINVALID
   ,  SwcApplStartUp_eError_TargetNO_VALID_HEADER
   ,  SwcApplStartUp_eError_TargetVERIFICATION_FAILED
   ,  SwcApplStartUp_eError_TargetINVALID_ADDRESS
   ,  SwcApplStartUp_eError_TargetDEP_MANDATORY_MISSING
   ,  SwcApplStartUp_eError_TargetDEP_NO_VALID_HEADER
   ,  SwcApplStartUp_eError_TargetDEP_VERIFY_FAILED
   ,  SwcApplStartUp_eError_END_OF_MAIN_REACHED
   ,  SwcApplStartUp_eError_ApplCheckMAC_READ_FAIL
   ,  SwcApplStartUp_eError_ApplCheckMAC_BUF_LENGTH
   ,  SwcApplStartUp_eError_ApplCheckMAC_READ_FAIL_LENGTH
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
