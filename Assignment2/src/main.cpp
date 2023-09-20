#include "EntityManager/EntityManager.hpp"
#include "Game/Game.hpp"
#include "Math/Vec2.hpp"
#include "Entities/Entity.hpp"
#include "Entities/Tag.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main(int argc, char * argv[])
{    
   Game game("configuration/config.txt");
   game.run();

   return 0;
}
