//ilk gelen ilk hizmet gorur, gercek hayat problemlerinde  kullanılan aktif bir veri yapısı
//hem dizi hemde liste üzerinde gösterecegiz, ekleme cıkarmayı sınırlandıracagız
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;

template <typename Object>
class Queue{
    private:
        int front;
        int back;
        int capacity;
        int length;
        Object *items; //dizinin ilk elemnaını gosteren pointer

        void reserve(int newCapacity) {
            Object *tmp = new Object[newCapacity];
            for (int i = 0; i < length; i++){
                tmp[i] = items[i];
            }   
        }
    public:
        Queue() { //kurucu method
            capacity = 100;
            front = 0;
            back = -1;
            length = 0;
            items = new Object[capacity];
        }
        void clear() {
            front = 0;
            back = -1;
            length = 0; //array listte sadece lentghi sıfırlamıstık amac yapıyı baslangıc konumuna getirmek :)
        }
        int count()const{ //get methodu, sabis bir func.
            return length;
        }
        bool isempty()const{
            return length == 0;
        }
        void enqueue(const Object& item) {
            if(length == capacity) reserve(2*capacity);
        }
};

#endif