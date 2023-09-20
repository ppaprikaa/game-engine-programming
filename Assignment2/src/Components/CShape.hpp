#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <cstddef>

class CShape
{
   public:
      sf::CircleShape circle;

      CShape(
            float radius, int points, 
            const sf::Color & fill, 
            const sf::Color & outline,
            float thickness
            )
         :  circle(radius, points)
      {
         circle.setFillColor(fill);
         circle.setOutlineColor(outline);
         circle.setOutlineThickness(thickness);
         circle.setOrigin(radius, radius);
      }

};
