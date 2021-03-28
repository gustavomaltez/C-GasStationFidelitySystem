#include <stdio.h>
#include <stdlib.h>
#include "colorize.h"
#include "database.h"
#include "interface.h"
#include "sqlite3.h"

int main()
{
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

    //Lida com a seleção de uma escolha do usuário
    handleSelectChoices();

    //Close database connection before exit
    sqlite3_close(db);

    return 0;
}