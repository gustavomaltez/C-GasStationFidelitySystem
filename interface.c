#include <stdio.h>
#include <stdlib.h>
#include "colorize.h"
#include "middlewares.h"
#include "interface.h"
#include <string.h>

// Mostra a tela inicial do sistema
void showMenu()
{
    system("cls");
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
    printf("\t  _______________________________________________________ \n");
    printf("\t |                       M E N U                         |\n");
    printf("\t |1 - Cadastrar novo cliente.                            |\n");
    printf("\t |2 - Cadastrar novo veiculo.                            |\n");
    printf("\t |3 - Abastecer veiculo.                                 |\n");
    printf("\t |4 - Consultar total de litros abastecidos por cliente. |\n");
    printf("\t |5 - Apagar cliente                                     |\n");
    printf("\t |6 - Listar todos os clientes.                          |\n");
    printf("\t |7 - Listar veiculos de um cliente.                     |\n");
    printf("\t |8 - Resgatar pontos de um cliente.                     |\n");
    printf("\t |9 - Alterar nome do cliente.                           |\n");
    printf("\t |0 - Sair.                                              |\n");
    printf("\t |_______________________________________________________|\n\n");
    colorize(BLACK, LIGHT_YELLOW);
    printf(">> INSIRA SUA ESCOLHA: ");
}

// Lida com a escolha de uma opção pelo usuário
void handleSelectChoices()
{
    int option;
    scanf("%d", &option);

    switch (option)
    {
    case 0:
        exit(0);
        break;
    case 1:
        handleRegisterNewClient();
        break;
    case 2:
        handleRegisterNewVehicle();
        break;
    case 5:
        handleDeleteClient();
        break;
    case 6:
        handleListAllClients();
        break;
    case 9:
        handleChangeClientName();
        break;
    default:
        showMenu();
        break;
    }
}

//Função chamada quando ocorre algum erro e é preciso voltar para
//o menu principal ou sair
void handleExitOrGoBackToMainMenu()
{
    int option;

    colorize(BLACK, DARK_BLUE);
    printf("\nDigite (1) para voltar ao menu ou qualquer outra tecla para sair: ");
    colorize(BLACK, LIGHT_BLACK);

    scanf("%d", &option);

    switch (option)
    {
    case 1:
        showMenu();
        handleSelectChoices();
        break;
    default:
        exit(1);
        break;
    }
}

//Lida com o registro de um novo cliente
void handleRegisterNewClient()
{
    char cpf[12];
    char name[60];

    colorize(BLACK, LIGHT_YELLOW);
    printf("Informe o CPF do cliente: ");
    colorize(BLACK, LIGHT_BLACK);
    scanf(" %[^\n]", &cpf);

    if (strlen(cpf) != 11)
    {
        colorize(BLACK, DARK_RED);
        printf("[ERRO] O CPF precisa ter 11 digitos!");
        handleExitOrGoBackToMainMenu();
    }

    if (isClientAlreadyRegistered(cpf))
    {
        colorize(BLACK, DARK_RED);
        printf("[ERRO] Ja existe um cliente com esse CPF cadastrado!");
        handleExitOrGoBackToMainMenu();
    }
    else
    {
        colorize(BLACK, LIGHT_YELLOW);
        printf("Informe o nome do cliente: ");
        colorize(BLACK, LIGHT_BLACK);
        scanf(" %[^\n]", &name);

        int status = handleRegisterClientInDatabase(cpf, name);

        if (status)
        {
            colorize(BLACK, LIGHT_GREEN);
            printf("Sucesso! Cliente registrado no sistema!");
            handleExitOrGoBackToMainMenu();
        }
        else
        {
            colorize(BLACK, DARK_RED);
            printf("[ERRO] Ocorreu um erro ao registrar o cliente!");
            handleExitOrGoBackToMainMenu();
        }
    }
}

//Lida com o registro de um novo veículo
void handleRegisterNewVehicle()
{
    char cpf[12];
    char licensePlate[8];

    colorize(BLACK, LIGHT_YELLOW);
    printf("Informe o CPF do cliente: ");
    colorize(BLACK, LIGHT_BLACK);
    scanf(" %[^\n]", &cpf);

    if (strlen(cpf) != 11)
    {
        colorize(BLACK, DARK_RED);
        printf("[ERRO] O CPF precisa ter 11 digitos!");
        handleExitOrGoBackToMainMenu();
    }

    if (!isClientAlreadyRegistered(cpf))
    {
        colorize(BLACK, DARK_RED);
        printf("[ERRO] Nao existe nenhum cliente com esse CPF");
        handleExitOrGoBackToMainMenu();
    }
    else
    {
        colorize(BLACK, LIGHT_YELLOW);
        printf("Informe a placa do veiculo: ");
        colorize(BLACK, LIGHT_BLACK);
        scanf(" %[^\n]", &licensePlate);

        if (strlen(licensePlate) != 7)
        {
            colorize(BLACK, DARK_RED);
            printf("[ERRO] A placa precisa ter 7 caracteres!");
            handleExitOrGoBackToMainMenu();
        }

        if (isVehicleAlreadyRegistered(licensePlate))
        {
            colorize(BLACK, DARK_RED);
            printf("[ERRO] Esse veiculo ja esta registrado no sistema");
            handleExitOrGoBackToMainMenu();
        }
        else
        {
            int status = handleRegisterVehicleInDatabase(cpf, licensePlate);

            if (status)
            {
                colorize(BLACK, LIGHT_GREEN);
                printf("Sucesso! Veiculo registrado no sistema!");
                handleExitOrGoBackToMainMenu();
            }
            else
            {
                colorize(BLACK, DARK_RED);
                printf("[ERRO] Ocorreu um erro ao registrar o veiculo!");
                handleExitOrGoBackToMainMenu();
            }
        }
    }
}

//Lida com a remoção de um cliente do sistema
void handleDeleteClient()
{
    char cpf[12];
    int confirm = 0;

    colorize(BLACK, LIGHT_YELLOW);
    printf("Informe o CPF do cliente: ");
    colorize(BLACK, LIGHT_BLACK);
    scanf(" %[^\n]", &cpf);

    if (strlen(cpf) != 11)
    {
        colorize(BLACK, DARK_RED);
        printf("[ERRO] O CPF precisa ter 11 digitos!");
        handleExitOrGoBackToMainMenu();
    }

    if (!isClientAlreadyRegistered(cpf))
    {
        colorize(BLACK, DARK_RED);
        printf("[ERRO] Nao existe nenhum cliente com esse CPF");
        handleExitOrGoBackToMainMenu();
    }
    else
    {
        colorize(BLACK, DARK_BLUE);
        printf("Tem certeza que deseja deletar esse cliente? (1-SIM / 2-NAO): ");
        colorize(BLACK, LIGHT_BLACK);
        scanf("%d", &confirm);

        if (confirm == 1)
        {
            int status = handleDeleteClientInDatabase(cpf);

            if (status)
            {
                colorize(BLACK, LIGHT_GREEN);
                printf("Sucesso! Cliente e veiculos deletados do sistema!");
                handleExitOrGoBackToMainMenu();
            }
            else
            {
                colorize(BLACK, DARK_RED);
                printf("[ERRO] Ocorreu um erro ao deletar o cliente!");
                handleExitOrGoBackToMainMenu();
            }
        }else{
            handleExitOrGoBackToMainMenu();
        }
    }
}

//Lida com a atualização do nome de um usuário
void handleChangeClientName()
{
    char cpf[12];
    char name[60];

    colorize(BLACK, LIGHT_YELLOW);
    printf("Informe o CPF do cliente: ");
    colorize(BLACK, LIGHT_BLACK);
    scanf(" %[^\n]", &cpf);

    if (strlen(cpf) != 11)
    {
        colorize(BLACK, DARK_RED);
        printf("[ERRO] O CPF precisa ter 11 digitos!");
        handleExitOrGoBackToMainMenu();
    }

    if (!isClientAlreadyRegistered(cpf))
    {
        colorize(BLACK, DARK_RED);
        printf("[ERRO] Nao existe nenhum cliente com esse CPF");
        handleExitOrGoBackToMainMenu();
    }
    else
    {
        colorize(BLACK, LIGHT_YELLOW);
        printf("Informe o novo nome do cliente: ");
        colorize(BLACK, LIGHT_BLACK);
        scanf(" %[^\n]", &name);

        int status = handleUpdateClientNameInDatabase(cpf, name);

        if (status)
        {
            colorize(BLACK, LIGHT_GREEN);
            printf("Sucesso! Nome do cliente atualizado!");
            handleExitOrGoBackToMainMenu();
        }
        else
        {
            colorize(BLACK, DARK_RED);
            printf("[ERRO] Ocorreu um erro ao atualizar o nome do cliente!");
            handleExitOrGoBackToMainMenu();
        }
    }
}

//Lista todos os usuáros do sistema
void handleListAllClients()
{

    const unsigned char *clientsFormated = getAllClientsInDatabase();

    if (strcmp(clientsFormated, "[NULL]") == 0)
    {
        colorize(BLACK, DARK_RED);
        printf("[ERRO] Ocorreu um erro ao buscar os clientes!");
        handleExitOrGoBackToMainMenu();
    }
    else
    {
        colorize(BLACK, DARK_CYAN);
        printf("Exibindo todos os clientes do sistema:\n");
        colorize(BLACK, LIGHT_CYAN);
        printf(clientsFormated);
        handleExitOrGoBackToMainMenu();
    }
}