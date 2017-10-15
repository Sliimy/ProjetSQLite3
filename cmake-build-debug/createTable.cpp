//
// Created by Sebastien Lapeyre on 12/10/17.
//
#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include <stdlib.h> //for function rand
#include "createTable.h"
#include "gestionDB.h"
#include "convert.h"

void phase1(sqlite3 *db) {
    char nameTable[]="table1";
    createNewTable( nameTable,NBR_INPUT,db);
    int nbrInputPossible = 1;
    nbrInputPossible = nbrInputPossible << NBR_INPUT;
    int i;
    int tabBinary[NBR_INPUT];
    for (i = 0; i < nbrInputPossible; i++) {
        intToTableBinary(i, tabBinary, NBR_INPUT);
        setDataDB(nameTable,tabBinary, NBR_INPUT, db);
    }
}
//TODO: Reprendre cette fonction "
void phase2(sqlite3 *db) {

    char nameTable[]="table2";
    createNewTable( nameTable,NBR_INPUT,db);
    int nbrInputPossible = 1;
    nbrInputPossible = nbrInputPossible << NBR_INPUT;

    int tabBinary[NBR_INPUT];
    int data1[NBR_INPUT];
    int data2[NBR_INPUT];
    int i;
    for(i=0;i<nbrInputPossible;i++){
        intToTableBinary(i, data1, NBR_INPUT);
        int j;
        for (j = 0; j < nbrInputPossible; j++) {
            intToTableBinary(j, data2, NBR_INPUT);
            int k;
            for(k=0; k<2;k++){
                setDataDB(nameTable,data1,NBR_INPUT,db);
                setDataDB(nameTable,data2,NBR_INPUT,db);
                int valRand= rand()%NBR_DATA_RAND+1;
                int l;
                for (l = 0; l <valRand ; ++l) {
                    int dataRand=rand()%(nbrInputPossible+1);
                    intToTableBinary(dataRand, tabBinary,NBR_INPUT);
                    setDataDB(nameTable,tabBinary,NBR_INPUT,db);
                }
            }
        }
    }
}

void phase3(sqlite3 *db) {

    char nameTable[]="table3";
    createNewTable( nameTable,NBR_INPUT,db);
    int nbrInputPossible = 1;
    nbrInputPossible = nbrInputPossible << NBR_INPUT;

    int tabBinary[NBR_INPUT];
    int data1[NBR_INPUT];
    int data2[NBR_INPUT];
    int data3[NBR_INPUT];
    for(int i=0;i<nbrInputPossible;i++){
        intToTableBinary(i, data1, NBR_INPUT);
        for (int j = 0; j < nbrInputPossible; j++) {
            intToTableBinary(j, data2, NBR_INPUT);
            for (int m = 0; m < nbrInputPossible; ++m) {
                intToTableBinary(j, data2, NBR_INPUT);
                for(int k=0; k<2;k++){
                    setDataDB(nameTable,data1,NBR_INPUT,db);
                    setDataDB(nameTable,data2,NBR_INPUT,db);
                    setDataDB(nameTable,data3,NBR_INPUT,db);
                    int valRand= rand()%NBR_DATA_RAND+1;
                    int l;
                    for (l = 0; l <valRand ; ++l) {
                        int dataRand=rand()%(nbrInputPossible+1);
                        intToTableBinary(dataRand, tabBinary,NBR_INPUT);
                        setDataDB(nameTable,tabBinary,NBR_INPUT,db);
                    }
                }
            }
        }
    }
}