#include "Huffman.hpp"

Dugum::Dugum(char kr, int frek, Dugum *sl, Dugum *sg){
    karakter = kr;
    frekans = frek;
    sol = sl;
    sag = sg;
    kod = "";
}
bool Dugum::yaprakMi() const{
    return sol == NULL && sag == NULL;
}
bool Dugum::operator == (Dugum& sg){
    return this->karakter == sg.karakter;
}
bool Dugum::operator != (Dugum& sg){
    return this->karakter != sg.karakter;
}
bool Dugum::operator > (Dugum& sg){
    return this->karakter > sg.karakter;
}



Dugum* Huffman::AgacOlustur(int frek[]){
    Dugum* dugumler[harfler];
    for (int i = 0; i < harfler; i++){
        if(frek[i] > 0) {
            dugumler[i] = new Dugum((char)i,frek[i]);
        } else {
            dugumler[i] = NULL;
        }
    }
    while(true) {
        int ilkIndex = minDugumIndex(dugumler);
        Dugum *min1 = dugumler[ilkIndex];
        dugumler[ilkIndex] = NULL;

        int ikinciIndex = minDugumIndex(dugumler);
        if(ikinciIndex == -1) {
            return min1;
        }

        Dugum *min2 = dugumler[ikinciIndex];
        dugumler[ikinciIndex] = NULL;
        dugumler[ilkIndex] = new Dugum(0, min1->frekans + min2->frekans, min1, min2);
    }
}
void Huffman::KodOlustur(Dugum* altdugum, string kod){
    if(altdugum == NULL) return;
    if(!altdugum->yaprakMi()) {
        KodOlustur(altdugum->sol, kod + "0");
        KodOlustur(altdugum->sag, kod + "1");
    } else{
        altdugum->kod = kod;
    }
}
int Huffman::minDugumIndex(Dugum* dugumler[]){
    Dugum *min;
    int minindeks = -1;

    for (int i = 0; i < harfler; i++){
        if(dugumler[i] != NULL) continue;
        if(*min > *(dugumler[i])) {
            min = dugumler[i];
            minindeks = i;
        }
    }
    return minindeks;
    
}
void Huffman::dosyaOku(string dosyaYolu){
    string satir;
    ifstream dosya(dosyaYolu.c_str());
    if(dosya.is_open()){
        while(getline(dosya,satir)){
            girdi += satir;
            girdi += "/n";
        }
        dosya.close(); //dongu tamamalndıgında dosya iceriginin tamamı satır satır girdi isimli string de olacaktır
    }else{
        throw "dosya acilamadi!";
    }
}
void Huffman::inorder(Dugum*){

}
void Huffman::silDugum(Dugum*& altDugum){
    if(altDugum == NULL) return;
    silDugum(altDugum->sol);
    silDugum(altDugum->sag);
    delete altDugum;
    altDugum = NULL; 
}
Huffman::Huffman(string dosyaYolu){
    harfler = 256;
    girdi = "";
    dosyaOku(dosyaYolu);
    kok = NULL;
}
void Huffman::Kodla(){
    char karakterler[girdi.size() - 1];
    strcpy(karakterler,girdi.c_str());
    int frek[harfler];
    for (int i = 0; i < harfler; i++){
        frek[i] = 0;
    }
    for (int i = 0; i < girdi.size() - 1; i++){
        frek[karakterler[i]]++;
    }
    kok = AgacOlustur(frek);
    KodOlustur(kok,"");
    
}
ostream& operator<<(ostream& ekran, Huffman& sag){
    ekran<<"Huffman agacindaki karakterler ve kodlari: "<<endl;
    sag.inorder(sag.kok);
    return ekran;
}
Huffman::~Huffman(){

}


int main() {

    return 0;
}