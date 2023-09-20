#include "GameConfig.hpp"
#include <fstream>
#include <iostream>
#include <string>

Config::ConfigType  Config::ParseType(std::string typeStr)
{
   if (typeStr == "Window")
      return Config::Window;
   if (typeStr == "Font")
      return Config::Font;
   if (typeStr == "Player")
      return Config::Player;
   if (typeStr == "Bullet")
      return Config::Bullet;
   if (typeStr == "Enemy")
      return Config::Enemy;
   return Default;
}

GameConfig::GameConfig(const std::string & filepath)
{
   std::ifstream fs(filepath);
   std::string configTypeStr;

   while(fs >> configTypeStr)
   {
      switch (Config::ParseType(configTypeStr)) {
         case Config::Window:
            fs >> WC.Width >> WC.Height >> WC.FrameLimit >> WC.Fullscreen;
            std::cout << "[window config loaded]" << std::endl;
            break;
         case Config::Font:
            fs >> FC.Filepath >> FC.Size >> FC.R >> FC.G >> FC.B;
            std::cout << "[font config loaded]" << std::endl;
            break;
         case Config::Player:
            fs >> PC.ShapeRadius >> PC.CollisionRadius >> PC.Speed >>
               PC.FillR >> PC.FillG >> PC.FillB >>
               PC.OutR >> PC.OutG >> PC.OutB >>
               PC.OutThickness >> PC.ShapeVertices;
            std::cout << "[player config loaded]" << std::endl;
            break;
         case Config::Bullet:
            fs >> BC.ShapeRadius >> BC.CollisionRadius >>
               BC.Speed >>
               BC.FillR >> BC.FillG >> BC.FillB >>
               BC.OutR >> BC.OutG >> BC.OutB >>
               BC.OutThickness >>
               BC.ShapeVertices >> BC.Lifespan;
            std::cout << "[bullet config loaded]" << std::endl;
            break;
         case Config::Enemy:
            fs >> EC.ShapeRadius >> EC.CollisionRadius >> 
               EC.MinSpeed >> EC.MaxSpeed >>
               EC.OR >> EC.OG >> EC.OB >> EC.OT >>
               EC.MinV >> EC.MaxV >>
               EC.SmallLifespan >> EC.SpawnInterval;
            std::cout << "[enemy config loaded]" << std::endl;
            break;
         default:
            std::cerr << "Unexpected config type: " << configTypeStr << std::endl;
      }
   }
}
