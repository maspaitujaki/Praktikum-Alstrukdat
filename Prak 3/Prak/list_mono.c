/*  NIM             : 13520156
    Nama            : Dimas Faidh Muzaki
    Tanggal         : 9 September 2021
    Topik praktikum : ADT list
    Deskripsi       : Penggunaan ADT List    */


#include <stdio.h>
#include "listpos.h"

int main()
{
    int i, j, len;
    boolean NoDesc = true, NoAsc =true;
    ListPos l;
    readList(&l);
    len=length(l);

    for (i = 0; i < len-1; i++)
    {
        for (j = i+1; j < len; j++)
        {
            if (ELMT(l,i)>ELMT(l,j)){
                NoDesc = false;
            }
            if (ELMT(l,i)<ELMT(l,j)){
                NoAsc = false;
            }
        }
        
        if ((!NoAsc) && (!NoDesc)){
            break;
        }
    }

    if (NoDesc && NoAsc){
        printf("Static Monotonic List\n");
    } else if (NoDesc){
        printf("Non-descending Monotonic List\n");
    } else if (NoAsc){
        printf("Non-ascending Monotonic List\n");
    } else{
        printf("Non-monotonic List\n");
    }


    return 0;
}
