#include "include/libdnd.h"

static void Button002(bool *is_active, bool *checked);
void init_welcome_window(int width, int height, bool *is_active, bool *checked)
{
    int windowWidth = 504;
    int windowHeight = 240;
    
    bool WindowBox000Active = true;
    bool TextmultiBox003EditMode = false;
    char TextmultiBox003Text[128] = "SAMPLE TEXT";


    printf("width - windowidth: %d\n", width - windowWidth);
    printf("height - windowHeight: %d\n", height - windowHeight);

    Rectangle WindowBox = (Rectangle){ (width - windowWidth) / 2, (height - windowHeight) / 2, windowWidth, windowHeight };
    Rectangle CheckBox = (Rectangle){ 424 - ((width - windowWidth) / 2) + 48, 344 + 12, 24, 24 };
    Rectangle Button = (Rectangle){ 744 - ((width - windowWidth) / 2) + 60, 344 + 12, 120, 24 };
    Rectangle Label = (Rectangle){ 448, 184, 120, 24 };
    Rectangle Label_2 = (Rectangle){ 448, 224, 400, 112 };
 

    if (WindowBox000Active)
    {
        WindowBox000Active = !GuiWindowBox(WindowBox, "Welcome to DnD Character Creator");
        *checked = GuiCheckBox(CheckBox, "SAMPLE TEXT", *checked);
        if(GuiButton(Button, "SAMPLE TEXT")) Button002(&*is_active, &*checked);
        GuiLabel(Label, "SAMPLE TEXT");
        GuiLabel(Label_2, "SAMPLE TEXT\n\nasdasdasd");
    }    
}

static void Button002(bool *is_active, bool *checked)
{
    if (*checked)
    {
        *is_active = false;
        printf("Button002 pressed");
    }
    // *is_active = false;
    // printf("Button002 pressed");
}