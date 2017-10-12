void createNewTable(char nameTable[],int nbrInput,sqlite3 *db);
static int callback(void *NotUsed, int argc, char **argv, char **azColName);
void setDataDB(char nameTable[],int data[],int sizeTabl,sqlite3 *db);
