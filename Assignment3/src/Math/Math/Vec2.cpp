#include "Vec2.hpp"
#include "Math.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

namespace Math {
   Vec2::Vec2() : X(0), Y(0) {}

   Vec2::Vec2(float xin, float yin) : X(xin), Y(yin) {}

   Vec2 Vec2::operator + (const Vec2 & rhs) const 
   {
      return Vec2(X + rhs.X, Y + rhs.Y);
   }

   Vec2 Vec2::operator - (const Vec2 & rhs) const
   {
      return Vec2(X - rhs.X, Y - rhs.Y);
   }

   Vec2 Vec2::operator * (const Vec2 & rhs) const
   {
      return Vec2(X * rhs.X, Y * rhs.Y);
   }

   Vec2 Vec2::operator / (const Vec2 & rhs) const
   {
      return Vec2(X / rhs.X, Y / rhs.Y);
   }

   Vec2 Vec2::operator * (const float scalar) const
   {
      return Vec2(X * scalar, Y * scalar);
   }

   Vec2 Vec2::operator / (const float scalar) const
   {
      return Vec2(X / scalar, Y / scalar);
   }

   void Vec2::operator += (const Vec2 & rhs) 
   {
      this->X += rhs.X;
      this->Y += rhs.Y;
   }

   void Vec2::operator -= (const Vec2 & rhs) 
   {
      this->X -= rhs.X;
      this->Y -= rhs.Y;
   }

   void Vec2::operator *= (const Vec2 & rhs) 
   {
      this->X *= rhs.X;
      this->Y *= rhs.Y;
   }

   void Vec2::operator /= (const Vec2 & rhs) 
   {
      this->X /= rhs.X;
      this->Y /= rhs.Y;
   }

   bool Vec2::operator == (const Vec2 & rhs) const
   {
      return this->X == rhs.X && this->Y == rhs.Y;
   }

   bool Vec2::operator != (const Vec2 & rhs) const
   {
      return this->X != rhs.X || this->Y != rhs.Y;
   }

   Vec2 & Vec2::scale(const float scalar)
   {
      *this = *this * scalar;
      return *this;
   }

   Vec2 & Vec2::normalize()
   {
      float len; 

      len = this->length(); 
      this->X /= len, this->Y /= len;

      return *this;
   }

   float Vec2::dist_sq(const Vec2 & rhs) const
   {
      return (this->X - rhs.X)*(this->X - rhs.X) + (this->Y - rhs.Y)*(this->Y - rhs.Y);
   }

   float Vec2::dist(const Vec2 & rhs) const
   {
      return Math::QuickSqrt(dist_sq(rhs));
   }

   float Vec2::length() const
   {
      return this->dist(Vec2(0.0, 0.0));
   }

   Vec2 Vec2::diff(const Vec2 & rhs) const
   {
      Vec2 result(std::fabs(this->X - rhs.X), std::fabs(this->Y - rhs.Y));
      return result;
   }
}
