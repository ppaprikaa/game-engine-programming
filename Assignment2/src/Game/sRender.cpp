#include "Game.hpp"

void Game::sRender()
{
   m_window.clear(); 
   m_window.draw(m_text);
   for (auto e : m_entities.getEntities())
   {
      if (e->cShape && e->cTransform)
      {
         e->cShape->circle.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);
         if (e->tag() == EntityTag::Enemy)
            e->cShape->circle.setRotation(e->cShape->circle.getRotation() + 5);
         if (e->cLifespan)
         {
            auto color = e->cShape->circle.getFillColor();
            e->cShape->circle.setFillColor(sf::Color(color.r, color.g, color.b, (e->cLifespan->remaining / e->cLifespan->total) * 255));
         }
         m_window.draw(e->cShape->circle);
      }
   }
   m_window.display();
}
