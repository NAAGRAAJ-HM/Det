/*****************************************************/
/* File   : Det.cpp                                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "Det.h"

#include "Det_EcuM.h"
#include "Det_SchM.h"

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
class_Det_EcuM Det_EcuM;
class_EcuM_Client *EcuM_Client_ptr_Det = &Det_EcuM;
class_Det_SchM Det_SchM;
class_SchM_Client *SchM_Client_ptr_Det = &Det_SchM;
class_Det Det;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, DET_CODE) class_Det_EcuM::InitFunction(void){
}

FUNC(void, DET_CODE) class_Det::ReportError(void){
}

FUNC(void, DET_CODE) class_Det::Start(void){
}

FUNC(void, DET_CODE) class_Det::GetVersionInfo(void){
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

