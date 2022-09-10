#include <iostream>
using namespace std;

//bir fonksiyona dizinin tamamı gonderilemez, ilk elemanının adresi gonderilir oyuzden dizi[]  veya *dizi seklinde parametre girilebilir
/*int Uzunluk(int dizi[]) {
return sizeof(dizi)/sizeof(int); //1 döndorur cunku hesaplayamaz adresin degeri 4 int deeri 4 her durumda 1 cıkaracaktır bu sekilde  kullanılmaz lokal dizinin uzunlugu hesaplanabilirken fonksiyon oalrak zuunluk hesabı yapılmaz
}*/ // hatalı kullanım

int* diziOlusturSifirla(int length) //uzunluk degerini dısaridan hesaplayamadıgımız icin parametre olarak gondermeliyiz
{
    int *Dizi = new int[length];//olusturdugum dizinin calısma anında silinmemesi icin heap bellek bolgesinde olusturuyorum
    for(int i = 0; i < length; i++)//tek tek elemanları dolasıp, sıfır atıyorum
    {
        Dizi[i] = 0;
    }
    return Dizi;
}  

int* diziKopyala(int *kaynak, int length) //kaynak ilk elemanın adresi oldugu icin pointer poalrak parametre girildi
{
    int *hedef = new int[length];
    for(int i = 0; i < length; i++) //elemanları tek tek kopayalıyorum
    {
        hedef[i] = kaynak[i];
    }
    return hedef;
} 

bool diziKarsilastir(int *d1, int u1, int *d2, int u2) 
{
    if(u1 != u2) return false;
    for(int i = 0; i < u1; i++) {
        if(d1[i] != d2[i]) return false;
    }
    return true;
} 

int main() {
    int sayilar[] = {5,10,15};
    int *p = sayilar;
    cout<<*p<<endl; //ilk hücrenin adresini tuttugu icin ekrana 5 yazdırır
    p++;
    cout<<*p<<endl; // pointerın kendi degerini 1 arttırdıgım icin, 2. hücrenin degerini yazdırdı.
    cout<<"uzunluk: "<<sizeof(sayilar)/sizeof(int)<<endl; // 12/4 = 3
    //cout<<"uzunluk: "<<Uzunluk(sayilar)<<endl; // hatalı kullanım
    cout<<" -------------------"<<endl;


    int length;
    cout<<"diziOlusturSifirla func. icin uzunluk girin:"<<endl;
    cin>>length;
    int *k = diziOlusturSifirla(length);
    cout<<k[3]<<endl; //3. elemanı yazdıracak hepsi sıfır oldugu icin 0 gelir ekrana  
    cout<<" -------------------"<<endl;


    int l[] = {10,20,30};
    int *r;
    r = diziKopyala(p,3); // r dizi p nin aynısı ama heapte p rts de
    r[0] = 100;
    cout<<p[0]<<endl; // p nin degerinin degismedigini goruruz r degisti sadece cunku iki bagımsız dizi 
    delete [] r; // p yi silmeme gerek yok o heapte degil
    cout<<" -------------------"<<endl;


    int m[] = {10,20,30};
    int n[] = {10,20,30};
    if(diziKarsilastir(m,3,n,3)) cout<<"diziler esit"<<endl;
    else cout<<"diizler esit degil"<<endl;
    cout<<" -------------------"<<endl;

    return 0;
}