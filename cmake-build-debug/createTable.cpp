//
// Created by Sebastien Lapeyre on 12/10/17.
//
#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include "createTable.h"
#include "gestionDB.h"
#include "convert.h"

void phase1(sqlite3 *db) {
    char nameTable[]="table1";
    createNewTable( nameTable,NBR_INPUT,db);
    int nbrLineDB = 1;
    nbrLineDB = nbrLineDB << NBR_INPUT;
    int i;
    int tabBinary[NBR_INPUT];
    for (i = 0; i < nbrLineDB; i++) {
        intToTableBinary(i, tabBinary, NBR_INPUT);
        setDataDB(nameTable,tabBinary, NBR_INPUT, db);
    }
}
//TODO: Reprendre cette fonction "
void phase2(sqlite3 *db) {

    char nameTable[]="table2.x";
    int nbrLineDB = 1;
    nbrLineDB = nbrLineDB << NBR_INPUT;
    int i;
    for(i=0;i<nbrLineDB;i++){
        sprintf(&nameTable[sizeof(nameTable)-1],"%d",i);
        createNewTable( nameTable,NBR_INPUT,db);
        int j;
        int tabBinary[NBR_INPUT];
        int data1[NBR_INPUT + 1];
        int data2[NBR_INPUT + 1];
        for (j = 0; j < nbrLineDB; j++) {
            intToTableBinary(j, tabBinary, NBR_INPUT);
            setDataDB(nameTable, tabBinary, NBR_INPUT, db);
            int k;
            for(k=0; k<nbrLineDB;k++){
                intToTableBinary(j, tabBinary, NBR_INPUT);
                data2[0] = j;
                setDataDB(nameTable,tabBinary, NBR_INPUT, db);
            }
        }
    }
}
