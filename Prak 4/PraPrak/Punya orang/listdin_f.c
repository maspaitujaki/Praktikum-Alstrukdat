/*
NIM     : 13520026
Nama    : Muhammad Fajar Ramadhan
Tanggal : 14 September 2021
Topik Praktikum : ADT List DInamis
Deskripsi : Implementasi file header listpos.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity){
    BUFFER(*l) = (ElType*) malloc (capacity * sizeof(ElType));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;

}

void dealocate(ListDin *l){
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}

int length(ListDin l){
    return NEFF(l);
}

IdxType getLastIdx(ListDin l){
    return NEFF(l)-1;
}

boolean isIdxValid(ListDin l, int i){
    return (i>=0 && i<CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i){
    return (i>=0 && i<=NEFF(l));
}

boolean isEmpty(ListDin l){
    return (NEFF(l)==0);
}

boolean isFull(ListDin l){
    return(NEFF(l)==CAPACITY(l));
}

void readList(ListDin *l){
    int a,b;
    scanf("%d",&a);
    while(a<0 || a>CAPACITY(*l)){
        scanf("%d",&a);
    }
    NEFF(*l)=a;
    if(a>0){
        for (int i=0; i<a; i++){
        scanf("%d",&b);
        ELMT(*l,i)=b;
        }
    }
}

void displayList(ListDin l){
    int a=length(l);
    if (isEmpty(l)){
        printf("[]");
    }else{
        printf("[");
        for(int i=0;i<a;i++){
            if(i==(a-1)){
                printf("%d]",ELMT(l,i));
            }else{
                printf("%d,",ELMT(l,i));
            }
        }
    }
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    ListDin temp;
    CreateListDin(&temp,CAPACITY(l1));
    int a = NEFF(l1);
    if(plus==true){
        for(int i=0;i<a;i++){
            ELMT(temp,i)=ELMT(l1,i)+ELMT(l2,i);
        }
    }else{
        for(int i=0;i<a;i++){
            ELMT(temp,i)=ELMT(l1,i)-ELMT(l2,i);
        }
    }
    NEFF(temp) = NEFF(l1);
    return temp;
}

boolean isListEqual(ListDin l1, ListDin l2){
    ListDin p1,p2;
    p1=l1;
    p2=l2;
    sort(&p1,true);
    sort(&p2,true);
    boolean flag = false;
    if(length(l1)==length(l2)){
        flag = true;
        int a=0;
        while(flag==true && a<length(p1)){
            a++;
            if(ELMT(p1,a)!=ELMT(p2,a)){
                flag = false;
            }

        }
    }else{
        flag = false;
    }
    return flag;
}

int indexOf(ListDin l, ElType val){
    int a=length(l);
    int b=0;
    boolean flag=false;
    if (isEmpty(l)==true){
        return IDX_UNDEF;
    }else{
        b=0;
        while(b<length(l) && flag==false){
            if(ELMT(l,b)==val){
                flag=true;
                break;
            }
            else{
                b++;
            }
        }
        if(flag==true){
            return b;
        }else{
            return IDX_UNDEF;
        }
    }
}

void extremes(ListDin l, ElType *max, ElType *min){
    ListDin l2=l;
    sort(&l2,true);
    int a = length(l)-1;
    *max=ELMT(l2,a);
    *min=ELMT(l2,0);
}

void copyList(ListDin lIn, ListDin *lOut){
    CreateListDin(lOut,CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    CAPACITY(*lOut) = CAPACITY(lIn);
    for(int i=0;i<NEFF(lIn);i++){
        ELMT(*lOut,i)=ELMT(lIn,i);
    }
}

ElType sumList(ListDin l){
    int sum = 0;
    for(int i=0;i<NEFF(l);i++){
        sum+=ELMT(l,i);
    }
    return sum;
}

int countVal(ListDin l, ElType val){
    int count = 0;
    if (NEFF(l)==0){
        return 0;
    }else{
        for(int i=0;i<NEFF(l);i++){
            if(ELMT(l,i)==val){
                count+=1;
            }
        }
    }
    return count;

}

boolean isAllEven(ListDin l){
    int a=0;
    boolean flag=true;
    while(a<length(l) && flag==true){
        if(ELMT(l,a)%2!=0){
            flag=false;
        }
        a++;
    }
    return flag;
}

void sort(ListDin *l, boolean asc){
    int panjang = length(*l);
    int temp;
    if (asc==true){
        for(int i=0;i<panjang-1;i++){
            for(int j=0;j<panjang-i-1;j++){
                if(ELMT(*l,j) > ELMT(*l,j+1)){
                    temp = ELMT(*l,j);
                    ELMT(*l,j)=ELMT(*l,j+1);
                    ELMT(*l,j+1)=temp;
                }
            }
        }
    }else{
        for(int i=0;i<panjang-1;i++){
            for(int j=0;j<panjang-i-1;j++){
                if(ELMT(*l,j) < ELMT(*l,j+1)){
                    temp = ELMT(*l,j);
                    ELMT(*l,j)=ELMT(*l,j+1);
                    ELMT(*l,j+1)=temp;
                }
            }
        }
    }

}

void insertLast(ListDin *l, ElType val){
    int a=length(*l);
    ELMT(*l,a)=val;
}

void deleteLast(ListDin *l, ElType *val){
    int a=length(*l)-1;
    *val = ELMT(*l,a);
    NEFF(*l) -= 1;
}

void growList(ListDin *l, int num){
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l),(CAPACITY(*l)+num)*sizeof(ElType));
    CAPACITY(*l) += num;

}

void shrinkList(ListDin *l, int num){
    CAPACITY(*l) -= num;
    BUFFER(*l) = (ElType*) realloc (BUFFER(*l), CAPACITY(*l)*sizeof(ElType));

}

void compactList(ListDin *l){
    CAPACITY(*l) = NEFF(*l);
    BUFFER(*l) = (ElType*) realloc (BUFFER(*l), CAPACITY(*l)*sizeof(ElType));
}
