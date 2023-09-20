#pragma once

namespace Math 
{
   struct Vec2
   {
      float x = 0;
      float y = 0;

      Vec2();
      Vec2(float xin, float yin);

      Vec2 operator + (const Vec2 & rhs) const;
      Vec2 operator - (const Vec2 & rhs) const;
      Vec2 operator * (const float scalar) const;
      Vec2 operator * (const Vec2 & rhs) const;
      Vec2 operator / (const float divisor) const;

      void operator += (const Vec2 & rhs);
      void operator -= (const Vec2 & rhs);
      void operator *= (const float scalar);
      void operator /= (const float divisor);

      bool operator == (const Vec2 & rhs) const;
      bool operator != (const Vec2 & rhs) const;

      Vec2 & scale(const float s);
      Vec2 & normalize();

      float dist(const Vec2 & rhs) const;
      float dist_sq(const Vec2 & rhs) const;
      
      float length() const;
      Vec2 diff(const Vec2 & rhs) const;
   };
}

