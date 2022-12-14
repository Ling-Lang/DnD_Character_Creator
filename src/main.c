#include "include/libdnd.h"

int main(void)
{
  printf("Hello World");
  printf("\n\t\n\tWOWPADJSDJIASD\n\n\n\n");
  static int windowHeight = 720;
  static int windowWidth = 720;
  InitWindow(windowHeight,windowWidth,"DnD character creator");
  Rectangle Window = (Rectangle){0,0,windowHeight, windowWidth};

  SetTargetFPS(60);
  while(!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("u smoll", 10, 10, 20, WHITE);
    EndDrawing();
  }
}
