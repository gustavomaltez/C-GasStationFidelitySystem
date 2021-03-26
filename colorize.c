#include <windows.h>

void colorize(int bgColor, int textColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + bgColor *16));
}
