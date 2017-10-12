#include <stdio.h>
#include <sqlite3.h>
#include <string>
#include <string.h>
#include <iostream>
#include "gestionDB.h"
#include "convert.h"

#define NBR_INPUT 3

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
    createNewTable( nameTable,NBR_INPUT,db);
    bool test[NBR_INPUT];
    int testint[NBR_INPUT]={1,0,1};
    //tableBoolToInt(test,testint,NBR_INPUT);
    //int res[4]={4,0,0,0};
    //memcpy(&res[1],testint,NBR_INPUT);
    //setDataDB(nameTable,res,NBR_INPUT+1,db);
    tableIntToBool(testint,test,3);
    int i;
    for(i=0;i<3;i++){
        if(test[i]){
            printf("true\n");
        }else {
            printf("false\n");
        }
    }

    sqlite3_close(db);

    return 0;
}



