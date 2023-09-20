#pragma once
#include "WindowConfig.hpp"
#include "FontConfig.hpp"
#include "PlayerConfig.hpp"
#include "EnemyConfig.hpp"
#include "BulletConfig.hpp"

#include <fstream>

namespace Config 
{
   enum ConfigType
   {
      Default,
      Window,
      Font,
      Player,
      Bullet,
      Enemy
   };

   ConfigType ParseType(std::string typeStr);
};

struct GameConfig
{
   WindowConfig WC;
   FontConfig FC;
   PlayerConfig PC;
   BulletConfig BC;
   EnemyConfig EC;

   GameConfig(const std::string & filepath);
};
