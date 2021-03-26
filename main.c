#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colorize.h"

void showMenu();

int main()
{   
    showMenu();

    return 0;
}

void showMenu()
{   
    colorize(BLACK, DARK_BLUE);
    printf("           _____              _____ _        _   _                       \n");
    printf("          / ____|            / ____| |      | | (_)                      \n");
    printf("         | |  __  __ _ ___  | (___ | |_ __ _| |_ _  ___  _ __           \n");
    printf("         | | |_ |/ _` / __|  \\___ \\| __/ _` | __| |/ _ \\| '_ \\          \n");
    printf("         | |__| | (_| \\__ \\  ____) | || (_| | |_| | (_) | | | |        \n");
    printf("          \\_____|\\__,_|___/ |_____/ \\__\\__,_|\\__|_|\\___/|_| |_|          \n");
    printf(" ______ _     _      _ _ _            _____           _                 \n");
    printf("|  ____(_)   | |    | (_) |          / ____|         | |                \n");
    printf("| |__   _  __| | ___| |_| |_ _   _  | (___  _   _ ___| |_ ___ _ __ ___  \n");
    printf("|  __| | |/ _` |/ _ \\ | | __| | | |  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ \n");
    printf("| |    | | (_| |  __/ | | |_| |_| |  ____) | |_| \\__ \\ ||  __/ | | | | |\n");
    printf("|_|    |_|\\__,_|\\___|_|_|\\__|\\__, | |_____/ \\__, |___/\\__\\___|_| |_| |_|\n");
    printf("                              __/ |          __/ |                      \n");
    printf("                             |___/          |___/                       \n\n");

    colorize(BLACK, DARK_YELLOW);
    printf("\t   _______________________________________________________ \n");
    printf("\t  |                       M E N U                         |\n");
    printf("\t  |1 - Cadastrar novo cliente.                            |\n");
    printf("\t  |2 - Cadastrar novo veiculo.                            |\n");
    printf("\t  |3 - Adicionar litros abastecidos pelo cliente.         |\n");
    printf("\t  |4 - Verificar total de litros abastecidos pelo cliente.|\n");
    printf("\t  |5 - Resgatar pontos.                                   |\n");
    printf("\t  |0 - Sair.                                              |\n");
    printf("\t  |_______________________________________________________|\n\n");
}
