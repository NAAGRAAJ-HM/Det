/*****************************************************/
/* File   : Det.cpp                                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "module.h"
#include "Det_EcuM.h"
#include "Det_SchM.h"
#include "Det_Unused.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class module_Det:
      public abstract_module
{
   public:
      FUNC(void, DET_CODE) InitFunction   (void);
      FUNC(void, DET_CODE) DeInitFunction (void);
      FUNC(void, DET_CODE) MainFunction   (void);
};

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
module_Det     Det;
infEcuMClient* gptrinfEcuMClient_Det = &Det;
infSchMClient* gptrinfSchMClient_Det = &Det;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, DET_CODE) module_Det::InitFunction(void){
}

FUNC(void, DET_CODE) module_Det::DeInitFunction(void){
}

FUNC(void, DET_CODE) module_Det::MainFunction(void){
}

FUNC(void, DET_CODE) class_Det_Unused::ReportError(void){
}

FUNC(void, DET_CODE) class_Det_Unused::Start(void){
}

FUNC(void, DET_CODE) class_Det_Unused::GetVersionInfo(void){
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

