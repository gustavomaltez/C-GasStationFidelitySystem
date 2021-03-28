#include "database.h"
#include <string.h>

//Busca por um cliente no banco de dados usando um CPF
//Caso o cliente exista retorna 1
//Caso o cliente não exista retorna 0
int isClientAlreadyRegistered(char* cpf){

    //A função pode retornar "" ou o CPF do cliente buscado
    const unsigned char* clientCPF = searchClientByCPF(cpf);

    if(strcmp(clientCPF,cpf) == 0)
        return 1;
    else
        return 0;  
}

int isVehicleAlreadyRegistered(){
    return 0;
}