#include "Game.hpp"
#include <iostream>
#include <memory>
#include <cmath>

void Game::spawnPlayer()
{
   m_player = m_entities.addEntity(EntityTag::PlayerControlled);
   m_player->cInput = std::make_shared<CInput>();
   m_player->cShape = std::make_shared<CShape>(
         m_PC.ShapeRadius, m_PC.ShapeVertices,
         sf::Color(m_PC.FillR, m_PC.FillG, m_PC.FillB),
         sf::Color(m_PC.OutR, m_PC.OutG, m_PC.OutB),
         m_PC.OutThickness
         );
   m_player->cTransform = std::make_shared<CTransform>(
         Math::Vec2(
            float(m_WC.Width) / 2, 
            float(m_WC.Height) / 2
            ),
         Math::Vec2(0, 0),
         0,
         m_PC.Speed
         );
   m_player->cCollision = std::make_shared<CCollision>(m_PC.CollisionRadius);
   m_player->cCrosshair = std::make_shared<CCrosshair>(Math::Vec2(0, 0));
   m_player->cScore = std::make_shared<CScore>(0);
}

void Game::spawnSmallEnemies(std::shared_ptr<Entity> e)
{
   if (e->tag() == EntityTag::Enemy &&e->cScore && e->cShape && e->cTransform && e->cCollision )
   {
      auto angle = 360 / e->cShape->circle.getPointCount();
      for (size_t i = 0; i < e->cShape->circle.getPointCount(); i++)
      {
         auto small = m_entities.addEntity(EntityTag::SmallEnemy);
         int speed = e->cTransform->speed / 2;
         int colRadius = e->cCollision->radius / 2;
         int shRadius = e->cShape->circle.getRadius() / 2;
         int pointCount =  e->cShape->circle.getPointCount();
         sf::Color fColor = e->cShape->circle.getFillColor();
         sf::Color oColor = e->cShape->circle.getOutlineColor();
         int OT = e->cShape->circle.getOutlineThickness();

         small->cShape = std::make_shared<CShape>(
               shRadius,
               pointCount,
               fColor,
               oColor,
               OT
               );

         Math::Vec2 pos(e->cTransform->pos.x, e->cTransform->pos.y);
         Math::Vec2 velocity(speed * std::cos(angle * i), speed * std::sin(angle * i));
         velocity.normalize();

         small->cCollision = std::make_shared<CCollision>(colRadius);
         small->cTransform = std::make_shared<CTransform>(pos, velocity, 0, speed);
         small->cLifespan = std::make_shared<CLifespan>(m_EC.SmallLifespan);
         small->cScore = std::make_shared<CScore>(e->cScore->score);
      }
   }
}
