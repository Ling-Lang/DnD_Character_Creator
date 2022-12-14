#include "include/libdnd.h"
#include "include/raylib.h"

int main(void)
{
  static int windowHeight = 720;
  static int windowWidth = 720;
  bool Button001Pressed = false;
  InitWindow(windowHeight,windowWidth,"DnD character creator");
  Rectangle Window = (Rectangle){0,0,windowHeight-30, windowWidth -50};
  Rectangle button = (Rectangle){200,300,176,56};

  SetTargetFPS(60);
  while(!WindowShouldClose())
  {
   int i = checkclose(Button001Pressed);
   if(i = 0)
      return;


    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("u smoll", 10, 10, 20, WHITE);
    GuiDrawRectangle(Window, 10, BLUE, GREEN);
    DrawText("HI FROM LINUX", 40, 50, 20, BLACK);
    Button001Pressed = GuiButton(button, "Test");
    EndDrawing();
  }
}
