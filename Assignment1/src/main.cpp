#include "Config.hpp"
#include "ConfigTypes.hpp"
#include "Scene.hpp"
#include "Shape.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <memory>
#include <vector>

int main(int argc, char *argv[]) 
{
   cfg::Config cfg("src/config.txt");
   Scene scene(cfg);

   scene.Init();
   std::cout << "Starting game" << std::endl;
   scene.Run();

   return 0;
}
