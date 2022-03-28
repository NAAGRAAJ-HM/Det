/******************************************************************************/
/* File   : Det.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.hpp"
#include "CfgDet.hpp"
#include "infDet_EcuM.hpp"
#include "infDet_Dcm.hpp"
#include "infDet_SchM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define DET_AR_RELEASE_MAJOR_VERSION                                           4
#define DET_AR_RELEASE_MINOR_VERSION                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(DET_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
   #error "Incompatible DET_AR_RELEASE_MAJOR_VERSION!"
#endif

#if(DET_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)
   #error "Incompatible DET_AR_RELEASE_MINOR_VERSION!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_Det:
      public abstract_module
{
   public:
      FUNC(void, DET_CODE) InitFunction   (void);
      FUNC(void, DET_CODE) DeInitFunction (void);
      FUNC(void, DET_CODE) GetVersionInfo (void);
      FUNC(void, DET_CODE) MainFunction   (void);

   private:
      CONST(Std_TypeVersionInfo, DET_CONST) VersionInfo = {
            0x0000
         ,  0xFFFF
         ,  0x01
         ,  '0'
         ,  '1'
         ,  '0'
      };
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Det, DET_VAR) Det;
CONSTP2VAR(infEcuMClient, DET_VAR, DET_CONST) gptrinfEcuMClient_Det = &Det;
CONSTP2VAR(infDcmClient,  DET_VAR, DET_CONST) gptrinfDcmClient_Det  = &Det;
CONSTP2VAR(infSchMClient, DET_VAR, DET_CONST) gptrinfSchMClient_Det = &Det;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, DET_CODE) module_Det::InitFunction(void){
   Det.IsInitDone = E_OK;
}

FUNC(void, DET_CODE) module_Det::DeInitFunction(void){
   Det.IsInitDone = E_NOT_OK;
}

FUNC(void, DET_CODE) module_Det::GetVersionInfo(void){
#if(STD_ON == Det_DevErrorDetect)
//TBD: API parameter check
   Det_ReportError(
   );
#endif
}

FUNC(void, DET_CODE) module_Det::MainFunction(void){
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

