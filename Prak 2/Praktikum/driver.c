#include <stdio.h>
#include "garis.h"
#include "vector.h"


// int main(){
//     GARIS l1,l2;
//     printf("Garis pertama: \n");
//     BacaGARIS(&l1);
//     printf("\nGaris kedua: \n");
//     BacaGARIS(&l2);
//     TulisGARIS(l1);
//     TulisGARIS(l2);
//     printf("\nPanjang garis %.02f\n",PanjangGARIS(l1));
//     printf("\nGradien garis 1 %.02f\n",Gradien(l1));
//     printf("\nGradien garis 2 %.02f\n",Gradien(l2));
//     TulisGARIS(l1);
//     if (IsTegakLurus(l1,l2)) {
//         printf("\ntegak lurus\n");
//     } else {
//         printf("\nnggak tegak lurus\n");
//     }
//     if (IsSejajar(l1,l2)) {
//         printf("\nsejajar\n");
//     } else {
//         printf("\nnggak sejajar\n");
//     }


// }

int main(){
    VECTOR v1,v2, v3, v4;
    float x,y;
    scanf("%f %f", &x, &y);
    v1=MakeVector(x,y);
    TulisVector(v1);
    scanf("%f %f", &x, &y);
    v2=MakeVector(x,y);
    TulisVector(v2);
    printf("\n%f", Magnitude(v1));
    v3 = Add(v1,v2);
    printf("\n");
    TulisVector(v3);
    v4 = Substract(v1,v2);
    printf("\n");
    TulisVector(v4);
    printf("\nHasil dot %f", Dot(v1,v2));
   
    TulisVector(Multiply(v1, 2));

}
