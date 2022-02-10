/*****************************************************/
/* File   : Det.cpp                                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "module.h"

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
class module_Det : public class_module{
   public:
      FUNC(void, DET_CODE) InitFunction   (void);
      FUNC(void, DET_CODE) DeInitFunction (void);
      FUNC(void, DET_CODE) MainFunction   (void);
};

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
module_Det Det;

interface_EcuM_Client *EcuM_Client_ptr_Det = &Det;
interface_SchM_Client *SchM_Client_ptr_Det = &Det;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, DET_CODE) module_Det::InitFunction(void){
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

