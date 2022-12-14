#ifndef LIBDND_H
# define LIBDND_H
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "raygui.h"

void draws();
int checkclose(bool Button001Pressed, int *windowWidth, int *windowHeight);
#endif