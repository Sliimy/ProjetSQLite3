//
// Created by esisar on 12/10/17.
//
#include "convert.h"

void tableBooltoInt(bool tabBool[],int tabInt[],int size){
    int i;
    for(i=0;i<size;i++){
        if(tabBool[i]){
            tabInt[i]=1;
        }else {
            tabInt[i]=0;
        }
    }
}
