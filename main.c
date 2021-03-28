#include <stdio.h>
#include <stdlib.h>
#include "colorize.h"
#include "database.h"
#include "interface.h"
#include "sqlite3.h"

int main()
{
    char cpf[12];
    int option = 0;

    //Cria as variáveis usadas para a conexão com o banco de dados
    sqlite3 *db;
    char *databaseErrorMsg = 0;

    //Inicializa o banco de dados
    int databaseConnectionStatus = initializeDatabase(db);

    //Caso ocorra algum erro na inicialização do banco, fecha a aplicação
    if (databaseConnectionStatus == 0)
    {
        return 0;
    }

    //Mostra o menu padrão
    showMenu();

    scanf("%d", &option);
    switch (option)
    {
    case 1:
        handleRegisterNewClient();
        break;

    default:
        showMenu();
        break;
    }

    //Close database connection before exit
    sqlite3_close(db);

    return 0;
}