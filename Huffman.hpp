#ifndef HUFFMANN_HPP
#define HUFFMANN_HPP

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Dugum{
    public:
        char karakter;
        int frekans;
        string kod;
        Dugum *sol;
        Dugum *sag;  

        Dugum(char kr, int frek, Dugum *sl = NULL, Dugum *sg = NULL);
        bool yaprakMi() const;
        bool operator == (Dugum&);
        bool operator != (Dugum&);
        bool operator > (Dugum&);
};

class Huffman{
    private:
        int harfler;
        string girdi;
        Dugum *kok;
        Dugum* AgacOlustur(int frek[]);
        void KodOlustur(Dugum*, string);
        int minDugumIndex(Dugum* dugumler[]);
        void dosyaOku(string);
        void inorder(Dugum*);
        void silDugum(Dugum*&);

    public:
        Huffman(string);
        void Kodla();
        friend ostream& operator<<(ostream&, Huffman&);
        ~Huffman();
};

#endif