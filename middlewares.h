int isClientAlreadyRegistered(char* cpf);
int handleRegisterClientInDatabase(char* cpf, char* name);
int handleRegisterVehicleInDatabase(char* cpf, char* licensePlate);
int isVehicleAlreadyRegistered(char* licensePlate);
int handleDeleteClientInDatabase(char *cpf);
int handleUpdateClientNameInDatabase(char *cpf, char *name);
const char *getAllVehiclesByCPFInDatabase(char *cpf);
const char *getAllClientsInDatabase();