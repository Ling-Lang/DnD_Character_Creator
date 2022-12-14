#include "include/libdnd.h"

int checkclose(bool Button001Pressed, int *windowWidth, int *windowHeight)
{
    if(Button001Pressed)
    {
        *windowWidth *= 2;
        *windowHeight *= 2;
    }
}
void draws()
{
    DrawCircle(123, 133, 50, BLACK);
}