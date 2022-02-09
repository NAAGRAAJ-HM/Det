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
interface_Det_EcuM_Init Det_EcuM_Init;
interface_Det_SchM_Main Det_SchM_Main;
class_Det Det;

interface_EcuM_Init_Client *EcuM_Init_Client_ptr_Det = &Det_EcuM_Init;
interface_SchM_Main_Client *SchM_Main_Client_ptr_Det = &Det_SchM_Main;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, DET_CODE) interface_Det_EcuM_Init::InitFunction(void){
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

