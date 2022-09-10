#include <iostream>
using namespace std;

void diziTersCevir(int dizi[], int uzunluk) {
    if(uzunluk > 1) {
        int tmp = dizi[0];
        dizi[0] = dizi[uzunluk - 1];
        dizi[uzunluk - 1] = tmp;
        
        diziTersCevir(dizi + 1, uzunluk - 2);
    } 
}

bool ikiliArama(int sayilar[], int baslangic, int bitis, int aranan){
    
}

int main() {
    int sayilar[] = {27,46,17,90,63};
    diziTersCevir(sayilar, 5);
    for (int index = 0; index < 5; index++){
        cout<<sayilar[index]<<" ";
    }
    cout<<" -------------------"<<endl;


    int dizi[] = {17,27,46,63,90,112,125,140,157};

    return 0;
}