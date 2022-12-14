#define RAYGUI_IMPLEMENTATION
#define GUI_WELCOME_IMPLEMENTATION
#include "include/libdnd.h"
#include "gui_welcome.h"



int main(void)
{
  int windowHeight = 320;
  int windowWidth = 920;
  InitWindow(windowWidth,windowHeight,"DnD character creator");

  SetTargetFPS(60);
  while(!WindowShouldClose())
  {

    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }
}
//Ich mag Pommes