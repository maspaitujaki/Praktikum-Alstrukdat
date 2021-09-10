
#include <stdio.h>
#include "time.h"

int main(){
    /* Kamus */
    TIME t, t2;
    long detik = 54000;
    int N;
    /* Algoritma */
    BacaTIME(&t);

    printf("\nWaktu terbaca: ");
    TulisTIME(t);
    printf(" atau setara dengan %ld detik\n", TIMEToDetik(t));
    printf("Misalkan kita memiliki jumlah detik sebesar %ld detik atau pukul ", detik);
    t2 = DetikToTIME(detik);
    TulisTIME(t2);

    if (TEQ(t,t2)){
        printf("\nKedua ADT time tersebut bernilai sama");
    } else if (TNEQ(t,t2)) {
        printf("\nKedua ADT time tersebut tidak bernilai sama");
    }

    if (TLT(t,t2)) {
        printf("\nTime pertama lebih awal dari Time kedua");
    } else if (TGT(t,t2)) {
        printf("\nTime pertama lebih telat dari Time kedua");
    }
    printf("\nSatu detik setelah Time kita adalah ");
    TulisTIME(NextDetik(t));
    printf("\nMasukkan N detik untuk ditambahkan ke Time: ");
    scanf("%d", &N);
    printf("\nTime kita setelah ditambah N detik menjadi ");
    TulisTIME(NextNDetik(t, N));

    printf("\nSatu detik sebelum Time kita adalah ");
    TulisTIME(PrevDetik(t));
    printf("\nMasukkan N detik untuk dikurangkan dari Time: ");
    scanf("%d", &N);
    printf("\nTime kita setelah dikurangkan N detik menjadi ");
    TulisTIME(PrevNDetik(t, N));

    printf("\nTerakhir, durasi atau jangka waktu dari dua Time yang kita miliki adalah %ld detik", Durasi(t,t2));


    return 0;
}
