#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"
#include "colorize.h"
#include "database.h"

//Variável global para acesso ao banco de dados
sqlite3 *database;

//Inicializa o banco de dados, criando as tabelas principais caso elas não existam
//Retorna 1 se a operação deu certo e 0 se deu errado
int initializeDatabase()
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

void closeDatabaseConnection()
{
    sqlite3_close(database);
}

const unsigned char *searchClientByCPF(char *cpf)
{
    char query[100] = "SELECT * from user WHERE (cpf == \"";
    strcat(query, cpf);
    strcat(query, "\");");

    sqlite3_stmt *stmt = NULL;
    sqlite3_prepare_v2(database, query, -1, &stmt, 0);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const unsigned char *cpf = sqlite3_column_text(stmt, 0);
        return cpf;
    }

    if (sqlite3_step(stmt) != SQLITE_ROW)
    {
       return "";
    }
}
