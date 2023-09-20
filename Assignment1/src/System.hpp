#pragma once

#include "Shape.hpp"
#include <memory>

namespace Systems {
   class System 
   {
      public:
         virtual void Apply(std::shared_ptr<AShape> shape) = 0;
   };
};
