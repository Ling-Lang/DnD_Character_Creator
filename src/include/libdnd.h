#ifndef LIBDND_H
# define LIBDND_H
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "raygui.h"

int *getRatio(int *width, int *height);
void startUpWindow();
int getGCF(int a, int b);
void setSize(int *width, int *height);
#endif