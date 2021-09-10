/*  NIM             : 13520156
    Nama            : Dimas Faidh Muzaki
    Tanggal         : 7 September 2021
    Topik praktikum : ADT list
    Deskripsi       : realisasi dari ADT list    */

#include <stdio.h>
#include "listpos.h"    
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
{
    /* Kamus lokal */
    int i=0;
    /* Algoritma */
    for(i;i<CAPACITY;i++){
        ELMT(*l,i) = VAL_UNDEF;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPos l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
{
    /* Kamus lokal */
    int idx = 0;
    /* Algoritma */
    while ((!(ELMT(l,idx) == VAL_UNDEF)) && (idx < CAPACITY))
    {
        idx ++;
    }

    return idx;
    
}
/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    /* Kamus lokal */
    /* Algoritma */
    return((i>IDX_UNDEF) && (i<CAPACITY));
}
boolean isIdxEff(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
    /* Kamus lokal */
    /* Algoritma */
    return((i>IDX_UNDEF) && (i<length(l)));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */

{
    /* Kamus lokal */
    /* Algoritma */
    return(ELMT(l,0) == VAL_UNDEF);
}
/* *** Test List penuh *** */
boolean isFull(ListPos l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
    /* Kamus lokal */
    /* Algoritma */
    return (length(l) == CAPACITY);
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos *l)
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
{
    /* Kamus lokal */
    int n, elmt, i;
    /* Algoritma */
    CreateListPos(l);
    do
    {
        scanf("%d",&n);
    } while ((n < 0) || (n > 100));
    if (n==0){

    } else
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d",&elmt);
            ELMT(*l,i) = elmt;
        }
    }
}
void displayList(ListPos l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
    /* Kamus lokal */
    int i=0, len= length(l);
    /* Algoritma */
    printf("[");
    if (isEmpty(l)){
    
    } else
    {
        for (i; i < len; i++)
        {
            printf("%d",ELMT(l,i));
            if(i != len-1){
                printf(",");
            }
        }
    }
    printf("]");
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus)
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
{
    /* Kamus lokal */
    int i=0, len= length(l1);
    ListPos l3;
    /* Algoritma */
    CreateListPos(&l3);
    if (plus)
    {
         for (i; i < len; i++)
        {
            ELMT(l3,i) = ELMT(l1,i)+ELMT(l2,i);
        }
    }
    else
    {
        for (i; i < len; i++)
        {
            ELMT(l3,i) = ELMT(l1,i)-ELMT(l2,i);
        }
    }
    return l3;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
{
    /* Kamus lokal */
    int i=0, len;
    boolean d=true;
    /* Algoritma */
    if (length(l1) == length(l2)){
        len= length(l1);
        for (i = 0; i < len; i++)
        {
            if(ELMT(l1,i) != ELMT(l2,i)){
                d=false;
                break;
            }
        }
        

    }
    else
    {
        d=false;
    }
    return d;
    
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
    /* Kamus lokal */
    int idx;
    boolean found=false;
    /* Algoritma */
    if (isEmpty(l)){
        
    } else
    {
        idx=0;
        while ((ELMT(l,idx) != VAL_UNDEF) && (!found) && (idx<CAPACITY))
        {
            if (ELMT(l,idx) == val)
            {
                found = true;
                break;
            }
            idx += 1;
        }
    }
    if (!found){
        idx= IDX_UNDEF;
    }
    return idx;
}
/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
{
    /* Kamus lokal */
    int i=1;
    /* Algoritma */
    *max = ELMT(l,0);
    *min = ELMT(l,0);

    while ((ELMT(l,i) != VAL_UNDEF) && (i<CAPACITY))
    {
        /* code */
        if (*max < ELMT(l,i))
        {
            *max = ELMT(l,i);
        }
        if (*min > ELMT(l,i))
        {
            *min = ELMT(l,i);
        }
        i++;
    }
    
}
/* ********** OPERASI LAIN ********** */
boolean isAllEven(ListPos l)
/* Menghailkan true jika semua elemen l genap */
{
    /* Kamus lokal */
    int i=0;
    boolean d=true;
    /* Algoritma */
    while ((ELMT(l,i)!= VAL_UNDEF) && (i < CAPACITY) && (d))
    {
        if (ELMT(l,i) % 2 != 0){
            d = false;
        }
        i++;
    }
    return d;
}
/* ********** SORTING ********** */
void sort(ListPos *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    /* Kamus lokal */
    int i,j,tmp, len = length(*l);
    /* Algoritma */

    if (asc)
    {
        for(i=0; i<len; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(ELMT(*l,j) <ELMT(*l,i))
                {
                    tmp = ELMT(*l,i);
                    ELMT(*l,i) = ELMT(*l,j);
                    ELMT(*l,j) = tmp;
                }
            }
        }
    } else
    {
        for(i=0; i<len; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(ELMT(*l,i) < ELMT(*l,j))
                {
                    tmp = ELMT(*l,i);
                    ELMT(*l,i) = ELMT(*l,j);
                    ELMT(*l,j) = tmp;
                }
            }
        }
    }
    
    
    
}
/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
{
    /* Kamus lokal */
    int len= length(*l);
    /* Algoritma */
    if (len == 0){
        ELMT(*l,0) = val;
    } else
    {
        ELMT(*l,len) = val;
    }
    
}
void deleteLast(ListPos *l, ElType *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    /* Kamus lokal */
    int last = length(*l)-1;
    /* Algoritma */
    *val = ELMT(*l,last); 
    ELMT(*l,last) = VAL_UNDEF;

}