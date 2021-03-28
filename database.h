int initializeDatabase();
void closeDatabaseConnection();
const unsigned char *searchClientByCPF(char *cpf);
int registerClient(char* cpf, char* name);