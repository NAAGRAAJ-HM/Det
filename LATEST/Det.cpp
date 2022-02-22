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
   ,  public interface_Det_EcuM
   ,  public interface_Det_SchM
{
   public:
      FUNC(void, DET_CODE) InitFunction   (void);
      FUNC(void, DET_CODE) DeInitFunction (void);
      FUNC(void, DET_CODE) MainFunction   (void);
};

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
module_Det Det;

interface_Det_EcuM *EcuM_Client_ptr_Det = &Det;
interface_Det_SchM *SchM_Client_ptr_Det = &Det;

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

