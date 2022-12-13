#include "include/libdnd.h"

int main(void)
{
  printf("Hello World");
  printf("\n\t\n\tWOWPADJSDJIASD\n\n\n\n");
  InitWindow(120,120,"TEST");
  SetTargetFPS(60);
  while(!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
  }
}
