#pragma once
#include <string>

struct FontConfig
{
   std::string Filepath = "*.ttf";
   int Size = 14; 
   int R = 255, G = 255, B = 255;

   FontConfig() {}

   FontConfig(std::string FP, int S, int r, int g, int b)
      :  Filepath(FP), Size(S), R(r), B(b), G(g) {}
};
