#pragma once

#include "Std_Types.h"
#include "Compiler_Cfg_Det.h"

class class_Det{
   public:
      FUNC(void, DET_CODE) InitFunction   (void);
      FUNC(void, DET_CODE) ReportError    (void);
      FUNC(void, DET_CODE) Start          (void);
      FUNC(void, DET_CODE) GetVersionInfo (void);
};

extern class_Det Det;


