/*  NIM             : 13520156
    Nama            : Dimas Faidh Muzaki
    Tanggal         : 9 September 2021
    Topik praktikum : ADT list
    Deskripsi       : Penggunaan ADT List    */

#include <stdio.h>
#include "listpos.h"

int not_main()
{
    int X, idx, max, min, len;
    ListPos l, ls;
    readList(&l);
    scanf("%d",&X);
    idx = indexOf(l,X);
    displayList(l);
    extremes(l,&max,&min);
    len = length(l);

    ls = l;
    sort(&ls,true);

    printf("\n");
    if (idx == IDX_UNDEF){
        printf("%d tidak ada\n", X);
    } else{
        printf("%d\n",idx);
        if (X==max){
            printf("maksimum\n");
        }
        if (X==min){
            printf("minimum\n");
        }
        if (len % 2 == 0){
            if (X == ELMT(ls,(len/2)-1)){
                printf("median\n");
            }
        } else {
            if (X == ELMT(ls,(len/2)) ){
                printf("median\n");
            }
        }
    }


    return 0;
}

