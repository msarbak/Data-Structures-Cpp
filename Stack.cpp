#include "Stack.hpp"

string TabanDonustur(int sayi, int donusturulecekTaban){
    Stack<int> *yigit = new Stack<int>(); // newin dondurdugu deger her zman adrestir
    string rakamlar = "012344567889ABCDEF";
    string yeniSayi = "";
    while(sayi > 0 ){
        int kalan = sayi % donusturulecekTaban;
        yigit->push(kalan);
        sayi = sayi / donusturulecekTaban;
    }
    while(!yigit->isEmpty()){
        yeniSayi = yeniSayi + rakamlar[yigit->top()];
        yigit->pop(); //vburadan sonra sayıyı elde ettik
    }
    delete yigit;
    return yeniSayi;
}

int main(){
    int sayi, taban;
    cout<<"10 tabaninda sayi: ";
    cin>>sayi;
    cout<<"Donusturulecek Taban: ";
    cin>>taban;
    cout<<"Yeni Sayi: "<<TabanDonustur(sayi,taban);
    return 0;
}