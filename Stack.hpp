#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

template <typename Object>
class Stack{
    private:
        //bize önce bir dizi lazım, dizi dedigimiz sey ilk elemanın adresin tutan bir yapı
        Object *items; //dizi olsuturduk
        int topOfStack;
        int capacity;
        
        void reserve(int newCapacity){
            Object* tmp = new Object[newCapacity];
            for (int i = 0; i < capacity; i++){
                tmp[i] = items[i];
            }//tüm verileri kopyalardık
            delete [] items; // [] items bir dizi gosteriyor
            items = tmp;
            capacity = newCapacity;
        }
    public:
        Stack(){ //yigit nesnesi olustu
            capacity = 100;
            topOfStack = -1; //0 gecerli index oyüzden -1 yani olmayanı yazmamız lazım
            items = new Object[capacity];
        }
        bool isEmpty(){
            return topOfStack == -1;
        }
        void clear(){
            topOfStack = -1; //varsayılan baslangıc konumuna dondu
        }
        void push(const Object& item){
            if(topOfStack + 1 == capacity) reserve(2*capacity);// +1 in sebebi 0. indexten basladıgı icin
            //if i atlıyorsa ekleyecegi yer var demektir
            topOfStack++;
            items[topOfStack] = item; //yeni veriyi tepeye ekledim
        }
        const Object& top(){//silemden cıkkmak üzere olanı gostern func.
            if(isEmpty()) throw "veri yok!";
            return items[topOfStack];
        }
        void pop(){
            if(isEmpty()) throw "veri yok!";
            topOfStack--; //en usttekini attık
        }
        ~Stack(){ //bir yıgıt nesnesi olusunca aynı zamanda dizi olusuyor ve  bunu iade etmemiz lazım
            delete  [] items;
        }
};

#endif