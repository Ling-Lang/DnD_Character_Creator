#include "include/libdnd.h"

int checkclose(bool Button001Pressed)
{
    if(Button001Pressed)
        return 0;
    return 1;
}
void draws()
{
    DrawCircle(123, 133, 50, BLACK);
}