#include "Math.hpp"

// source: https://thatonegamedev.com/math/fast-square-root-quake-iii/
float Math::QuickInverseSqrt(const float x)
{
    union {
        float localX, result;
        int integerRepresentation;
    };

    localX = x;
    const int K_correction = 0x5f3759df;
    integerRepresentation = K_correction - (integerRepresentation >> 1);
    result = localX * (1.5f - (x * 0.5) * (localX * localX));
    
    return result;
}

float Math::QuickSqrt(const float n)
{
   return n * QuickInverseSqrt(n);
}
