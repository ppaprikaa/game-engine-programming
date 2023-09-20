#pragma once

struct PlayerConfig
{
   int ShapeRadius = 0;
   int CollisionRadius = 0;
   float Speed = 0;
   int FillR = 0, FillG = 0, FillB = 0; 
   int OutR = 255, OutG = 255, OutB = 255;
   int OutThickness = 0;
   int ShapeVertices = 3;

   PlayerConfig() {}
   PlayerConfig(
         int SR, int CR, 
         int S, 
         int FR, int FG, int FB, 
         int OR, int OG, int OB, 
         int OT,
         int SV
         ) 
      :  ShapeRadius(SR), CollisionRadius(CR),
         Speed(S),
         FillR(FR), FillG(FG), FillB(FB),
         OutR(OR), OutG(OG), OutB(OB),
         OutThickness(OT),
         ShapeVertices(SV)
   {}
};
