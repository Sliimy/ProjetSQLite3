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
    printf("nbrLine : %d\n", nbrLineDB);
    int i;
    int tabBinary[NBR_INPUT];
    int data[NBR_INPUT + 1];
    for (i = 0; i < nbrLineDB; i++) {
        intToTableBinary(i, tabBinary, NBR_INPUT);
        data[0] = i;
        printf("tabBinary :%d  %d  %d \n", tabBinary[0], tabBinary[1], tabBinary[2]);
        printf("Predata :%d  %d  %d %d \n", data[0], data[1], data[2], data[3]);

        int j;
        memcpy(&data[1], tabBinary, sizeof(tabBinary));
        printf("data :%d  %d  %d %d \n\n", data[0], data[1], data[2], data[3]);

        setDataDB(nameTable, data, NBR_INPUT + 1, db);
    }
}
