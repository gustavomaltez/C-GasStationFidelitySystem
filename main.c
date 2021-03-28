#include <stdio.h>
#include <stdlib.h>
#include "colorize.h"
#include "database.h"
#include "interface.h"
#include "sqlite3.h"

int main()
{
    //Inicializa o banco de dados
    int databaseConnectionStatus = initializeDatabase();

    //Caso ocorra algum erro na inicialização do banco, fecha a aplicação
    if (databaseConnectionStatus == 0)
        return 0;

    //Mostra o menu padrão
    showMenu();

    //Lida com a seleção de uma escolha do usuário
    handleSelectChoices();

    //Fecha o banco de dados antes de sair da aplicação
    closeDatabaseConnection();

    return 0;
}