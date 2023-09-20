#include "Game.hpp"
#include <cmath>

void Game::sCollision()
{
   for (auto e : m_entities.getEntities())
   {
      if (e->cCollision && e->cTransform && e->tag() > EntityTag::Bullet)
      {
         if (e->cTransform->pos.x - e->cCollision->radius < 0)
         {
            e->cTransform->pos.x -= e->cTransform->velocity.x * e->cTransform->speed;
            if (e->tag() >= EntityTag::Enemy)
               e->cTransform->velocity.x *= -1;
         } else if (e->cTransform->pos.x + e->cCollision->radius > m_WC.Width)
         {
            e->cTransform->pos.x -= e->cTransform->velocity.x * e->cTransform->speed;
            if (e->tag() >= EntityTag::Enemy)
               e->cTransform->velocity.x *= -1;
         }

         if (e->cTransform->pos.y - e->cCollision->radius < 0)
         {
            e->cTransform->pos.y -= e->cTransform->velocity.y * e->cTransform->speed;
            if (e->tag() >= EntityTag::Enemy)
               e->cTransform->velocity.y *= -1;
         } else if (e->cTransform->pos.y + e->cCollision->radius > m_WC.Height)
         {
            e->cTransform->pos.y -= e->cTransform->velocity.y * e->cTransform->speed;
            if (e->tag() >= EntityTag::Enemy)
               e->cTransform->velocity.y *= -1;
         }
      }

      for (auto enemy : m_entities.getEntities(EntityTag::Enemy))
      {
         if (enemy->cCollision && enemy->cTransform) 
         {
            if (e->cTransform->pos.dist_sq(enemy->cTransform->pos) < std::pow(e->cCollision->radius + enemy->cCollision->radius, 2))
            {
               if (e->tag() == EntityTag::Bullet && enemy->isActive())
               {
                  spawnSmallEnemies(enemy);
                  m_player->cScore->score += enemy->cScore->score;
                  enemy->destroy();
               }
               if (e->tag() == EntityTag::PlayerControlled && e->isActive())
               {
                  e->destroy();
                  e->cScore->score = 0;
                  spawnPlayer();
               }
            }
         }
      }
   }
}

