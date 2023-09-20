#pragma once
#include "Shape.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include "ConfigTypes.hpp"


namespace cfg {
	class Config 
	{
		private:
			cfg::WindowConfig m_windowConfig = cfg::WindowConfig();  
			cfg::FontConfig m_fontConfig = cfg::FontConfig();
			std::vector<cfg::RectangleConfig> m_rectangleConfigs;
			std::vector<cfg::CircleConfig> m_circleConfigs;
		public:
			Config();
			Config(const std::string & configFilePath);

			const cfg::WindowConfig & GetWindowConfig();
			const cfg::FontConfig & GetFontConfig();
			const std::vector<cfg::RectangleConfig> & GetRectangles();
			const std::vector<cfg::CircleConfig> & GetCircles();
	};
};
