#include "database.h"
#include <string.h>

//Busca por um cliente no banco de dados usando um CPF
//Caso o cliente exista retorna 1
//Caso o cliente não exista retorna 0
int isClientAlreadyRegistered(char *cpf)
{

    //A função pode retornar "" ou o CPF do cliente buscado
    const unsigned char *clientCPF = searchClientByCPF(cpf);

    if (strcmp(clientCPF, cpf) == 0)
        return 1;
    else
        return 0;
}

//Registra um cliente no banco de dados
//Retorna 1 se deu certo ou 0 se deu erro
int handleRegisterClientInDatabase(char *cpf, char *name)
{
    return registerClient(cpf, name);
}

//Registra um veículo no banco de dados
//Retorna 1 se deu certo ou 0 se deu erro
int handleRegisterVehicleInDatabase(char *cpf, char *licensePlate)
{
    return registerVehicle(cpf, licensePlate);
}

//Remove um cliente e seus veículos do banco de dados
//Retorna 1 se deu certo ou 0 se deu erro
int handleDeleteClientInDatabase(char *cpf)
{
    return deleteClientAndVehicles(cpf);
}

//Busca por um veículo no banco de dados usando uma placa
//Caso o veículo exista retorna 1
//Caso o veículo não exista retorna 0
int isVehicleAlreadyRegistered(char *licensePlate)
{
    //A função pode retornar "" ou a placa do veiculo
    const unsigned char *vehicleLicensePlate = searchVehicleByLicensePlate(licensePlate);

    if (strcmp(vehicleLicensePlate, licensePlate) == 0)
        return 1;
    else
        return 0;
}

//Atualiza o nome de um cliente no banco de dados com base no cpf
//Retorna 1 se der certo e 0 se der errado
int handleUpdateClientNameInDatabase(char *cpf, char *name)
{
    return updateClientName(cpf, name);
}

//Busca todos os clientes e trás os dados formatados
//Pode retornar a lista de clietes ou [NULL]
const char *getAllClientsInDatabase()
{
    return getClients();
}