#include "Game.hpp"
#include <cstdlib>
#include <iostream>
#include <memory>

Game::Game(const std::string & configPath)
{
   init(configPath);
}

void Game::init(const std::string & configPath)
{
   GameConfig gameCfg(configPath);
   m_WC = gameCfg.WC;
   m_PC = gameCfg.PC; 
   m_BC = gameCfg.BC;
   m_EC = gameCfg.EC;
   m_FC = gameCfg.FC;
   
   m_window.create(sf::VideoMode(m_WC.Width, m_WC.Height), "Assignment 2", m_WC.Fullscreen == 0 ? sf::Style::Titlebar : sf::Style::Fullscreen);
   m_window.setFramerateLimit(m_WC.FrameLimit);
   
   if (!m_font.loadFromFile(m_FC.Filepath))
   {
      std::cerr << "Couldn't load font" << std::endl;
      exit(1);
   }

   m_text.setFont(m_font);
   m_text.setCharacterSize(m_FC.Size);
   m_text.setFillColor(sf::Color(m_FC.R, m_FC.G, m_FC.B));
   
   spawnPlayer();
}

void Game::run()
{
   while (m_window.isOpen())
   {
      sEnemySpawner();
      m_currentFrame++;
      m_entities.update();
      sInput();
      sMovement();
      sShooting();
      sCollision();
      sScore();

      sRender();
      sLifespan();
   }
}
