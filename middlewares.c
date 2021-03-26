/*
Trabalho de LAB - FUNÇÕES DE COMUNICAÇÃO DA INTERFACE COM FUNÇÕES DO BANCO DE DADOS
Responsável - Isaac Emanuel Costa de Andrade 
Matricula - 493661
E-mail - ienewton123@gmail.com
E-mail institucional - zaazaac@alu.ufc.br
*/

#include <stdio.h>
#include <math.h>

int client_check(const char* cpf cpf){ // AUX
    if(/*cliente existe*/) return 1; // Se o cliente existe no sistema, retorna 1

    else return 0; // Senão, retorna 0
}

int vehicle_check(const char* license_plate){ // AUX
    if(/*veiculo existe*/) return 1; // Se o veiculo existe no sistema, retorna 1
    
    else return 0;
}

int client_register(const char* cpf cpf){ // Registra o cliente no sistema 
    if(client_check(cpf) == 0){ // Se for possivel registrar, registra e retorna 1
        //...
        /* codigo para registrar o cliente */
        //...
        return 1;
    }
    else return 0; // Se o cliente ja existir no sistema, retorna 0
}

int vehicle_register(const char* license_plate){ // Registra um veiculo de um cliente no sistema
    if(vehicle_check(cpf) == 0){ // Se for possivel registrar o veiculo, registra e retorna 1
        //...
        /* codigo para registrar o veiculo */
        //...
        return 1;
    }
    else return 0; // Se o veiculo ja existir no sistema, retorna 0
}

int fill_vehicle(const char* license_plate, int fuel){ // Passa a quantidade de litros abastecidos para o banco de dados  
    if(vehicle_check(license_plate) == 1){
        //...
        /* codigo para "abastecer" no banco de dados */ 
        //...
        return 1;
    }
    else return 0;
}

float fuel_search(const char* cpf){ // Busca a quantidade de litros abastecidos, sera usada na funcao de resgatar pontos
    if(client_check(cpf) == 1){ // Se o cliente existe no sistema, busca a quantidade de litros acumulados
        float total_fuel = /* quantidade total de litros abastecidos do cliente encontrada no banco */ 
        return total_fuel;
    }
    else return -1;
}

int rescue_points(const char* cpf){ // Resgata os pontos do cliente
    if(client_check(cpf) == 1){ // Se o cliente existe no sistema retorna o número de pontos do cliente(arredondado)
        return ceil(fuel_search(cpf) * 25);
    }
    else return -1; // Senão retorna -1
} 


/*

OBSERVAÇÕES:
O código apresenta alguns módulos faltando. Cada comentário nesse estilo: \* *\
é a descrição de alguma parte do código que ainda não tenha sido implementada,
como um cabeçalho de if ou um nome de variável.
comentários nesse estilo: // São comentários mesmo, que descrevem o comportamento
do código escrito

*/
