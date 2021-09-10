
#include <stdio.h>
#include "point.h"
int main(){
    /* Kamus */
    POINT p1, p2;
    float gx, gy, arc;
    /* Algoritma */
    printf("Hello Guys, selamat datang di program point \n");
    printf("\nMasukkan nilai absis dan ordinat point pertama: ");
    BacaPOINT(&p1);
    printf("\nMasukkan nilai absis dan ordinat point kedua: ");
    BacaPOINT(&p2);
    printf("\nPoint yang terbaca ");
    TulisPOINT(p1);
    printf(" dan ");
    TulisPOINT(p2);

    printf("\nMenjalankan Test....\n");

    if (EQ(p1,p2)){
        printf("Point 1 dan 2 adalah sama\n");
    } else if (NEQ(p1,p2)){
        printf("Point 1 dan 2 tidak sama\n");
    }

    if (IsOrigin(p1)){
        printf("Point 1 adalah titik origin\n");
    }
    if (IsOnSbX(p1)){
        printf("Point 1 terletak di sumbu x\n");
    }
    if (IsOnSbY(p1)){
        printf("Point 1 terletak di sumbu y\n");
    }
    printf("Point 1 terletak di kuadran %d", Kuadran(p1));
    printf("\nApabila digeser sejauh satu sejajar sumbu x positif, point 1 menjadi ");
    TulisPOINT(NextX(p1));
    printf("\nApabila digeser sejauh satu sejajar sumbu y positif, point 1 menjadi ");
    TulisPOINT(NextY(p1));

    printf("\nTest geser point sejajar sumbu x sebesar: ");
    scanf("%f", &gx);
    printf("\nTest geser point sejajar sumbu y sebesar: ");
    scanf("%f", &gy);
    printf("\nHasil apabila digeser: ");
    TulisPOINT(PlusDelta(p1,gx,gy));

    printf("\nPoint 1 apabila dicerminkan terhadap sumbu x: ");
    TulisPOINT(MirrorOf(p1, true));
    printf("\nPoint 1 apabila dicerminkan terhadap sumbu x: ");
    TulisPOINT(MirrorOf(p1, false));

    printf("\nJarak point ke titik pusat: %f\n", Jarak0(p1));
    printf("Panjang garis antara point 1 dan 2 : %f\n", Panjang(p1,p2));

    printf("\nGeser point sejajar sumbu x sebesar: ");
    scanf("%f", &gx);
    printf("\nGeser point sejajar sumbu y sebesar: ");
    scanf("%f", &gy);
    printf("\nMenggeser point menjadi: ");
    Geser(&p1,gx,gy);
    TulisPOINT(p1);

    printf("\nMenggeser point ke sumbu x menjadi: ");
    GeserKeSbX(&p1);
    TulisPOINT(p1);

    printf("\nMenggeser point ke sumbu y menjadi: ");
    GeserKeSbY(&p1);
    TulisPOINT(p1);

    printf("\nMencerminkan point terhadap sumbu x menjadi: ");
    Mirror(&p1, true);
    TulisPOINT(p1);
    printf("\nMencerminkan point terhadap sumbu y menjadi: ");
    Mirror(&p1, false);
    TulisPOINT(p1);

    printf("\nPutar point sejauh berapa derajat: ");
    scanf("%f",&arc);
    printf("\nPoint diputar menjadi: ");
    Putar(&p1, arc);
    TulisPOINT(p1);



   return 0;
}
