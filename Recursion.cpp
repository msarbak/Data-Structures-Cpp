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
     int ortaindis = (baslangic + bitis) / 2;
     if(bitis < baslangic) return false; //hatalı durum, durdum
     if(sayilar[ortaindis] == aranan) return true;  //aranan tam ortada durdum
     if(aranan < sayilar[ortaindis]) {
        return ikiliArama(sayilar, baslangic, ortaindis - 1, aranan);
        } //solda arama
     else {
        return ikiliArama(sayilar, ortaindis + 1, bitis, aranan);
        }  //sagda arama
}

int main() {
    int sayilar[] = {27,46,17,90,63};
    diziTersCevir(sayilar, 5);
    for (int index = 0; index < 5; index++){
        cout<<sayilar[index]<<" ";
    }
    cout<<" -------------------"<<endl;


    int dizi[] = {17,27,46,63,90,112,125,140,157};
    int sayi;
    cout<<"Aranan Sayiyi giriniz: "<<endl;
    cin>>sayi;
    if(ikiliArama(dizi,0,8,sayi)) {
        cout<<"Aranan sayi dizide VARDIR"<<endl;
        }
    else {
        cout<<"Aranan sayi dizide YOKTUR"<<endl;
    }
    cout<<" -------------------"<<endl;
    
    return 0;
}