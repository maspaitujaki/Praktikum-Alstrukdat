
/*
NIM: 13520045
Nama: Addin Nabilal Huda
Tanggal: 14 September 2021
Topik praktikum: PraPraktikum 3 / Array dinamis
Deskripsi:
MODUL INTEGER DYNAMIC LIST
Berisi realisasi semua primitif pemrosesan list integer
Penempatan elemen selalu rapat kiri
Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include <stdio.h>
#include "listdin.h"
#include <stdlib.h>

#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

void CreateListDin(ListDin *l, int capacity){
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    CAPACITY(*l) =capacity;
    BUFFER(*l) = (ElType*) malloc(capacity*sizeof(ElType));
    NEFF(*l)=0;
}

void dealocate(ListDin *l){
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    free(BUFFER(*l));
    CAPACITY(*l) =0;
    NEFF(*l)=0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return (length(l)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i>=0 && i<=CAPACITY(l)-1);
}

boolean isIdxEff(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
    return (i>=0 && i<=NEFF(l)-1);

}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    if (NEFF(l)==0) {
        return true;
    }
    return false;
}

/* *** Test list penuh *** */
boolean isFull(ListDin l){
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return length(l)==CAPACITY(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
   /* KAMUS */
   int i,N;
   /* ALGORITMA */
   do {
      scanf("%d", &N);
   } while (N < 0 || N > CAPACITY(*l));
   for (i=0; i<N; i++) {
      scanf("%d", &ELMT(*l, i));
   }
   NEFF(*l) =N;
}

void displayList(ListDin l){
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
   int i;
   if (length(l)>0){
      printf("[");
      for (i=0; i<(length(l)-1); i++){
         printf("%d,", ELMT(l, i));
      }
      printf("%d]", ELMT(l, length(l)-1));
   }
   else{
      printf("[]");
   }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
    int i;
    ListDin lt;
    CreateListDin(&lt, CAPACITY(l1));
   for (i=0; i<length(l1); i++){
      if (plus) {
         ELMT(lt, i) = ELMT(l1, i) + ELMT(l2, i);
      }
      else {
         ELMT(lt, i) = ELMT(l1, i) - ELMT(l2, i);
      }
   }
   NEFF(lt)= NEFF(l1);
   return lt;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
   /* KAMUS */
    boolean isSame;
   int i=0;
   /* ALGORITMA */
   if (length(l1) != length(l2)) {
      return false;
   }
   else {
      isSame = true;
      while (isSame && i<length(l1)){
         if (ELMT(l1, i) != ELMT(l2, i)) {
            isSame = false;
         }
         else {
            i++;
         }
      }
      return isSame;
   }
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
   /* KAMUS */
   int i=0;
   boolean isAda=false;
   /* ALGORITMA */
   while (isAda==false && i<length(l)) {
      if (ELMT(l, i) == val) {
         isAda=true;
      }
      else {
         i++;
      }
   }
   if (isAda==false) {
      return IDX_UNDEF;
   }
   else {
      return i;
   }
}

/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
    /* KAMUS */
    int i;
   /* ALGORITMA */
   *max=(ELMT(l, 0));
   *min=(ELMT(l, 0));
   for (i=1; i<length(l); i++) {
      if (ELMT(l, i) < *min) {
         *min = ELMT(l, i);
      }
      if (ELMT(l, i) > *max) {
         *max = ELMT(l, i);
      }
   }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
    *lOut =lIn;
}

ElType sumList(ListDin l){
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
    int i,sum;
    sum=0;
    for (i=0; i<length(l); i++){
        sum+= ELMT(l,i);
    }
    return sum;
}
int countVal(ListDin l, ElType val){
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
    /* KAMUS */
    int i, sum;
    sum=0;
   /* ALGORITMA */
   for (i=0; i<length(l); i++) {
       if (ELMT(l,i)==val){
           sum+=1;
       }
   }
   return sum;
}

boolean isAllEven(ListDin l){
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
   /* KAMUS */
   int i=0;
   boolean isEven=true;
   /* ALGORITMA */
   while (i<length(l) && isEven){
      if (ELMT(l, i) %2==0){
         i++;
      }
      else {
         isEven=false;
      }
   }
   return isEven;
}
/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
   void swap(int *x,int *y){
      /* KAMUS */
      int temp;
      /* ALGORITMA */
      temp=*x;
      *x=*y;
      *y=temp;
   }
   /* KAMUS */
   int i, j, idxmin,idxmax;
    /* ALGORITMA */
   if (asc) {
      for (i=0; i<length(*l)-1;i++){
         idxmin=i;
         for (j=i+1; j<length(*l);j++){
            if (ELMT(*l, idxmin)>ELMT(*l, j)) {
               idxmin=j;
            }
         swap(&ELMT(*l, i), &ELMT(*l, idxmin));
         }
      }
   }
   else {
      for (i=0; i<length(*l)-1;i++){
         idxmax=i;
         for (j=i+1; j<length(*l);j++){
            if (ELMT(*l, idxmax)<ELMT(*l, j)) {
               idxmax=j;
            }
         swap(&ELMT(*l, i), &ELMT(*l, idxmax));
         }
      }
   }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    ELMT(*l,length(*l))= val;
    NEFF(*l)+=1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    int i;
    if (NEFF(*l) < CAPACITY(*l)/4) {
        CAPACITY(*l) = CAPACITY(*l)/2;
        BUFFER(*l) = (ElType*) realloc(BUFFER(*l), CAPACITY(*l)/2*sizeof(ElType));
    NEFF(*l)-=1;
    *val=ELMT(*l, NEFF(*l));
    }
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num){
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    CAPACITY(*l)=CAPACITY(*l)+num;
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l), (CAPACITY(*l)+num)*sizeof(ElType));
}

void shrinkList(ListDin *l, int num){
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    CAPACITY(*l)=CAPACITY(*l)-num;
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l), (CAPACITY(*l)-num)*sizeof(ElType));
}

void compactList(ListDin *l){
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
    CAPACITY(*l)=NEFF(*l);
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l), (NEFF(*l))*sizeof(ElType));
}

