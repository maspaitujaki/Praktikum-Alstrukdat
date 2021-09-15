/*
13520088
Rio Alexander Audino
15 September 2021
Topik     : ADT List Integer Dinamis
Deskripsi : Implementasi dari file listdin.h
*/


#include "listdin.h"   
#include <stdio.h>
#include <stdlib.h>


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    //ALGORITMA
    CAPACITY(*l) = capacity;
    BUFFER(*l) = (ElType*) malloc (capacity * sizeof(ElType));
    NEFF(*l) = 0;

}

void dealocate(ListDin *l){
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    //ALGORITMA
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
    //ALGORITMA
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    //ALGORITMA
    return NEFF(l)-1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/\
    //ALGORITMA
    return (i>IDX_UNDEF) && (i<CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
    //ALGORITMA
    return (i>IDX_UNDEF) && (i<NEFF(l));   //cek (<) atau (<=)
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    //ALGORITMA
    return NEFF(l) == 0;
}
/* *** Test list penuh *** */
boolean isFull(ListDin l){
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    //ALGORITMA
    return NEFF(l) == CAPACITY(l);
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
    //KAMUS
    int N, cap = CAPACITY(*l);
    IdxType i;
    ElType temp;
    //ALGORITMA
    do
    {
        scanf("%d", &N);
    } while (! ((N>=0) && (N<=cap)));

    for (i=0;i<N;i++){
        scanf("%d", &temp);
        ELMT(*l, i) = temp;
    }

    NEFF(*l) = N;

}
void displayList(ListDin l){
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
    //KAMUS
    IdxType i, last;
    //ALGORITMA
    if (length(l) > 0){
        last = getLastIdx(l);

        printf("[");
        for(i=0; i<last;i++){
            printf("%d,", ELMT(l, i));
        }
        printf("%d]", ELMT(l, last));

    }else{
        printf("[]");
    }    
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
    //KAMUS
    ListDin l3;
    IdxType i;
    int len;

    //ALGORITMA
    CreateListDin(&l3, CAPACITY(l1));
    len = length(l1);
    if (plus){
        for (i = 0; i<len; i++){
            ELMT(l3,i) = ELMT(l1,i) + ELMT(l2,i);
        }
    }else{
        for (i = 0; i<len; i++){
            ELMT(l3,i) = ELMT(l1,i) - ELMT(l2,i);
        }
    }

    NEFF(l3) = len;
    return l3;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
    //KAMUS
    boolean isEqual=true;
    IdxType i;
    int len;

    //ALGORITMA
    if (length(l1) == length(l2)){
        len = length(l1);
        for (i=0;i<len;i++){
            if (ELMT(l1, i) != ELMT(l2,i)){
                isEqual=false;
                break;
            }
        }
    }else{
        isEqual=false;
    }

    return isEqual;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
    //KAMUS
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

    return (indVal);
}

/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
    //KAMUS
    IdxType i;
    int len;

    //ALGORITMA
    len = length(l);
    *max = ELMT(l,0);
    *min = ELMT(l,0);

    for (i=1;i<len;i++){
        if (ELMT(l,i) > *max){
            *max = ELMT(l,i);
        }
        if (ELMT(l,i) < *min){         //HATI-HATI ELSE-IF/IF
            *min = ELMT(l,i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
    //KAMUS
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
ElType sumList(ListDin l){
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
    //KAMUS
    IdxType i, sum = 0;
    int len;

    //ALGORITMA
    len = length(l);
    for (i=0;i<len;i++){
        sum += ELMT(l,i);
    }

    return sum;
}
int countVal(ListDin l, ElType val){
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
    //KAMUS
    IdxType i;
    int count=0, len = length(l);
    
    //ALGORITMA
    for (i=0; i<len ; i++){
        if (ELMT(l,i) == val){
            count ++;
        }
    }

    return count;
}
boolean isAllEven(ListDin l){
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
    //KAMUS
    IdxType i;
    boolean isEven=true;
    int len;

    //ALGORITMA
    len = length(l);
    for (i=0; i<len; i++){
        if (ELMT(l,i) % 2 != 0){
            isEven=false;
            break;
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
    //KAMUS
    int i, j, temp, len;    
    //ALGORITMA
    len = length(*l);
    //Menggunakan Bubble Sort
    for (i=0; i<len;i++){
        for (j = 0; j<len-i-1;j++ ){
            if ((ELMT(*l, j) > ELMT(*l, j+1)) ^ !asc){
                temp = ELMT(*l, j);
                ELMT(*l , j) = ELMT(*l, j+1);
                ELMT(*l, j+1) = temp; 
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
/* ********** MENGHAPUS ELEMEN ********** */
    //KAMUS
    int len = length(*l);

    //ALGORITMA
    ELMT(*l, len) = val;
    NEFF(*l) ++;

}
void deleteLast(ListDin *l, ElType *val){
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    //KAMUS
    int last = getLastIdx(*l);
    //ALGORITMA
    *val = ELMT(*l, last);
    NEFF(*l) --;
}
/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num){
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    //ALGORITMA
    BUFFER(*l) = (ElType*) realloc (BUFFER(*l), (CAPACITY(*l)+num)* sizeof(ElType));
    CAPACITY(*l) += num;
}

void shrinkList(ListDin *l, int num){
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    //ALGORITMA
    BUFFER(*l) = (ElType*) realloc (BUFFER(*l), (CAPACITY(*l)-num)* sizeof(ElType));
    CAPACITY(*l) -= num;
}

void compactList(ListDin *l){
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
    //ALGORITMA
    BUFFER(*l) = (ElType*) realloc (BUFFER(*l), NEFF(*l)* sizeof(ElType));
    CAPACITY(*l) = NEFF(*l);
}
