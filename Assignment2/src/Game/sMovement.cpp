#include "Game.hpp"

void Game::sMovement()
{
   for (auto e : m_entities.getEntities())
   {
      if (e->cTransform) 
      {
         if (e->cInput)
         {
            e->cTransform->velocity = {0, 0};

            if (e->cInput->down && e->cInput->up)
               e->cTransform->velocity.y = 0.f;
            else if (e->cInput->up)
               e->cTransform->velocity.y = -1.f;
            else if (e->cInput->down)
               e->cTransform->velocity.y = 1.f;

            if (e->cInput->left && e->cInput->right)
               e->cTransform->velocity.x = 0.f;
            else if (e->cInput->left)
               e->cTransform->velocity.x = -1.f;
            else if (e->cInput->right)
               e->cTransform->velocity.x = 1.f;
         }

         e->cTransform->pos += e->cTransform->velocity.normalize() * e->cTransform->speed;     
      }
   }
}
