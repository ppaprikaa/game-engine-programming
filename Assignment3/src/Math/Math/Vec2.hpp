#pragma once
namespace Math {
   struct Vec2
   {
      float X = 0, Y = 0;

      Vec2();
      Vec2(float xin, float yin);

      Vec2 operator + (const Vec2 & rhs) const;
      Vec2 operator - (const Vec2 & rhs) const;
      Vec2 operator * (const Vec2 & rhs) const;
      Vec2 operator / (const Vec2 & rhs) const;

      Vec2 operator * (const float scalar) const;
      Vec2 operator / (const float scalar) const;

      void operator += (const Vec2 & rhs);
      void operator -= (const Vec2 & rhs);
      void operator *= (const Vec2 & rhs);
      void operator /= (const Vec2 & rhs);

      bool operator == (const Vec2 & rhs) const;
      bool operator != (const Vec2 & rhs) const;

      Vec2 & scale(const float scalar);
      Vec2 & normalize();

      float dist_sq(const Vec2 & rhs) const;
      float dist(const Vec2 & rhs) const;

      float length() const;
      Vec2 diff(const Vec2 & rhs) const;
   };
}
