#include <stdio.h>

#include "sqlite3.h"

int main()
{   
	sqlite3 *db;
    char *err_msg = 0;

	sqlite3_open("database.db", &db);

	if (db == NULL)
	{
		printf("Failed to open DB\n");
		return 1;
	}


    char *sql = "DROP TABLE IF EXISTS Cars;" "CREATE TABLE Cars(Id INT, Name TEXT, Price INT);" ;

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK ) {
        
        printf("Erro!");
        
        sqlite3_free(err_msg);
        sqlite3_close(db);
        
        return 1;
    }else{
        printf("Deu bom");
    }

	sqlite3_close(db);
	return 0;
}

