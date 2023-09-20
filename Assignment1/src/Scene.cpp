#include "Scene.hpp"
#include "Config.hpp"
#include "ConfigTypes.hpp"
#include "Shape.hpp"
#include "ShapeTextDrawingSystem.hpp"
#include "ShapesDrawingSystem.hpp"
#include "ShapesMovingSystem.hpp"
#include "System.hpp"
#include "WindowCollisionSystem.hpp"
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

void Scene::ApplySystems() 
{
   for (auto system : this->m_systems)
      for(auto & shape : this->m_shapes)
         system->Apply(shape);
}

void Scene::Init()
{

   std::shared_ptr<Systems::System> shapesDrawingSystem = std::make_shared<Systems::ShapeDrawingSystem>(this->m_window);
   this->m_systems.push_back(shapesDrawingSystem);

   std::shared_ptr<Systems::System> shapesMovingSystem = std::make_shared<Systems::ShapesMovingSystem>();
   this->m_systems.push_back(shapesMovingSystem);

   std::shared_ptr<Systems::System> windowCollisionSystem = std::make_shared<Systems::WindowCollisionSystem>(this->m_window);
   this->m_systems.push_back(windowCollisionSystem);

   std::shared_ptr<Systems::System> shapeTextDrawingSystem = std::make_shared<Systems::ShapeTextDrawingSystem>(this->m_window);
   this->m_systems.push_back(shapeTextDrawingSystem);
}

void Scene::Run()
{
   std::shared_ptr<sf::RenderWindow> Window = this->m_window; 
   Window->setFramerateLimit(60);
   sf::Font font;

   if(!font.loadFromFile("fonts/ArialRegular.ttf")) {
      std::cerr << "Couldn't load font" << std::endl;
      exit(1);
   }

   std::shared_ptr<sf::Text> text = std::make_shared<sf::Text>();
   text->setPosition(0, 0);
   text->setString("Assignment 1");
   text->setFillColor(sf::Color(255, 255, 255));
   text->setCharacterSize(24);
   text->setFont(font);

   while(Window->isOpen()) {
      Window->clear();

      sf::Event event;

      this->ApplySystems();
      while(Window->pollEvent(event)) {
         if (event.type == sf::Event::Closed)
            Window->close();
      }

      Window->draw(*text);
      
      Window->display();
   }
}

Scene::Scene(cfg::Config &cfg) 
{
  this->m_window = std::make_shared<sf::RenderWindow>(
      sf::VideoMode(cfg.GetWindowConfig().Width, cfg.GetWindowConfig().Height),
      cfg.GetWindowConfig().Title,
      sf::Style::Titlebar
      );

  sf::Font sf_font;
  sf::Color sf_font_color(
      cfg.GetFontConfig().Color.R, cfg.GetFontConfig().Color.G,
      cfg.GetFontConfig().Color.B
      );

  if (!sf_font.loadFromFile(cfg.GetFontConfig().Filepath)) {
    std::cerr << "Couldn't load font" << std::endl;
    exit(1);
  }

  for (const cfg::RectangleConfig &rect : cfg.GetRectangles()) {
      std::shared_ptr<sf::Shape> sf_shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(rect.Width, rect.Height));
      sf_shape->setFillColor(
      sf::Color(rect.Color.R, rect.Color.G, rect.Color.B)
      );
      sf_shape->setPosition(rect.InitX, rect.InitY);

      std::shared_ptr<sf::Text> sf_text = std::make_shared<sf::Text>();
      sf_text->setFillColor(sf_font_color);
      sf_text->setFont(sf_font);
      sf_text->setString(rect.Name);
      sf_text->setCharacterSize(cfg.GetFontConfig().Size);

      this->m_shapes.push_back(std::make_shared<AShape>(sf_shape, sf_text,
                                    rect.SpeedX, rect.SpeedY));
  }

  for (const cfg::CircleConfig &circle : cfg.GetCircles()) {
      std::shared_ptr<sf::Shape> sf_shape = std::make_shared<sf::CircleShape>(circle.Radius);
      sf_shape->setFillColor(
      sf::Color(circle.Color.R, circle.Color.G, circle.Color.B)
      );

      sf_shape->setPosition(circle.InitX, circle.InitY);

      std::shared_ptr<sf::Text> sf_text = std::make_shared<sf::Text>();
      sf_text->setFillColor(sf_font_color);
      sf_text->setFont(sf_font);
      sf_text->setString(circle.Name);
      sf_text->setCharacterSize(cfg.GetFontConfig().Size);

      this->m_shapes.push_back(std::make_shared<AShape>(sf_shape, sf_text,
                                    circle.SpeedX, circle.SpeedY));
  }
}
