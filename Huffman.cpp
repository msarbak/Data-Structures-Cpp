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

}
void Huffman::KodOlustur(Dugum*, string){

}
int Huffman::minDugumIndex(Dugum* dugumler[]){

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
void Huffman::silDugum(Dugum*&){

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
    
    
}
ostream& operator<<(ostream&, Huffman&);
Huffman::~Huffman(){

}


int main() {

    return 0;
}