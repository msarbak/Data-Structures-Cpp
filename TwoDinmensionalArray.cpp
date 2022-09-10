#include <iostream>
#include <ctime>
using namespace std;

int** MatrisOlustur(int satir, int sutun){
    //int **matris = new int[satir][sutun]; //heapde 2. kısmı olusturamıyoruz boyle kullanamayız, tek boyutlu gibi yapıp pointer tanımlayacagız
    int **matris = new int*[satir];
    for (int i = 0; i < satir; i++){
        matris[i] = new int[sutun];
        for (int j = 0; j < sutun; j++){
            matris[i][j] = rand()%5+1; //1 -5 arasında sayi atıyorum
       }
    }
    return matris;
}

void MatrisYazdir(int** matris, int satir, int sutun){
      for (int i = 0; i < satir; i++){
        cout<<"| ";
        for (int j = 0; j < sutun; j++){
            cout<<matris[i][j]<<" ";
       }
       cout<<" |"<<endl;
    }
}

int** MatrisCarpim(int **matris1, int** matris2, int satir1, int satir2, int sutun2){
    int toplam = 0;
    int** MatrisSonuc = new int*[satir1];
    for(int i = 0; i < satir1; i++) {
        MatrisSonuc[i] = new int[sutun2]; // 1. matrisin satır 2. matrisin sutun bilginde dolasıyoruz
        for(int j = 0; j < sutun2; j++) {
            for(int k = 0; k < satir2; k++) {
                toplam = toplam + matris1[i][k] * matris2[k][j]; // 1. satirda 2. sutunda ilerledigi icin boyle cıktı
            }
            MatrisSonuc[i][j] = toplam; // toplamı kaydediyorum ilgili hücreye
            toplam = 0; //bir sonraki topalma islemi icn sıfırlayıp yer acıyorum
        }
    } 
    return MatrisSonuc;
}

void MatrisYoket(int** matris, int satir){
    for (int i = 0; i < satir; i++){
        delete [] matris[i]; //matris olustur daki for lu ic kısmı yok ediyor
    }
    delete [] matris; // en üstteki kısmını yok ediyor
    
}

int main() {
    //int a[5][4];
    srand(time(NULL));  // her calıstırmada farklı sayı uretmek ıcın 
    int **A = MatrisOlustur(3,4);
    int **B = MatrisOlustur(4,3);
    cout<<"A:"<<endl;
    MatrisYazdir(A,3,4);
    cout<<"\nB:"<<endl;
    MatrisYazdir(B,4,3);
    int** sonuc = MatrisCarpim(A,B,3,4,3);
    cout<<"\nA x B:"<<endl;
    MatrisYazdir(sonuc,3,3);

    MatrisYoket(A,3);
    MatrisYoket(B,4);
    MatrisYoket(sonuc,3);
    return 0;
}