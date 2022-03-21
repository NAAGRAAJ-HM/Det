/******************************************************************************/
/* File   : Det.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.h"
#include "infDet_Version.h"
#include "infDet_EcuM.h"
#include "infDet_Dcm.h"
#include "infDet_SchM.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

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
}

FUNC(void, DET_CODE) module_Det::MainFunction(void){
}

#include "Det_Unused.h"

FUNC(void, DET_CODE) class_Det_Unused::ReportError(void){
}

FUNC(void, DET_CODE) class_Det_Unused::Start(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

