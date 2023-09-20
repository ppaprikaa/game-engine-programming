#pragma once
#include "Shape.hpp"
#include "System.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <SFML/Graphics.hpp>

namespace Systems {
   class ShapeDrawingSystem : public Systems::System
   {
      private:
         std::shared_ptr<sf::RenderWindow> m_window;
      public:
         ShapeDrawingSystem(std::shared_ptr<sf::RenderWindow> window)
            : m_window(window)
         {}

         void Apply(std::shared_ptr<AShape> shape) override 
         {
            if (shape->GetSfShape()) {
               this->m_window->draw(*shape->GetSfShape());
            }
         };
   };
}
