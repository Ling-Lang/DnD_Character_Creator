#define RAYGUI_IMPLEMENTATION
#define GUI_WELCOME_WINDOW_IMPLEMENTATION
#include "include/libdnd.h"


int main(void)
{
  InitWindow(0, 0, "initializing");

  bool is_active = true;
  bool checked = false;
  int width = GetMonitorWidth(0);
  int height = GetMonitorHeight(0);
  char *clipboard = GetClipboardText();


  startUpWindow(&width, &height);
  SetTargetFPS(60);
  while(!WindowShouldClose())
  {
     
    BeginDrawing();
    ClearBackground(WHITE);
    DrawText("Hello World", 0, 0, 20, WHITE);
    if(is_active)
    {
      init_welcome_window(width, height, &is_active, &checked);
    }
    EndDrawing();
    // printf("is_checked: %d, is_active: %d\n", checked, is_active);
  }
}
