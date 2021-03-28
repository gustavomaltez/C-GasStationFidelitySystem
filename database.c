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
                "(`cpf`  varchar(11) NOT NULL  PRIMARY KEY,"
                "`name` varchar(60) NOT NULL);"
                "CREATE TABLE IF NOT EXISTS `vehicle`("
                " `plate`  varchar(7) NOT NULL PRIMARY KEY,"
                "`liters` FLOAT NOT NULL DEFAULT 0,"
                "`owner_cpf` varchar(11),"
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

//Fecha a conexão com o banco de dados
void closeDatabaseConnection()
{
    sqlite3_close(database);
}

//Busca um cliente por CPF
//Retorna "" se o cliente não exister ou o CPF do cliente se existir
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

const unsigned char *searchVehicleByLicensePlate(char *licensePlate)
{
    char query[100] = "SELECT * from vehicle WHERE (plate == \"";
    strcat(query, licensePlate);
    strcat(query, "\");");

    sqlite3_stmt *stmt = NULL;
    sqlite3_prepare_v2(database, query, -1, &stmt, 0);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const unsigned char *vehicleLicensePlate = sqlite3_column_text(stmt, 0);
        return vehicleLicensePlate;
    }

    if (sqlite3_step(stmt) != SQLITE_ROW)
    {
        return "";
    }
}

int registerClient(char *cpf, char *name)
{
    char query[100] = "INSERT INTO user VALUES (\"";
    strcat(query, cpf);
    strcat(query, "\",\"");
    strcat(query, name);
    strcat(query, "\");");

    if (sqlite3_exec(database, query, 0, 0, 0) != SQLITE_OK)
        return 0;
    else
        return 1;
}

int registerVehicle(char *cpf, char *licensePlate)
{
    char query[100] = "INSERT INTO vehicle VALUES (\"";
    strcat(query, licensePlate);
    strcat(query, "\",\"");
    strcat(query, "0\",\"");
    strcat(query, cpf);
    strcat(query, "\");");

    if (sqlite3_exec(database, query, 0, 0, 0) != SQLITE_OK)
        return 0;
    else
        return 1;
}