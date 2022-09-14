#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <cmath>

using namespace std;
#define SIZE 1000

template <typename Object>
class BST{
    private:
        Object *items;
        int condition[SIZE]; //durum dizisi

        int indexOf(const Object& item){
            int currentIndex = 0; //ben ekledim derlemiyordu
             while(true) {
                if(currentIndex >= SIZE || condition[currentIndex] == 0) return -1;
                else if(item < items[currentIndex]) currentIndex = 2 * currentIndex + 1;
                else if (item > items[currentIndex]) currentIndex = 2 * currentIndex + 2;
                else if(items[currentIndex] == item && condition[currentIndex] == 1) 
                    return currentIndex;
            }
        }
    public:
        BST(){
            items = new Object[SIZE];
            clear();
        }
        void clear(){ // tek tek her yere 0 atıyoruz
            for (int i = 0; i < SIZE; i++){
                condition[i] = 0; 
            }
        }
        void add(const Object& item){
            int currentIndex = 0;
            while(true) {//ne akdar asagi inecegimi kestiremedigim iicn  buarada sonsuz dongu tasarlıyorum 
                if(condition[currentIndex] == 0) {
                    //bos noktaya geldim demektir
                    items[currentIndex] = item; // yeni veriyi ekledilk
                    condition[currentIndex] = 1; //artık doldu
                    break;
                }
                else if(item < items[currentIndex]) { //dolu noktaya geldigmiz durum
                    currentIndex = 2 * currentIndex + 1; //üzerinde bulundugumuz dugumun sol cocuga inecegiz
                }
                else if (item > items[currentIndex]) {
                    //verinin buyuk olma ihtimali, b usefer sag cocucga ekleyecegiz
                    currentIndex = 2 * currentIndex + 2;
                }
                else return; //esit olma durumu, amac aramak oldugu icin kac tane oldugunun onemi yok varsa vardır. ekleme yapmıyoruz cunku aynı veri zaten var
            }
        }
        bool search(const Object& item){ //arayacagım elemanı aprametre olarak alacagım
            //nos noktaya geldiysem eleman yoktur, veriyi bulduysam ture dondurecegim
            return indexOf(item) != -1;
        }
        void inorder(int currentIndex = 0){ //bize parametre gondermez kendi icinde kokden baslayıp cagırır
               if(currentIndex < SIZE && condition[currentIndex] != 0) {
                    inorder(2 * currentIndex  + 1); //solcocugun indeksini cagırmamız lazım
                    cout<<items[currentIndex]<<" ";
                    inorder(2 * currentIndex + 2); //oz yinelemeli inorder dolasım
               }
               //else durumu durma noktası 
        }
        void preorder(int currentIndex = 0){
               if(currentIndex < SIZE && condition[currentIndex] != 0) {
                //once kendisi sonra cocuklar
                    cout<<items[currentIndex]<<" ";
                    preorder(2 * currentIndex + 1);
                    preorder(2 * currentIndex + 2);
               }
        }
        void postorder(int currentIndex = 0){
               if(currentIndex < SIZE && condition[currentIndex] != 0) {
                    postorder(2 * currentIndex + 1);
                    postorder(2 * currentIndex + 2);
                    cout<<items[currentIndex]<<" ";
                    //once cocuklar sonra dugumun kendisi
               }
        }
        void levelorder(int currentIndex = 0){ //parametreyi yine ben ekledim derlenmiylordu
              for (int i = 0; i < SIZE; i++){ //seviye bazlı oldugu icin direkt 0 dan baslayıp donebiliriz
                if(condition[i] == 1) { //dugum var demektir
                    cout<<items[currentIndex]<<" "; //ekrana dugumu yazıyorum
                }
              }
              
        }
        ~BST(){
            delete [] items;
        }
        
};
#endif