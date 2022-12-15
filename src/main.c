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
    DrawText("Hello World", 0, 0, 20, WHITE);
    EndDrawing();
  }
}
//Ich mag Pommes