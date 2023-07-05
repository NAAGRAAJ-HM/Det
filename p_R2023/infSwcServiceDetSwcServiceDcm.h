#ifndef _INFSWCSERVICEDETSWCSERVICEDCM_H
#define _INFSWCSERVICEDETSWCSERVICEDCM_H
/******************************************************************************/
/* File   : infSwcServiceDetSwcServiceDcm.h                                   */
/*                                                                            */
/* Author : Raajnaag HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* git@github.com:RaajnaagHuliyapuradaMata/<module_name>.git                  */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_SwcServiceDet.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define DCM_MODULE_ID                                                      0x35
#define DCM_INSTANCE_ID                                                    0x00u
#define DCM_COPYRXDATA_ID                                                  0x8Du
#define DCM_COPYTXDATA_ID                                                  0x9Fu
#define DCM_E_INTERFACE_BUFFER_OVERFLOW                                    0x03u
#define DCM_E_PARAM_POINTER                                                0x07u
#define DCM_E_DCMRXPDUID_RANGE_EXCEED                                      0x20u
#define DCM_E_DCMTXPDUID_RANGE_EXCEED                                      0x21u

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
extern Std_ReturnType Det_ReportError(
      uint16 ModuleId
   ,  uint8  InstanceId
   ,  uint8  ApiId
   ,  uint8  ErrorId
);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
#endif
