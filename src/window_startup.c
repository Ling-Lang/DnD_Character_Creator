#include "include/libdnd.h"

void startUpWindow()
{
    InitWindow(0, 0, "initializing");
    int w = GetMonitorWidth(0);
    int h = GetMonitorHeight(0);
    int *ratio = getRatio(&w, &h);
    setSize(&w, &h);

    printf("Current monitor: %d\n", GetCurrentMonitor());
    printf("ratio: %d:%d\n", ratio[0], ratio[1]);
    SetWindowTitle("Dungeons and Dragons Character Creator");
}

void setSize(int *width, int *height)
{
    int *ratio = getRatio(width, height);
    if (ratio[0] == 16 && ratio[1] == 9)
    {
        *width = *width *  0.5;
        *height = *height * 0.5;
        SetWindowSize(*width, *height);
        SetWindowPosition((GetMonitorWidth(0) - *width) / 2, (GetMonitorHeight(0) - *height) / 2);
    }
    else
    {
        *width = *width * 0.4;
        *height = *height * 0.4;
        SetWindowSize(*width, *height);
        SetWindowPosition((GetMonitorWidth(0) - *width) / 2, (GetMonitorHeight(0) - *height) / 2);
    }
}

int *getRatio(int *width, int *height)
{
    static int arr[1];
    int GCF = getGCF(*width, *height);
    int a, b;
    a = *width / GCF;
    b = *height / GCF;
    arr[0] = a;
    arr[1] = b;
    // printf("a: %d\tb: %d\tarr: %d", a, b, arr[0]);
    return arr;
}

int getGCF(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    // free(temp);
    // free(b);
    return a;
}