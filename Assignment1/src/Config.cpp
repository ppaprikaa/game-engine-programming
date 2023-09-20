#include "Config.hpp"
#include "ConfigTypes.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>

cfg::Config::Config()
{}

cfg::Config::Config(const std::string & configFilePath)
{
	std::ifstream fs(configFilePath);
	std::string typeStr;

	cfg::WindowConfig & windowCfg = m_windowConfig;
	cfg::FontConfig & fontCfg = m_fontConfig;

	cfg::RectangleConfig tempRectangle;
	cfg::CircleConfig tempCircle;

	while (fs >> typeStr) 
	{
	switch (cfg::ResolveType(typeStr)) 
	{
		case Window:
			fs >> windowCfg.Title >> windowCfg.Width >> windowCfg.Height;
			break;
		case Font:
			fs >> fontCfg.Filepath >> fontCfg.Size >>
					fontCfg.Color.R >> fontCfg.Color.G >> fontCfg.Color.B;
			break;
		case Rectangle:
			fs >> tempRectangle.Name >> 
					tempRectangle.InitX >> tempRectangle.InitY >>
					tempRectangle.SpeedX >> tempRectangle.SpeedY >>
					tempRectangle.Color.R >> tempRectangle.Color.G >> tempRectangle.Color.B >>
					tempRectangle.Width >> tempRectangle.Height;

			m_rectangleConfigs.push_back(tempRectangle);
			break;
		case Circle:
			fs >> tempCircle.Name >>
			tempCircle.InitX >> tempCircle.InitY >>
			tempCircle.SpeedX >> tempCircle.SpeedY >>
			tempCircle.Color.R >> tempCircle.Color.G >> tempCircle.Color.B >>
			tempCircle.Radius;

			m_circleConfigs.push_back(tempCircle);
			break;
		case Invalid: 
			std::cerr << "Couldn't read option type." << std::endl;
			break;
	}
	}
}

const cfg::WindowConfig & cfg::Config::GetWindowConfig()
{
	return m_windowConfig;
}

const cfg::FontConfig & cfg::Config::GetFontConfig()
{
	return m_fontConfig;
}

const std::vector<cfg::RectangleConfig> & cfg::Config::GetRectangles()
{
	return m_rectangleConfigs;
}

const std::vector<cfg::CircleConfig> & cfg::Config::GetCircles()
{
	return m_circleConfigs;
}
