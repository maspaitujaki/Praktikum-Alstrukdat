#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main()
{
    ListPos l1, l2;
    int val, wang,x;

    printf("Bikin List 1!\n");
    readList(&l1);
    printf("\nJadi sebuah list : ");
    displayList(l1);
    printf(" panjangnya %d\n", length(l1));

    // if (isEmpty(l1))
    // {
    //     printf("\n List ini kosong");
    // } else if(!isEmpty(l1))
    // {
    //     printf("\n List ini tidak kosong");
    // }

    // printf("Bikin List 2!\n");
    // readList(&l2);
    // printf("\nJadi sebuah list : ");
    // displayList(l2);
    // printf(" panjangnya %d\n", length(l2));
    
    // if (isEmpty(l2))
    // {
    //     printf("\n List ini kosong");
    // } else if(!isEmpty(l2))
    // {
    //     printf("\n List ini tidak kosong");
    // }
    
    // printf("Kalo dijumlahin jadi: ");
    // displayList(plusMinusTab(l1,l2,true));
    // printf("Kalo dikurangin jadi: ");
    // displayList(plusMinusTab(l1,l2,false));

    // if (isListEqual(l1,l2))
    // {
    //     printf("\n Kedua list sama\n");
    // } else if (!isListEqual(l1,l2))
    // {
    //     printf("\n Kedua list beda\n");
    // }
    
    // printf("Berapa yang mau dicari?\n");
    // scanf("%d",&val);
    // printf("%d pada l1 ada di index ke %d\n",val, indexOf(l1,val));

    // extremes(l1, &max, &min);
    // printf("%d merupakan nilai terbesar, sedangkan %d nilai terkecil\n",max,min);
    
    // if (isAllEven(l1))
    // {
    //     printf("l1 genap semua\n");
    // } else if (!isAllEven(l1))
    // {
    //     printf("l1 ada yang ganjil\n");
    // }

    printf("Mau masukin berapa?\n");
    scanf("%d", &x);
    insertLast(&l1,x);
    displayList(l1);
    printf(" panjangnya %d\n", length(l1));

    deleteLast(&l1,&wang);
    printf("%d dibuang, sekarang list nya jadi:\n", wang);
    displayList(l1);
    printf(" panjangnya %d\n", length(l1));

    sort(&l1,true);
    printf("Disort membesar jadi:\n");
    displayList(l1);

    sort(&l1,false);
    printf("\nDisort mengecil jadi:\n");
    displayList(l1);

    return 0;
}
