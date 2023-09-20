#pragma once

struct WindowConfig
{
   int Width = 800;
   int Height = 600;
   int FrameLimit = 60;
   int Fullscreen = 0;

   WindowConfig() {}
   WindowConfig(int W, int H, int FL, int FS)
      : Width(W), Height(H), FrameLimit(FL), Fullscreen(FS) {}
};
