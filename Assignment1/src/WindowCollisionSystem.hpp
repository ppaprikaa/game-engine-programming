#pragma once
#include "Shape.hpp"
#include "System.hpp"
#include <SFML/Window/Window.hpp>
#include <memory>

namespace Systems {
   class WindowCollisionSystem : public Systems::System
   {
      private:
         std::shared_ptr<sf::RenderWindow> m_window;
      public:
         WindowCollisionSystem(std::shared_ptr<sf::RenderWindow> window)
            : m_window(window)
         {}

         void Apply(std::shared_ptr<AShape> shape) override 
         {
            if (shape->CollidesX(
                     0,
                     this->m_window->getSize().x)
               )
               shape->ReverseXSpeed();
            if (shape->CollidesY(
                     0,
                     this->m_window->getSize().y)
               )
               shape->ReverseYSpeed();
         };
   };
}

