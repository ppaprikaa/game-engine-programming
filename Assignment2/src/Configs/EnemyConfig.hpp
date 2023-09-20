#pragma once

struct EnemyConfig
{
   int ShapeRadius = 0, CollisionRadius = 0;
   int MinSpeed = 0, MaxSpeed = 0;
   int OR = 0, OG = 0, OB = 0;
   int OT = 0;
   int MinV = 0, MaxV = 0;
   int SmallLifespan = 0;
   int SpawnInterval = 0;

   EnemyConfig() {}
   EnemyConfig( int SR, int CR, int MinS, int MaxS, int oR, int oG, int oB,
                int ot, int minV, int maxV, int sLifespan, int sInterval ) 
      :        ShapeRadius(SR), CollisionRadius(CR),
               MinSpeed(MinS), MaxSpeed(MaxS),
               OR(oR), OG(oG), OB(oB),
               OT(ot),
               MinV(minV), MaxV(maxV),
               SmallLifespan(sLifespan),
               SpawnInterval(sInterval)
         {}
};
