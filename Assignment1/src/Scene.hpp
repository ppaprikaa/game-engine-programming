#pragma once
#include "Config.hpp"
#include "Shape.hpp"
#include "System.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Window.hpp>
#include <memory>
#include <vector>

class Scene
{
	private:
		std::shared_ptr<sf::RenderWindow> m_window;
		std::vector<std::shared_ptr<AShape>> m_shapes;
      std::vector<std::shared_ptr<Systems::System>> m_systems;

      void ApplySystems();
	public:
		Scene(cfg::Config & cfg);

      void Init();
		void Run();
};
