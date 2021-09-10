/* File : mtime.c */
/* Driver untuk ADT time */

#include <stdio.h>
#include "time.h"

int main(){
    /* Kamus */
    int N;
    int first = 0;
    TIME t1,t2, temp, taw, takh;
    /* Algoritma */
    scanf("%d", &N);
    for (int i = 1; i <= N;i++){
        printf("[%d]", i);
        BacaTIME(&t1);
        BacaTIME(&t2);
        if (TGT(t1,t2)){
            temp = t1;
            t2 = t1;
            t1 = temp;
        }
        if (first){
            first = 1;
            taw = t1;
            takh = t2;
        } else
        {
            if (TLT(taw,t1)){
                taw = t1;
            }
            if (TGT(takh,t2)){
                takh =t1;
            }
        }
        
        printf("%ld", Durasi(t1,t2));
        
    }
    TulisTIME(taw);
    TulisTIME(takh);
}