#include "Vec2.hpp"
#include "q_rsqrt.hpp"
#include <cmath>
#include <math.h>

using namespace Math;

Vec2::Vec2() {}

Vec2::Vec2(float xin, float yin)
   : x(xin),
     y(yin)
{}

Vec2 Vec2::operator + (const Vec2 & rhs) const
{
   return Vec2(this->x + rhs.x, this->y + rhs.y);
}

Vec2 Vec2::operator - (const Vec2 & rhs) const
{
   return Vec2(this->x - rhs.x, this->y - rhs.y);
}

Vec2 Vec2::operator * (const float scalar) const
{
   return Vec2(this->x * scalar, this->y * scalar);
}

Vec2 Vec2::operator * (const Vec2 & rhs) const
{
   return Vec2(this->x * rhs.x, this->y * rhs.y);
}

Vec2 Vec2::operator / (const float divisor) const
{
   return  Vec2(this->x / divisor, this->y / divisor);
}

void Vec2::operator += (const Vec2 & rhs)
{
   this->x += rhs.x;
   this->y += rhs.y;
}

void Vec2::operator -= (const Vec2 & rhs)
{
   this->x -= rhs.x;
   this->y -= rhs.y;
}

void Vec2::operator *= (const float scalar)
{
   this->x *= scalar;
   this->y *= scalar;
}

void Vec2::operator /= (const float divisor)
{
   this->x /= divisor;
   this->y /= divisor;
}

bool Vec2::operator == (const Vec2 & rhs) const
{
   return this->x == rhs.x && this->y == rhs.y;
}

bool Vec2::operator != (const Vec2 & rhs) const
{
   return this->x != rhs.x || this->y != rhs.y;
}


float Vec2::dist_sq(const Vec2 & rhs) const
{
   return (this->x - rhs.x)*(this->x - rhs.x)  + (this->y - rhs.y)*(this->y - rhs.y);
}


float Vec2::dist(const Vec2 & rhs) const
{
   return 1 / Math::Q_rsqrt(dist_sq(rhs));
}

Vec2 & Vec2::scale(const float s)
{
   this->x *= s;
   this->y *= s;
   return *this;
}

Vec2 & Vec2::normalize()
{
   float dist = this->dist(Vec2(0, 0));
   this->x /= dist;
   this->y /= dist;
   return *this;
}

float Vec2::length() const 
{
   return this->dist(Vec2(0.0, 0.0));
}

