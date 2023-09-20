#pragma once
#include "Shape.hpp"
#include "System.hpp"
#include <memory>
#include <SFML/Graphics.hpp>

namespace Systems {
   class ShapeTextDrawingSystem : public Systems::System
   {
      private:
         std::shared_ptr<sf::RenderWindow> m_window;
      public:
         ShapeTextDrawingSystem(std::shared_ptr<sf::RenderWindow> window)
            : m_window(window)
         {}

         void Apply(std::shared_ptr<AShape> shape) override 
         {
            if(shape->GetSfText()) {
               this->m_window->draw(*shape->GetSfText());
            }
         };
   };
}
