int initializeDatabase();
void closeDatabaseConnection();
const unsigned char *searchClientByCPF(char *cpf);
const unsigned char *searchVehicleByLicensePlate(char* licensePlate);
int registerClient(char* cpf, char* name);
int registerVehicle(char* cpf, char* licensePlate);