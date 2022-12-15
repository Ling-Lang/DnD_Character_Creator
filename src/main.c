#define RAYGUI_IMPLEMENTATION
#define GUI_WELCOME_IMPLEMENTATION
#include "include/libdnd.h"




int main(void)
{
  startUpWindow();
  SetTargetFPS(60);
  while(!WindowShouldClose())
  {

    BeginDrawing();
    ClearBackground(BLACK);

    EndDrawing();
  }
}
//Ich mag Pommes