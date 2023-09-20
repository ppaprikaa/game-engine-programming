#include "Game.hpp"

void Game::spawnBullet(std::shared_ptr<Entity> e)
{
   if (e->cTransform && e->cCrosshair) 
   {
      auto bullet = m_entities.addEntity(EntityTag::Bullet);
      bullet->cShape = std::make_shared<CShape>(
            m_BC.ShapeRadius, m_BC.ShapeVertices,
            sf::Color(m_BC.FillR, m_BC.FillG, m_BC.FillB),
            sf::Color(m_BC.OutR, m_BC.OutG, m_BC.OutB),
            m_BC.OutThickness);
      bullet->cShape->circle.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);
      auto vel = Math::Vec2(e->cCrosshair->pos.x - e->cTransform->pos.x, (e->cTransform->pos.y - e->cCrosshair->pos.y) * -1).normalize();
      bullet->cTransform = std::make_shared<CTransform>(e->cTransform->pos, vel, 0, m_BC.Speed);
      bullet->cCollision = std::make_shared<CCollision>(m_BC.CollisionRadius);
      bullet->cLifespan = std::make_shared<CLifespan>(m_BC.Lifespan);
   }
}

void Game::sShooting()
{
   for (auto e : m_entities.getEntities(EntityTag::PlayerControlled))
   {
      if (e->cTransform && e->cInput && e->cCrosshair) 
      {
         if (e->cInput->shoot) 
         {
            spawnBullet(e);
         }
      }
   }
}
