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
    int nbrLineDB=1;
    nbrLineDB=nbrLineDB<<NBR_INPUT;
    printf("nbrLine : %d\n",nbrLineDB);
    int i;
    int tabBinary[NBR_INPUT];
    int data[NBR_INPUT+1];
    for (i=0;i<nbrLineDB;i++){
        intToTableBinary(i,tabBinary,NBR_INPUT);
        data[0]=i;
        printf("tabBinary :%d  %d  %d \n",tabBinary[0],tabBinary[1],tabBinary[2]);
        printf("Predata :%d  %d  %d %d \n",data[0],data[1],data[2],data[3]);

        int j;
        memcpy(&data[1],tabBinary, sizeof(tabBinary));
        printf("data :%d  %d  %d %d \n\n",data[0],data[1],data[2],data[3]);

        setDataDB(nameTable,data,NBR_INPUT+1,db);

    }


    sqlite3_close(db);

    return 0;
}





