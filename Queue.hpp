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
        //length kapasiteye esit olmadıgı sürece yer var demektir 
        //referans noktam uzunluk, uuznluk sıfırsa kuyrukta eleman yoktur
        void reserve(int newCapacity) {
            Object *tmp = new Object[newCapacity];
            for (int j = 0, i = front; j < length; j++){ //kuyruk sıfırdan baslamıyor olabilir, tmp i biz belirledigimiz ici o sıralı fakat i yani items garanti olması acısından front tan baslatmamız gerekiyor
            //j yi birer artıyoruoruz i yi dizinin dısında tasmaması adına modunu alarak arttıracagız
                tmp[j] = items[i];
                i = (i + 1) % capacity;  // dizi arasındaki boslukları alıyorum aslında burada
            } 
            capacity = newCapacity; //kapasite degisti
            delete [] items; //eski diziyi iade ediyorum
            items = tmp; // artık items yeni diziyi gosterecek
            front = 0; // artık frontun 0. adres olduguna eminim (tmp de duzenledik yukarıdaki for dongusunde)
            back = length - 1; //front gibi duzenlengigi icin dogal olarak en sondaki adresde
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
        bool isEmpty()const{
            return length == 0;
        }
        //yıgıttaki top func. gibi , cıkmak ğzere olan veriyi gosterecek func.:
        const Object& peek(){ //sadece okuma amaclı bir func.
            if(isEmpty()) throw "queue is empty!";
            return items[front]; // front indexi neredeyse veri oradadır
        }
        void enqueue(const Object& item) {
            if(length == capacity) reserve(2*capacity);
            back = (back + 1) % capacity; //bir hata olmaması adına yine mod alarak gidiyorum
            //elemanı ekleemden once kuyrugun sonunu ilerletecegim daha sonrasında eklenecek
            items[back] = item; // back'in icinde oldugu index'e yeni veriyi ekliyorum
            length++; // sonrasında eleman sayısı arttı
        }
        void dequeue(const Object& item){
            //eklemenin tersi bu sefer back degil front ilerleyecek
            if(isEmpty()) throw "queue is empty!";
            front = (front + 1) % capacity;
            length--;
        }
        ~Queue(){
            delete [] items;
        }
};

#endif