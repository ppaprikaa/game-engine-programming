#pragma once
#include "../Math/Vec2.hpp"

class CTransform
{
   public:
      Math::Vec2 pos = {0.0, 0.0};
      Math::Vec2  velocity = {0.0, 0.0};
      float angle = 0;
      float speed = 0;

      CTransform(const Math::Vec2 & p, const Math::Vec2 & v,float a, float s)
         :  pos(p), velocity(v), angle(a), speed(s)
      {}
};
