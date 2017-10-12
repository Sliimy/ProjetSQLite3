//
// Created by Sebastien Lapeyre on 11/10/17.
//
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <sqlite3.h>
#include "gestionDB.h"

using namespace std;


void createNewTable(char nameTable[],int nbrInput,sqlite3 *db){

    int i,rc;
    char *zErrMsg = 0;
    char* sql;

    string str="CREATE TABLE "+(string) nameTable+"(" \
                "ID INT NOT NULL,";
    for(i=1;i<=nbrInput;i++){
        string number=to_string(i);
        if(i<nbrInput){
            str=str+"PIN"+number+" INT NOT NULL, ";
        }else{
            str=str+"PIN"+number+" INT NOT NULL );";
        }
    }
    sql=&str[0u];
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
    cout << "test2" << str << "\n";
}
//void setDataDB

// AJOUT FOREIGN KEY POUR LES SORTIES
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
