/******************************************************************************/
/* File   : ServiceDet.cpp                                                    */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "ServiceDet.hpp"
#include "infServiceDet_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infServiceDetClient,  SERVICEDET_VAR, SERVICEDET_CONST) gptrServiceDet = &ServiceDet;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_ServiceDet, SERVICEDET_VAR) ServiceDet;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, SERVICEDET_CODE) module_ServiceDet::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, SERVICEDET_CONST,       SERVICEDET_APPL_CONST) lptrNvMBlocksRomModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICEDET_CONFIG_DATA, SERVICEDET_APPL_CONST) lptrCfgModule
){
#if(STD_ON == ServiceDet_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrNvMBlocksRomModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrNvMBlocksRom = lptrNvMBlocksRomModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == ServiceDet_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == ServiceDet_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == ServiceDet_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICEDET_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICEDET_CODE) module_ServiceDet::DeInitFunction(
   void
){
#if(STD_ON == ServiceDet_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == ServiceDet_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == ServiceDet_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICEDET_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICEDET_CODE) module_ServiceDet::MainFunction(
   void
){
#if(STD_ON == ServiceDet_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == ServiceDet_InitCheck)
   }
   else{
#if(STD_ON == ServiceDet_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICEDET_E_UNINIT
      );
#endif
   }
#endif
}

#if(STD_ON == _ReSIM)
#include <iostream>
using namespace std;
#else
#endif

FUNC(Std_TypeReturn, SERVICEDET_CODE) module_ServiceDet::ReportError(
      uint16 IdModule
   ,  uint8  IdInstance
   ,  uint8  IdApi
   ,  uint8  IdError
){
#if(STD_ON == _ReSIM)
   cout<<endl<<"Development error reported";
   cout<<endl<<"IdModule   = "<<IdModule;
   cout<<endl<<"IdInstance = "<<IdInstance;
   cout<<endl<<"IdApi      = "<<IdApi;
   cout<<endl<<"IdError    = "<<IdError;
#else
#endif
   return E_OK;
}

void ServiceDet_ReportRuntimeError(
   void
){
}

void ServiceDet_ReportTransientFault(
   void
){
}

FUNC(void, SERVICEDET_CODE) module_ServiceDet::Start(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

