#include "Game.hpp"

void Game::sEnemySpawner()
{
   if (m_currentFrame % m_EC.SpawnInterval != 0) {
      return;
   }

   auto enemy = m_entities.addEntity(EntityTag::Enemy);
   int points = m_EC.MinV + (rand() % (1 + m_EC.MaxV - m_EC.MinV));
   int R = rand() % 256;
   int G = rand() % 256;
   int B = rand() % 256;
   enemy->cShape = std::make_shared<CShape>(
         float(m_EC.ShapeRadius), points,
         sf::Color(R, G, B),
         sf::Color(m_EC.OR, m_EC.OG, m_EC.OB),
         float(m_EC.OT));

   int speed = m_EC.MinSpeed + (rand() % (1 + m_EC.MaxSpeed - m_EC.MinSpeed));
   Math::Vec2 p = Math::Vec2(
         2 * m_EC.ShapeRadius + float(rand() % (m_WC.Width - 2 * m_EC.ShapeRadius)),
         2 * m_EC.ShapeRadius + float(rand() % (m_WC.Height - 2 * m_EC.ShapeRadius))
         );
   Math::Vec2 v = Math::Vec2(
         float(rand() % (1 + m_WC.Width)),
         float(rand() % (1 + m_WC.Height))
         ).normalize();
   enemy->cTransform = std::make_shared<CTransform>(p, v, 0.f, float(speed));
   enemy->cCollision = std::make_shared<CCollision>(float(m_EC.CollisionRadius));
   enemy->cScore = std::make_shared<CScore>(200);
}
