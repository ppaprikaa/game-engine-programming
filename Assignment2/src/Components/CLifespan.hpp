#pragma once
#include <string>

class CLifespan 
{
   public: 
      float remaining = 0;
      float total = 0;

      CLifespan(float t) 
      : total(t), remaining(t) {}
};
