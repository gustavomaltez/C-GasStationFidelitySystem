#include <windows.h>

//Recebe os parametros de cor e os utiliza para setar o a atributo de texto do console
//Para um valor que represente uma cor
void colorize(int bgColor, int textColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + bgColor *16));
}
