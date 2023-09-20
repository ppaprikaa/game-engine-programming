#include "Game.hpp"

void Game::sLifespan()
{
   for (auto e : m_entities.getEntities())
   {
      if (e->cLifespan)
      {
         e->cLifespan->remaining -= 1000;
         if (e->cLifespan->remaining <= 1)
         {
            e->destroy();
         }
      }
   }
}
