//ilk gelen ilk hizmet gorur, gercek hayat problemlerinde  kullanılan aktif bir veri yapısı
//hem dizi hemde liste üzerinde gösterecegiz, ekleme cıkarmayı sınırlandıracagız
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;

template <typename Object>
struct Node{
    Object item;
    Node<Object> *next;

    Node(Object item, Node<Object> *next = NULL){ //girilmezse null a aesitle varsayılan parametre
        this->item = item;
        this->next = next;
    }
};

template <typename Object>
class Queue{
    private:
        Node<Object> *front; // veri silinirse harekt edecek 
        Node<Object> *back; // veri eklenirse harekt edecek 
        int length; // uzunluk da lazım
        Node<Object> *previousMaxNode(){
            //kuyrugu kullanan belirleyecek
            Node<Object> *prev = NULL;
            Node<Object> *tmp = front;
            Object max = front->item; //ilk dugumun verisini baslangic icin max kabul ediyorum
            while(tmp->next != NULL) { //oncesine yerlestirdigimiz icin sorasını kontro lediyoruz
                if(tmp->next->item > max) {
                    max = tmp->next->item; //sonraki deger max dan büyüksee yeni max o olur ve bu duurmda prev artık tmp'tir
                    prev = tmp;
                }
                tmp = tmp->next;
            }
            return prev;
        }

        //dizi üzerinde degil düğüm üzerinde gostercegiz, bunalr artık tam sayı degil adres olacak o yüzden iptal ettik
        /* int front;
        int back;
        int capacity;
        int length;
        Object *items; //dizinin ilk elemnaını gosteren pointer
        //length kapasiteye esit olmadıgı sürece yer var demektir 
        //referans noktam uzunluk, uuznluk sıfırsa kuyrukta eleman yoktur */

        //reserve e de gerek kalmadı dizi gibi dolmaz cunku liste sürekli ekelme yapılabilir
        /*void reserve(int newCapacity) {
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
        }*/
    public:
        Queue(){
            front = back = NULL;
            length = 0;
        }
        
        /*Queue() { //kurucu method
            capacity = 100;
            front = 0;
            back = -1;
            length = 0;
            items = new Object[capacity];
        }*/
        void clear() {
           while(!isEmpty()) dequeue(); // teker teker tüğm dügümler yokedilecek
        }
        /*void clear() {
            front = 0;
            back = -1;
            length = 0; //array listte sadece lentghi sıfırlamıstık amac yapıyı baslangıc konumuna getirmek :)
        }*/
        int count()const{ //get methodu, sabis bir func.
            return length;
        }
        bool isEmpty()const{
            return length == 0;
        }
        //yıgıttaki top func. gibi , cıkmak ğzere olan veriyi gosterecek func.:
        const Object& peek(){ //sadece okuma amaclı bir func.
            if(isEmpty()) throw "queue is empty!";
            return front->item;
        }
        /*const Object& peek(){ //sadece okuma amaclı bir func.
            if(isEmpty()) throw "queue is empty!";
            return items[front]; // front indexi neredeyse veri oradadır
        }*/
        const Object& peekMax(){ //sadece okuma amaclı bir func.
            if(isEmpty()) throw "queue is empty!";
            Node<Object> *prev = previousMaxNode; //bir öncesine yerlesiyor
            if(prev == NULL) return peek();
            return prev->next->item;
        }
        void enqueue(const Object& item) {
            Node<Object> *last = new Node<Object>(item);
            if(isEmpty()) front = back = last;
            else{
                back->next = last; //last heapte fakat lokal bir pointer func. kapandıgında silinecek 
                back = last; // kaybolamması icin backi yeniden tanımlkyorum
            }
            length++;
        }
       /* void enqueue(const Object& item) {
            if(length == capacity) reserve(2*capacity);
            back = (back + 1) % capacity; //bir hata olmaması adına yine mod alarak gidiyorum
            //elemanı ekleemden once kuyrugun sonunu ilerletecegim daha sonrasında eklenecek
            items[back] = item; // back'in icinde oldugu index'e yeni veriyi ekliyorum
            length++; // sonrasında eleman sayısı arttı
        }*/
        void dequeue(const Object& item){
            if(isEmpty()) throw "queue is empty!";
            Node<Object> *tmp = front;//cop kalmasın diye gecici bir gostericiye atmam lzaım
            front = front->next; // boylece bastaki silindi
            delete tmp;
            length--;
        }
        /*void dequeue(const Object& item){
            //eklemenin tersi bu sefer back degil front ilerleyecek
            if(isEmpty()) throw "queue is empty!";
            front = (front + 1) % capacity;
            length--;
        }*/
        void dequeueMax(const Object& item){ //oncelikli durumlar icin
            if(isEmpty()) throw "queue is empty!";
            Node<Object> *prev = previousMaxNode;
            Node<Object> *tmp;
            if(prev == NULL) dequeue();
            else{
                if(prev->next == back) back = prev; //previn nexti en son dugumse back artık prev 
                tmp = prev->next;
                prev->next = prev->next->next; //prev->nextini ilerletiyoruz
                delete tmp;
                length--;
            }
        }
        ~Queue(){
            clear();
        }
        /*~Queue(){
            delete [] items;
        }*/
};

#endif