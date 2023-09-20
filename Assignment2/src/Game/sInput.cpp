#include "Game.hpp"

void Game::sInput()
{
   sf::Event event;

   while(m_window.pollEvent(event))
   {
      for (auto e : m_entities.getEntities(EntityTag::PlayerControlled))
      {
         switch (event.type) {
            case sf::Event::KeyPressed:
               switch (event.key.code) {
                  case sf::Keyboard::W:
                     e->cInput->up = true;
                     break;
                  case sf::Keyboard::S:
                     e->cInput->down = true;
                     break;
                  case sf::Keyboard::A:
                     e->cInput->left = true;
                     break;
                  case sf::Keyboard::D:
                     e->cInput->right = true;
                     break;
                  default: 
                     break;
               }
               break;
            case sf::Event::KeyReleased:
               switch (event.key.code) {
                  case sf::Keyboard::W:
                     e->cInput->up = false;
                     break;
                  case sf::Keyboard::S:
                     e->cInput->down = false;
                     break;
                  case sf::Keyboard::A:
                     e->cInput->left = false;
                     break;
                  case sf::Keyboard::D:
                     e->cInput->right = false;
                     break;
                  default: 
                     break;
               }
               break;
            case sf::Event::MouseMoved:
                     e->cCrosshair->pos = Math::Vec2(event.mouseMove.x, event.mouseMove.y);
            case sf::Event::MouseButtonPressed:
               switch (event.mouseButton.button) {
                  case sf::Mouse::Left:
                     e->cInput->shoot = true;
                     break;
                  default:
                     break;
               }
               break;
            case sf::Event::MouseButtonReleased:
               switch (event.mouseButton.button) {
                  case sf::Mouse::Left:
                     e->cInput->shoot = false;
                     break;
                  default:
                     break;
               }
               break;
            case sf::Event::Closed:
               m_window.close();
               break;
            default:
               break;
         }
      }
   }
}
