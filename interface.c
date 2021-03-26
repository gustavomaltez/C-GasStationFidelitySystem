#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "colorize.h"

//Função auxiliar para substituir o sistem("pause").
void pausar() {
    printf("\n\t\tPressione Qualquer tecla para continuar...");
    getch();
}

int main()
{
    char cpf[12]; // Armazena o CPF do cliente.
    int status = -2; // Armazena o valor referente ao cliente ou veículo existente/inexstente no sistema(1 ou 0).
    int op = 10; // Armazena a operação escolhida(1, 2, 3, 4, 5 ou 0).
    char license_plate[10]; // Armazena a placa do carro.
    float fuel = -2; // Guarda o total de litros abastecidos.
    int points = -2;

    setlocale(LC_ALL, "portuguese");

    while(op != 0){

        colorize(DARK_RED, 4);
        printf("\t\t|-------------------------MENU-------------------------|\n\n");
        printf("\t\t1 - Cadastrar novo cliente.\n");
        printf("\t\t2 - Cadastrar novo veículo.\n");
        printf("\t\t3 - Adicionar litros abastecidos pelo cliente.\n");
        printf("\t\t4 - Verificar total de litros abastecidos pelo cliente.\n");
        printf("\t\t5 - Resgatar pontos.\n");
        printf("\t\t0 - Sair.\n");
        printf("\n\t\t|------------------------------------------------------|\n\n");

        printf("\n\t\tEscolha a operação desejada: ");
        scanf("%d", &op);
        fflush(stdin);
        switch(op){
            case 1: // Cadastrar novo cliente.
                printf("\n\t\tInforme o CPF do cliente (apenas números): ");
                fgets(cpf, 12, stdin);
                if(cpf[strlen(cpf) - 1] == '\n')
                    cpf[strcspn(cpf, "\n")] = 0;
                //status = client_register(cpf);
                if(status == 1)
                    printf("\n\t\tCliente cadastrado com sucesso!\n\n");
                else if(status == 0)
                    printf("\n\t\tOperação inválida! Cliente já cadastrado no sistema.\n\n");
                else if(status == -2)
                    printf("\n\t\tFunção ainda não cadastrada no sistema!\n\n");
                pausar();
                system("cls");
                break;

            case 2: // Cadastrar novo veículo.
                printf("\n\t\tInforme a placa do carro do cliente: ");
                fgets(license_plate, 10, stdin);
                if(license_plate[strlen(license_plate) - 1] == '\n')
                    license_plate[strcspn(license_plate, "\n")] = 0;
                //status = vehicle_register(license_plate);
                if(status == 1)
                    printf("\n\t\tVeículo cadastrado com sucesso!\n\n");
                else if(status == 0)
                    printf("\n\t\tOperação inválida! Veículo já cadastrado no sistema.\n\n");
                else if(status == -2)
                    printf("\n\t\tFunção ainda não cadastrada no sistema!\n\n");
                pausar();
                system("cls");
                break;

            case 3: // Adicionar litros abastecidos pelo cliente.
                printf("\n\t\tInforme a placa do carro do cliente: ");
                fgets(license_plate, 10, stdin);
                if(license_plate[strlen(license_plate) - 1] == '\n')
                    license_plate[strcspn(license_plate, "\n")] = 0;
                printf("\n\t\tInforme a quantidade em litros a ser abastecida: ");
                scanf("%f", &fuel);
                //status = fill_vehicle(license_plate, fuel);
                if(status == 1)
                    printf("\n\t\tAbastecimento confirmado com sucesso!\n\n");
                else if(status == 0)
                    printf("\n\t\tOperação inválida! Veículo não cadastrado no sistema.\n\n");
                else if(status == -2)
                    printf("\n\t\tFunção ainda não cadastrada no sistema!\n\n");
                pausar();
                system("cls");
                break;

            case 4: //Verificar total de litros abastecidos pelo cliente.
                fuel = -2;
                printf("\n\t\tInforme o CPF do cliente (apenas números): ");
                fgets(cpf, 12, stdin);
                if(cpf[strlen(cpf) - 1] == '\n')
                    cpf[strcspn(cpf, "\n")] = 0;
                //fuel = fuel_search(cpf);
                if(fuel == -1)
                    printf("\n\t\tOperação inválida! Cliente não cadastrado no sistema.\n\n");
                else if(fuel == -2)
                    printf("\n\t\tFunção ainda não cadastrada no sistema!\n\n");
                else
                    printf("\n\t\tTotal de litros abastecidos: %.2f litros.\n\n", fuel);
                pausar();
                system("cls");
                break;

            case 5: //Resgatar pontos.
                printf("\n\t\tInforme o CPF do cliente (apenas números): ");
                fgets(cpf, 12, stdin);
                if(cpf[strlen(cpf) - 1] == '\n')
                    cpf[strcspn(cpf, "\n")] = 0;
                //points = rescue_points(cpf);
                if(points == -1)
                    printf("\n\t\tOperação inválida! Cliente não cadastrado no sistema.\n\n");
                else if(points == -2)
                    printf("\n\t\tFunção ainda não cadastrada no sistema!\n\n");
                else
                    printf("\n\t\tTotal de pontos resgatados: %d\n\n", points);

                pausar();
                system("cls");
                break;

            case 0:
                printf("\n\t\tPrograma finalizado.\n\n");
                op = 0;
                break;

            default:
                printf("\n\t\tOperação não encontrada.\n\n");
                pausar();
                system("cls");
        }
    }
    return 0;
}
