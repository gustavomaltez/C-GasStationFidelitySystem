#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include "colorize.h"

//Inicializa o banco de dados, criando as tabelas principais caso elas não existam
//Retorna 1 se a operação deu certo e 0 se deu errado
int initializeDatabase(sqlite3 *database)
{
    sqlite3_open("database.db", &database);

    if (database == NULL)
    {
        colorize(BLACK, DARK_RED);
        printf("Erro ao abrir o banco de dados! Por favor reinicie o software!\n");
        return 0;
    }

    char *sql = "CREATE TABLE IF NOT EXISTS `user`"
                "(`cpf`  varchar(12) NOT NULL  PRIMARY KEY,"
                "`name` varchar(60) NOT NULL);"
                "CREATE TABLE IF NOT EXISTS `vehicle`("
                " `plate`  varchar(7) NOT NULL PRIMARY KEY,"
                "`liters` FLOAT NOT NULL DEFAULT 0,"
                "`owner_cpf` varchar(12),"
                "FOREIGN KEY(owner_cpf) REFERENCES user(cpf));";

    if (sqlite3_exec(database, sql, 0, 0, 0) != SQLITE_OK)
    {
        sqlite3_close(database);
        return 0;
    }
    else
    {
        return 1;
    }
}
