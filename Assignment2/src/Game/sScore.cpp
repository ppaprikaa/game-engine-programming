#include "Game.hpp"

void Game::sScore()
{
   m_text.setString("SCORE: " + std::to_string(m_player->cScore->score));
}
