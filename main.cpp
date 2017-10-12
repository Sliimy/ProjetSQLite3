#include <stdio.h>
#include <sqlite3.h>
#include <string>
#include <iostream>
#include "gestionDB.h"


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

    char nameTable[]="table1";
    createNewTable( nameTable,3,db);

    int testint[4]={1,2,3,3};
    setDataDB(nameTable,testint,4,db);

    sqlite3_close(db);

    return 0;
}



