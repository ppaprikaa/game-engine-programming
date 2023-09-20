#pragma once
#include <string>

namespace cfg 
{
	enum Type
	{
		Invalid,
		Window,
		Font,
		Rectangle,
		Circle
	};

	Type ResolveType(std::string typeString);

	struct WindowConfig 
	{
		public:
			std::string Title = "Window";
			int Width = 800;
			int Height = 600;

			WindowConfig()
			{}

			WindowConfig(std::string title, int width, int height)
			: 	Title(title),
				Width(width),
				Height(height)
			{}
	};

	struct ColorConfig 
	{
		public:
			unsigned int R = 0;
			unsigned int G = 0;
			unsigned int B = 0;

			ColorConfig()
			{}

			ColorConfig(unsigned int R, unsigned int G, unsigned int B)
			: R(R),
			G(G),
			B(B)
			{}
	};

	struct FontConfig 
	{
		public:
				std::string Filepath = "fonts/ArialRegular.ttf";
				unsigned int Size = 14; 
				ColorConfig Color = ColorConfig(255, 255, 255);

				FontConfig()
				{}

				FontConfig(std::string filepath, unsigned int size, ColorConfig color)
				: Filepath(filepath),
					Size(size),
					Color(color)
				{}
	};

	struct RectangleConfig 
	{
		public:
			std::string Name = "Rectangle";
			float InitX, InitY = 0.0f;
			float SpeedX, SpeedY = 0.0f; 
			ColorConfig Color = ColorConfig();
			float Width = 0.0f, Height = 0.0f;

			RectangleConfig()
			{}

			RectangleConfig(
					std::string name, 
					float initX, float initY, 
					float speedX, float speedY,
					ColorConfig color,
					float width, float height
			) : Name(name),
					InitX(initX),
					InitY(initY),
					SpeedX(speedX),
					SpeedY(speedY),
					Color(color),
					Width(width), Height(height)
			{}
	};

	struct CircleConfig 
	{
		public:
			std::string Name = "Rectangle";
			float InitX, InitY = 0.0f;
			float SpeedX, SpeedY = 0.0f; 
			ColorConfig Color = ColorConfig();
			float Radius = 0.0f;

			CircleConfig()
			{}

			CircleConfig(
					std::string name, 
					float initX, float initY, 
					float speedX, float speedY,
					ColorConfig color,
					float radius
			) : Name(name),
					InitX(initX),
					InitY(initY),
					SpeedX(speedX),
					SpeedY(speedY),
					Color(color),
					Radius(radius)
			{}
	};
}