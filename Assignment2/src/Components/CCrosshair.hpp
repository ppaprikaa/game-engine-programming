#pragma once
#include "../Math/Vec2.hpp"

class CCrosshair
{
   public:
      Math::Vec2 pos;
      CCrosshair(Math::Vec2 p) : pos(p) {}
};
