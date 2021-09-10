/* File: vector.h */
/* Tanggal: 02 September 2021 */

#include "vector.h"
#include <math.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
VECTOR MakeVector(float x, float y)
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */
{
    /* Kamus Lokal */
    VECTOR v;
    /* Algoritma */
    v = MakePOINT(x,y);
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v)
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */
{
    /* Kamus Lokal */
    /* Algoritma */
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}
/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v)
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
{
    /* Kamus Lokal */
    float x, y;
    /* Algoritma */
    x = AbsisComponent(v);
    y = OrdinatComponent(v);
    return (sqrt(x*x+y*y));
}

VECTOR Add(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
{
    /* Kamus Lokal */
    float atemp, btemp;
    /* Algoritma */
    atemp = AbsisComponent(a) + AbsisComponent(b);
    btemp = OrdinatComponent(a) + OrdinatComponent(b);
    return MakeVector(atemp,btemp);
}

VECTOR Substract(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
{
    /* Kamus Lokal */
    float atemp, btemp;
    /* Algoritma */
    atemp = AbsisComponent(a) - AbsisComponent(b);
    btemp = OrdinatComponent(a) - OrdinatComponent(b);
    return MakeVector(atemp,btemp);
}

float Dot(VECTOR a, VECTOR b)
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
{
    /* Kamus Lokal */
    float ax, ay, bx, by;
    /* Algoritma */
    ax = AbsisComponent(a);
    ay = OrdinatComponent(a);
    bx = AbsisComponent(b);
    by = OrdinatComponent(b);
    return ((ax*bx)+(ay*by));
}

VECTOR Multiply(VECTOR v, float s)
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * a.x, s * a.y) */
{
    /* Kamus Lokal */
    float new_x, new_y;
    /* Algoritma */
    new_x = AbsisComponent(v) * s;
    new_y = OrdinatComponent(v) * s;
    return (MakeVector(new_x,new_y));
}