/******************************************************************************/
/* File   : Det.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CfgDet.hpp"
#include "Det_core.hpp"
#include "infDet_Exp.hpp"
#include "infDet_Imp.hpp"

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
      INTERFACES_EXPORTED_DET
      public abstract_module
   ,  public infDetClient
   ,  public class_Det_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
            Std_TypeReturn          IsInitDone{E_NOT_OK};
      const CfgModule_TypeAbstract* lptrCfg{(CfgModule_TypeAbstract*)NULL_PTR};

   public:
      module_Det(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, DET_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, DET_CONFIG_DATA, DET_APPL_CONST) lptrCfgModule
      );
      FUNC(void, DET_CODE) DeInitFunction (void);
      FUNC(void, DET_CODE) MainFunction   (void);
      DET_CORE_FUNCTIONALITIES

      FUNC(Std_TypeReturn, DET_CODE) ReportError(
            uint16 IdModule
         ,  uint8  IdInstance
         ,  uint8  IdApi
         ,  uint8  IdError
      );
};

extern VAR(module_Det, DET_VAR) Det;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, DET_VAR, DET_CONST) gptrinfEcuMClient_Det = &Det;
CONSTP2VAR(infDcmClient,  DET_VAR, DET_CONST) gptrinfDcmClient_Det  = &Det;
CONSTP2VAR(infSchMClient, DET_VAR, DET_CONST) gptrinfSchMClient_Det = &Det;
CONSTP2VAR(infDetClient,  DET_VAR, DET_CONST) gptrDet               = &Det;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Det, DET_VAR) Det(
   {
#if(STD_ON == _ReSIM)
         "Det"
#else
#endif
      ,  DET_AR_RELEASE_VERSION_MAJOR
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
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         if(STD_HIGH){
            lptrCfg = lptrCfgModule;
         }
         else{
            lptrCfg = &PBcfgDet;
         }
      }
      else{
#if(STD_ON == Det_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == Det_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == Det_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  DET_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, DET_CODE) module_Det::DeInitFunction(void){
#if(STD_ON == Det_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == Det_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == Det_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  DET_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, DET_CODE) module_Det::MainFunction(void){
#if(STD_ON == Det_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == Det_InitCheck)
   }
   else{
#if(STD_ON == Det_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  DET_E_UNINIT
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

FUNC(Std_TypeReturn, DET_CODE) module_Det::ReportError(
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

void Det_ReportRuntimeError(void){
}

void Det_ReportTransientFault(void){
}

FUNC(void, DET_CODE) module_Det::Start(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

