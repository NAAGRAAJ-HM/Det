/******************************************************************************/
/* File   : Det.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "infDet_EcuM.hpp"
#include "infDet_Dcm.hpp"
#include "infDet_SchM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define DET_AR_RELEASE_VERSION_MAJOR                                           4
#define DET_AR_RELEASE_VERSION_MINOR                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(DET_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible DET_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(DET_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible DET_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_Det:
      public abstract_module
{
   public:
      module_Det(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, DET_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, DET_CONFIG_DATA, DET_APPL_CONST) lptrCfgModule
      );
      FUNC(void, DET_CODE) DeInitFunction (void);
      FUNC(void, DET_CODE) MainFunction   (void);
};

extern VAR(module_Det, DET_VAR) Det;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, DET_VAR, DET_CONST) gptrinfEcuMClient_Det = &Det;
CONSTP2VAR(infDcmClient,  DET_VAR, DET_CONST) gptrinfDcmClient_Det  = &Det;
CONSTP2VAR(infSchMClient, DET_VAR, DET_CONST) gptrinfSchMClient_Det = &Det;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/
#include "CfgDet.hpp"

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Det, DET_VAR) Det(
   {
         DET_AR_RELEASE_VERSION_MAJOR
      ,  DET_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, DET_CODE) module_Det::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, DET_CONFIG_DATA, DET_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Det_InitCheck)
   if(E_OK == IsInitDone){
#if(STD_ON == Det_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == Det_DevErrorDetect)
         Det_ReportError(
         );
#endif
      }
      else{
         if(STD_LOW){
// check lptrCfgModule for memory faults
            lptrCfg = lptrCfgModule;
         }
         else{
// use PBcfgCanIf as back-up configuration
            lptrCfg = &PBcfgDet;
         }
      }
      IsInitDone = E_OK;
#if(STD_ON == Det_InitCheck)
   }
#endif
}

FUNC(void, DET_CODE) module_Det::DeInitFunction(void){
#if(STD_ON == Det_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == Det_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
      IsInitDone = E_NOT_OK;
#if(STD_ON == Det_InitCheck)
   }
#endif
}

FUNC(void, DET_CODE) module_Det::MainFunction(void){
#if(STD_ON == Det_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == Det_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
#if(STD_ON == Det_InitCheck)
   }
#endif
}

void Det_ReportError(void){
}

void Det_ReportRuntimeError(void){
}

void Det_ReportTransientFault(void){
}

class class_Det_Unused{
   public:
      FUNC(void, DET_CODE) ReportError    (void);
      FUNC(void, DET_CODE) Start          (void);
};

FUNC(void, DET_CODE) class_Det_Unused::ReportError(void){
}

FUNC(void, DET_CODE) class_Det_Unused::Start(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

