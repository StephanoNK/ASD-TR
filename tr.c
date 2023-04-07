#include <stdio.h>
#include <stdlib.h>

struct mobil{
    char ID[5], nama[100], warna[30];
    int tahun;
    long harga;
    struct mobil* prev;
    struct mobil* next;
};
struct mobil *mobil = NULL;

int main(){
    printf("Hai.");
    return 0;
}