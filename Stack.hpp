#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

template <typename Object>
struct Node{
    Object data; //veri
    Node<Object> *next; //adres

    Node(Object data, Node<Object> *nx=NULL) {//parametre girilmezse null oalcak
        this->data = data;
        this->next = nx;
    }
};

template <typename Object>
class Stack{
    private:
        //bize önce bir dizi lazım, dizi dedigimiz sey ilk elemanın adresin tutan bir yapı
        //Object *items; //dizi olsuturduk
        //int topOfStack;
        //int capacity;
        
        Node<Object> *topOfStack;

        /*void reserve(int newCapacity){
            Object* tmp = new Object[newCapacity];
            for (int i = 0; i < capacity; i++){
                tmp[i] = items[i];
            }//tüm verileri kopyalardık
            delete [] items; // [] items bir dizi gosteriyor
            items = tmp;
            capacity = newCapacity;
        }*/
        // BUNA GEREK KALMADI LISTE UZERINDE GERCEKLESTIRECEGIMIZ ICIN
    public:
        Stack(){ //yigit nesnesi olustu
            /* capacity = 100;
            topOfStack = -1; //0 gecerli index oyüzden -1 yani olmayanı yazmamız lazım
            items = new Object[capacity]; */

            topOfStack = NULL;
        }
        bool isEmpty(){
            //return topOfStack == -1;
            return topOfStack == NULL;
        }
        void clear(){
            //topOfStack = -1; //varsayılan baslangıc konumuna dondu

            while(!isEmpty()) pop(); //tek tek hepsini silecek 
        }
        void push(const Object& item){
            /*if(topOfStack + 1 == capacity) reserve(2*capacity);// +1 in sebebi 0. indexten basladıgı icin
            //if i atlıyorsa ekleyecegi yer var demektir
            topOfStack++;
            items[topOfStack] = item; //yeni veriyi tepeye ekledim*/

           topOfStack = new Node<Object>(item,topOfStack); //new -> olusan yenidugumun adresini dondurecek

        }
        const Object& top(){//silemden cıkkmak üzere olanı gostern func.
            if(isEmpty()) throw "veri yok!";
            //return items[topOfStack];
            return topOfStack->data; //dısarısı veri ile ilgilenir adresle ilgilnemez
        }
        void pop(){
            if(isEmpty()) throw "veri yok!";
            //topOfStack--; //en usttekini attık

            Node<Object> *del = topOfStack;
            topOfStack = topOfStack->next; // topofstack artık bir ilerisini gosterecek ve sonraki adımda delin gosterdigi eski topfstacki iade edp eleman cıakracagız
            delete del;
        }
        ~Stack(){ //bir yıgıt nesnesi olusunca aynı zamanda dizi olusuyor ve  bunu iade etmemiz lazım
            //delete  [] items;
            clear();
        }
};

#endif