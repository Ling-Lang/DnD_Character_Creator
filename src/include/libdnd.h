#ifndef LIBDND_H
# define LIBDND_H
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "raygui.h"
#include "gui_welcome_window.h"

int *getRatio(int *width, int *height);
void startUpWindow(int *w, int *h);
int getGCF(int a, int b);
void setSize(int *width, int *height);
void init_welcome_window(int width, int height, bool *is_active, bool *checked);
#endif