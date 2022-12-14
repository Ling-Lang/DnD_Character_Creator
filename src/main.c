#define RAYGUI_IMPLEMENTATION
#define GUI_WELCOME_IMPLEMENTATION
#include "include/libdnd.h"
#include "gui_welcome.h"



int main(void)
{
  static int windowHeight = 320;
  static int windowWidth = 920;
  bool Button001Pressed = false;
  InitWindow(windowWidth,windowHeight,"DnD character creator");
  Rectangle Window = (Rectangle){15,25,windowWidth-30, windowHeight-50}; //x,y,width,height
  Rectangle button = (Rectangle){(windowWidth/2)-88,(windowHeight/2)-28,176,56};
  GuiWelcomeState state = InitGuiWelcome();

  SetTargetFPS(60);
  while(!WindowShouldClose())
  {
   int i = checkclose(Button001Pressed);
   if(checkclose(Button001Pressed) == 0)
   {
    return;
   }


    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("u smoll", 10, 10, 20, WHITE);
    GuiDrawRectangle(Window, 10, BLUE, GREEN);
    DrawText("HI FROM LINUX", 40, 50, 20, BLACK);
    draws();
    GuiWelcome(&state);
    Button001Pressed = GuiButton(button, "Test");
    EndDrawing();
  }
}
//Ich mag Pommes