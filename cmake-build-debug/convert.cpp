//
// Created by esisar on 12/10/17.
//
#include "convert.h"

void tableBoolToInt(bool tabBool[], int tabInt[], int size){
    int i;
    for(i=0;i<size;i++){
        if(tabBool[i]){
            tabInt[i]=1;
        }else {
            tabInt[i]=0;
        }
    }
}
void tableIntToBool(int tabInt[],bool tabBool[],int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (tabInt[i]==1) {
            tabBool[i] = true;
        } else {
            tabBool[i] = false;
        }
    }
}