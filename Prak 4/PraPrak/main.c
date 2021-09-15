#include <stdio.h>
#include <stdlib.h>
#include "listDin.h"
int main()
{
    ListDin l1,l2,l3;
    IdxType val;
    ElType min, max,idx;

    CreateListDin(&l1,5);
    CreateListDin(&l2,5);

    displayList(l1);
    printf("\n");

    printf("bikin list 1:\n");
    printf("\n");
    readList(&l1);
    
    displayList(l1);
    printf("\n");

    printf("bikin list 1:\n");
    readList(&l2);
    displayList(l2);

    printf("\n");
    printf("panjangnya %d\n", length(l1));

    if (isEmpty(l1))
    {
        printf("list kosong\n");
    }
    else if (!isEmpty(l1))
    {
        printf("list gak kosong\n");
    }

    if (isFull(l1))
    {
        printf("list penuh\n");
    }
    else if (!isFull(l1))
    {
        printf("list gak penuh\n");
    }
    
    idx= getLastIdx(l1);
    printf("last element l1:\n");
    printf("%d",ELMT(l1,idx));

    if(isIdxValid(l1, 7)){
        printf("l1 index 7 valid\n");
    }
    if(isIdxValid(l1, 4)){
        printf("l1 index 4 valid\n");
    }

    if(isIdxValid(l1, 7)){
        printf("l1 index 7 efektif\n");
    }
    if(isIdxValid(l1, 4)){
        printf("l1 index 4 efektif\n");
    }
    
    displayList(plusMinusList(l1,l2,true));
    printf("\n");
    displayList(plusMinusList(l1,l2,false));
    printf("\n");
    
    if(isListEqual(l1,l2)){
        printf("kedua list sama\n");
    }
    if(!isListEqual(l1,l2)){
        printf("kedua list tidak sama\n");
    }

    printf("cari elemen apa?\n");
    scanf("%d",&val);
    printf("%d ada di index %d",val, indexOf(l1,val));

    extremes(l1,&max,&min);

    printf("max: %d\nmin:%d",max,min);
    copyList(l1,&l3);
    displayList(l3);
    printf("\n");

    printf("ditotalin jadi: %d\n", sumList(l1));

    printf("nilai apa yang mau dicari muncul berapa kali?\n");
    scanf("%d",&val);
    printf("%d muncul %d kali\n", val,countVal(l1,val));

    if (isAllEven(l1))
    {
        printf("l1 genap semua\n");
    }
    if (!isAllEven(l1))
    {
        printf("l1 gak genap semua\n");
    }

    printf("l1 abis disort ascending jadi:\n");
    sort(&l1,true);
    displayList(l1);
    printf("\n");

    printf("l1 abis disort descending jadi:\n");
    sort(&l1,false);
    displayList(l1);
    printf("\n");
    
    printf("mau berapa yang ditambahin?\n");
    scanf("%d",&val);
    growList(&l1,1);
    insertLast(&l1, val);
    displayList(l1);
    printf("\n");

    deleteLast(&l1,&val);
    displayList(l1);
    printf("\n");
    shrinkList(&l1,1);

    growList(&l1, 10);
    printf("kapasitas %d",CAPACITY(l1));

    shrinkList(&l1, 5);
    printf("kapasitas %d",CAPACITY(l1));
    compactList(&l1);
    printf("kapasitas %d",CAPACITY(l1));
    
    return 0;
}
