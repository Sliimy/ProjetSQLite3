
#include <sqlite3.h>
#include <string>
#include <iostream>
#include "createTable.h"



// AJOUT FOREIGN KEY POUR LES SORTIES
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


int main() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    printf("Je suis dedans\n");
    rc = sqlite3_open("mainP.db", &db);
    phase1(db);
    sqlite3_close(db);

    return 0;
}





