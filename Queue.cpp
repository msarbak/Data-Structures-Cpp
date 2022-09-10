#include "Queue.hpp"
#include <cmath>
//radix sort gercek hayat problemi
// bu algorima icin 10 adet kuyruk gerekli ve dizide tutulurlar

int basamakSayisi(int sayi) {
    sayi = abs(sayi); // herturlu sayiyi positive ceviriyorum, negatif olursa algoritmayı bozuyor
    int basamak = 0;
    while(sayi > 0) {
        basamak++;
        sayi /= 10;
    }
    return basamak;
}

int enYuksekBasamakSayisi(int *items, int length) {
    int max = 0;
    for (int i = 0; i < length; i++){
        if(basamakSayisi(items[i] > max)) {
            max = basamakSayisi(items[i]); // max dan daha buyugunu buldugumda bu sayısı max olarak belirliyorum
        }   
    }
    return max;
    
}

int* radixSort(int* items, int length) {
    Queue<int> **queues = new Queue<int>*[10]; //icinde adres , dizinin kendide adres: çift **
    // 10 tane kuyrugu burada olusturduk
    
}

int main() {

}