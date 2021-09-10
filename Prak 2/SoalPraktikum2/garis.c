/* File: garis.c */
/* Tanggal: 02 September 2021 */
/* Definisi ADT GARIS, menggunakan ADT point */

#include "garis.h"
#include "math.h"
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void MakeGARIS (POINT P1, POINT P2, GARIS * L)
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */
{
    /* Kamus Lokal */
    /* Algoritma */
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}
/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS (GARIS * L)
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */
{
    /* Kamus Lokal */
    POINT p1, p2;
    /* Algoritma */
    do {
        printf("Masukkan absis ordinat titik awal setelah itu titik akhir: ");
        BacaPOINT(&p1);
        BacaPOINT(&p2);
        if ((Absis(p1) == Absis(p2)) && (Ordinat(p1) == Ordinat(p2))){
            printf("\nGaris tidak valid\n");
        }
    } while (!((Absis(p1) == Absis(p2)) && (Ordinat(p1) == Ordinat(p2))));
    
}

void TulisGARIS (GARIS L)
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
{
    /* Kamus Lokal */
    /* Algoritma */
    printf("(");
    TulisPOINT(PAwal(L));
    printf(",");
    TulisPOINT(PAkhir(L));
}
/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L)
/* Menghitung panjang garis L : berikan rumusnya */
/* Rumus nya adalah akar dari absolut absis1-absis2 ditambah dengan absolut ordinat1-ordinat2 */
{
    /* Kamus Lokal */
    float x1,x2,y1,y2;
    /* Algoritma */
    x1 = Absis(PAwal(L));
    x2 = Absis(PAkhir(L));
    y1 = Ordinat(PAwal(L));
    y2 = Ordinat(PAkhir(L));
    return (sqrt((fabs(x1 - x2) * fabs(x1 - x2)) + (fabs(y1 - y2) * fabs(y1 - y2))));

}
float Gradien (GARIS L)
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
{
    /* Kamus Lokal */
    float x1,x2,y1,y2;
    /* Algoritma */
    x1 = Absis(PAwal(L));
    x2 = Absis(PAkhir(L));
    y1 = Ordinat(PAwal(L));
    y2 = Ordinat(PAkhir(L));
    return ((y2-y1) / (x2-x1));
}
void GeserGARIS (GARIS * L, float deltaX, float deltaY)
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */
{
    /* Kamus Lokal */
    /* Algoritma */
    Geser(&PAwal(*L),deltaX,deltaY);
    Geser(&PAkhir(*L),deltaX,deltaY);
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2)
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
{
    /* Kamus Lokal */
    float g1,g2;
    /* Algoritma */
    g1 = Gradien(L1);
    g2 = Gradien(L2);
    return ((g1*g2) == -1);
}

boolean IsSejajar (GARIS L1, GARIS L2)
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
{
    /* Kamus Lokal */
    float g1,g2;
    /* Algoritma */
    g1 = Gradien(L1);
    g2 = Gradien(L2);
    return(g1==g2);
}