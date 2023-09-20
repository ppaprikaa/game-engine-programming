#include "ConfigTypes.hpp"

cfg::Type cfg::ResolveType(std::string typeString) 
{
	if (typeString == "Window")
		return cfg::Window;
	if (typeString == "Font")
		return cfg::Font;
	if (typeString == "Rectangle")
		return cfg::Rectangle;
	if (typeString == "Circle")
		return cfg::Circle;

	return Invalid;
}