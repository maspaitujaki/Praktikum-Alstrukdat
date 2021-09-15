/*    NIM             : 13520156                */
/*    Nama            : Dimas Faidh Muzaki      */
/*    Tanggal         : 14/09/2021              */
/*    Topik Praktikum : ADT List Dinamis        */
/*    Deskripsi       :                         */


/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */
#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    /* Kamus */
    /* Algoritma */
    CAPACITY(*l) = capacity;
    BUFFER(*l) = (ElType*) malloc (capacity * sizeof(ElType));
    NEFF(*l) = 0;
}

void dealocate(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    /* Kamus */
    /* Algoritma */
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    /* Kamus */
    /* Algoritma */
    return NEFF(l);
}
/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    /* Kamus */
    /* Algoritma */
    return NEFF(l)-1;
}
/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    /* Kamus */
    /* Algoritma */
    return ((i>IDX_UNDEF) && (i<CAPACITY(l)));
}
boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
    /* Kamus */
    /* Algoritma */
    return ((i>IDX_UNDEF) && (i<NEFF(l)));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    /* Kamus */
    /* Algoritma */
    return (NEFF(l)==0);
}
/* *** Test list penuh *** */
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    /* Kamus */
    /* Algoritma */
    return (length(l)==CAPACITY(l));
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    /* Kamus */
    int N;
    IdxType i;
    ElType elmt;
    /* Algoritma */
    do
    {
        scanf("%d",&N);
    } while ((N < 0) || (N > CAPACITY(*l)));
    if (N==0){

    } else
    {
        for (i = 0; i < N; i++)
        {
            
            scanf("%d",&elmt);
            ELMT(*l,i) = elmt;
        }
    }
    NEFF(*l) = N;
    
}
void displayList(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    /* Kamus */
    int len= length(l);
    IdxType i;
    /* Algoritma */
    printf("[");
    if (isEmpty(l)){
    
    } else
    {
        for (i=0; i < len; i++)
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
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
    /* Kamus lokal */
    int len= length(l1);
    IdxType i;
    ListDin l3;
    /* Algoritma */
    CreateListDin(&l3, CAPACITY(l1));
    if (plus)
    {
         for (i = 0; i < len; i++)
        {
            ELMT(l3,i) = ELMT(l1,i)+ELMT(l2,i);
        }
    }
    else
    {
        for (i=0; i < len; i++)
        {
            ELMT(l3,i) = ELMT(l1,i)-ELMT(l2,i);
        }
    }
    NEFF(l3) = len;
    
    return l3;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
    /* Kamus lokal */
    int len;
    IdxType i;
    boolean isEqual=true;
    /* Algoritma */
    if (length(l1) == length(l2)){
        len= length(l1);
        for (i = 0; i < len; i++)
        {
            if(ELMT(l1,i) != ELMT(l2,i)){
                isEqual=false;
                break;
            }
        }
    }
    else
    {
        isEqual=false;
    }
    return isEqual;
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
    /* Kamus */
    IdxType i, indVal = IDX_UNDEF;
    int len;

    //ALGORITMA
    len = length(l);
    for (i=0;i<len;i++){
        if (ELMT(l, i) == val){
            indVal = i;
            break;
        }
    }

    return indVal;
}
/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    /* Kamus lokal */
    IdxType i;
    int len = length(l);
    /* Algoritma */
    *max = ELMT(l,0);
    *min = ELMT(l,0);

    for (i=1;i<len;i++)
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
    }
}
/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
    /* Kamus */
    IdxType i;
    int len;

    //ALGORITMA
    CreateListDin(lOut, CAPACITY(lIn));
    len = length(lIn);
    NEFF(*lOut) = len;

    for (i=0; i<len; i++){
        ELMT(*lOut,i) = ELMT(lIn,i);
    }
}
ElType sumList(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
    /* Kamus */
    ElType sum=0;
    IdxType i;
    int len = length(l);
    /* Algoritma */
    if (isEmpty(l))
    {
        
    }
    else
    {
        for (i=0;i<len;i++){
            sum += ELMT(l,i);
        }
    }
    return sum;
    
}
int countVal(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
    /* Kamus */
    int n = 0, len=length(l);
    IdxType i;
    /* Algoritma */
    if (isEmpty(l))
    {
        
    }
    else
    {
        for (i=0;i<len;i++){
            if(ELMT(l,i)==val){
                n += 1;
            }
        }
    }
    return n;
}
boolean isAllEven(ListDin l)
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
{
     /* Kamus lokal */
    IdxType i=0;
    boolean d = true;
    int len;
    /* Algoritma */
    len=length(l);
    for (i=0;i<len;i++)
    {
        if (ELMT(l,i) % 2 != 0){
            d = false;
            break;
        }
    }
    return d;
}
/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    /* Kamus lokal */
    IdxType i,j;
    ElType tmp;
    int len = length(*l);
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
void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    /* Kamus lokal */
    int len= length(*l);
    /* Algoritma */
    ELMT(*l,len) = val;
    NEFF(*l)++;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    /* Kamus lokal */
    int last = getLastIdx(*l);
    /* Algoritma */
    *val = ELMT(*l,last); 
    NEFF(*l) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    /* Kamus */
    int capacity;
    /* Algoritma */
    capacity = CAPACITY(*l) + num;
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l),capacity*sizeof(ElType));
    CAPACITY(*l) = capacity;

}
void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    /* Kamus */
    int capacity;
    /* Algoritma */
    capacity = CAPACITY(*l) - num;
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l),capacity*sizeof(ElType));
    CAPACITY(*l) = capacity;
}
void compactList(ListDin *l)
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
{
    /* Kamus */
    /* Algoritma */
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l),NEFF(*l)*sizeof(ElType));
    CAPACITY(*l) = NEFF(*l);
}

