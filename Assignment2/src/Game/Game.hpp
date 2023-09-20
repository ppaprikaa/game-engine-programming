#pragma once
#include "../EntityManager/EntityManager.hpp"
#include "../Configs/GameConfig.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

class Game 
{
   private:
      sf::RenderWindow m_window;
      EntityManager m_entities;
      sf::Font m_font;
      sf::Text m_text;
      
      FontConfig m_FC;
      WindowConfig m_WC;
      PlayerConfig m_PC;
      EnemyConfig m_EC;
      BulletConfig m_BC;

      int m_score = 0;
      int m_currentFrame = 0;   
      int m_lastEnemySpawnTime = 0;
      bool m_paused = false;
      bool m_running = true;

      std::shared_ptr<Entity> m_player;

      void init(const std::string & configPath);
      void setPaused(bool paused);
      
      void sInput();
      void sRender();
      void sMovement();
      void sEnemySpawner();
      void sCollision();
      void sShooting();
      void sLifespan();
      void sScore();

      void spawnPlayer();
      void spawnBullet(std::shared_ptr<Entity> e);
      void spawnSmallEnemies(std::shared_ptr<Entity> e);
   public:
      Game(const std::string & configPath);
      void run();
};
