#pragma once
#include "Shape.hpp"
#include "System.hpp"
#include <memory>

namespace Systems {
   class ShapesMovingSystem : public Systems::System {
      public:
         void Apply(std::shared_ptr<AShape> shape) override
         {
            shape->Move();
         }
   };
}
