#pragma once
/******************************************************************************/
/* File   : ServiceDet.hpp                                                    */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infServiceDet_ServiceNvM_Types.hpp"
#include "CfgServiceDet.hpp"
#include "ServiceDet_core.hpp"
#include "infServiceDet_Exp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_ServiceDet:
      INTERFACES_EXPORTED_SERVICEDET
      public abstract_module
   ,  public infServiceDetClient
   ,  public class_ServiceDet_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
      const ConstServiceDet_Type* lptrConst = (ConstServiceDet_Type*)NULL_PTR;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
   public:
      FUNC(void, SERVICEDET_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, SERVICEDET_CONST,       SERVICEDET_APPL_CONST) lptrConstModule
         ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICEDET_CONFIG_DATA, SERVICEDET_APPL_CONST) lptrCfgModule
      );
      FUNC(void, SERVICEDET_CODE) DeInitFunction (void);
      FUNC(void, SERVICEDET_CODE) MainFunction   (void);
      SERVICEDET_CORE_FUNCTIONALITIES

      FUNC(Std_TypeReturn, SERVICEDET_CODE) ReportError(
            uint16 IdModule
         ,  uint8  IdInstance
         ,  uint8  IdApi
         ,  uint8  IdError
      );
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
extern VAR(module_ServiceDet, SERVICEDET_VAR) ServiceDet;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

