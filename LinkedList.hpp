#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
using namespace std;

template <typename Object>
struct Node{
    Object item; // veri kısmı
    Node<Object> *next;//adres kısmı

    Node(const Object& item, Node<Object> *next = NULL){//kurucu func.
    //dısaridan veri aldım ve adres oalcak
    this->item = item; //itemı aldık once
    this->next = next;
    }
};

template <typename Object>
class LinkedList{
    private:
        Node<Object> *head; //dugum gosterici
        int size;

        Node<Object>* FindPrevByPosition(int position){ //ekleme silmede bir öncesini döndüren bir adrese ihtiyacımız var bunu kullanıcaz
            if(position < 0 || position > size) throw "Index out of range!";
            int index = 1; // bir öncesini bulacagım icin 1 den baslatıyorum 0 dan baslatamam
            for(Node<Object>* itr = head; itr != NULL; itr = itr->next, index++){ //1. dugumun adresini lokal pointera verdim, ilerleme kaydetmek istiyorum. headin degismemei lazım yoksa listeyi kaybederiz. burada degistirecegimiz sey "itr"
            // itr = itr->next demek her turda br ilerlemesi demek
                if(position == index) return itr;
            }
            return NULL; //1. dugumunoncesi istendiyse yok ve null doner (gerekirse)
        }
    public:
        LinkedList(){
            head = NULL; //ilk dugumu gosterecek adres ortada dgum olmadı gı icin null
            size = 0;
        }
        bool isEmpty()const{ //get func.
            return size == 0;
        }
        int count()const{
            return size;
        }
        const Object& first(){ //ilk elemanı getir
            if(isEmpty()) throw "Empty list!";
            return head->item; // head burada dugum adresidir bizden veri getirmemizi istiyor ozman headin itemi seklinde olmalı
        }
        const Object& last(){
            if(isEmpty()) throw "Empty list!";
            return FindPrevByPosition(size)->item; //size aslında son degil ama bir oncesine gittigi icin son olmus oalcak
        }
        void add(const Object& item){
            insert(size,item); //konum size yani sona ekleyecek, neyi ekleyecek item ı
        }
        void insert(int index, const Object& item){
            if(index == 0) head = new Node<Object>(item,head); //head artık yeni eklenen yeri gosteriyor, basa ekleme durumu icin
            //araya ve sona ekleme isi birlestirilebilir:
            else{
                Node<Object> *prev = FindPrevByPosition(index); //bir öncesini bulmak istiyorum
                //bulduktan sonra prev olarak gosterdigim dügümün nexti olarak araya eleman eklerim, onunda nexti previn nexti olur 
                prev->next = new Node<Object>(item,prev->next);
                //burada ilk parametre dugumun verisiydi dolayısıyla item yani yeni istedigimiz veri bu, ikinci parametre next adresiydi dugum yapsıına bakarsak, burada da previn nexti yeni eklenecek dugumun nexti oldu 
                //sornasında da previmnn kendisi lokal pointer oldugu icin silinir fakat gosterdigib heap bellek bolgesinde oldugu icin  silinmeyecektir
            }
            size++; //her kosulda eleman sayisi artacak
        }
        void remove(const Object& item){ // su veriyi sil func.
            int index = indexOf(item);
            removeAt(index);
        }
        void removeAt(int index){ //konumdakini sil func.
            if(size == 0) throw "Empty list!";
            Node<Object> *del; //sielcegim dugumu gosterecek bir lokal pointer tanımlıyorum. çöp olusmamıs icin en son bunun gosterdigini delete diyecegim
            if(index == 0){//ilk elemanı silme durumu
                del = head; //silecegim kısmı dele atıyorum çöp olmasın diye
                head = head->next; //headi bir ilerletiorum
            } else{// aradan veya sondan eleman silme
                Node<Object> *prev = FindPrevByPosition(index);
                del = prev->next;
                prev->next = prev->next->next;
            }
            delete del;
            size--;
        }
        int indexOf(const Object& item){ // verinin adresini getirecek
            int index = 0;
            for(Node<Object> *itr = head; itr != NULL; itr->next,index++){ //listenin basından baslayıp hepsini gezecegim bir dongu   
                if(itr->item == item) return index;
            }
            throw "Index out of range!";
        }
        bool find(const Object& item){ // su veri var mı?
            for(Node<Object> *itr = head; itr != NULL; itr = itr->next){ 
                if(itr->item == item) return true;
            }
            return false;
        }
        friend ostream& operator<<(ostream& screen, LinkedList<Object>& right) {
            if(right.isEmpty()){
                screen<<"Empty List!"<<endl;
            } else {
                for(Node<Object> *itr = head; itr != NULL; itr = itr->next){ 
                screen<<itr->item<<" ";
                }
            }
            return screen;
        }
        void clear() {
            /*head = NULL;
            size = 0; 
            // bu sekilde baslangic konumuna doner ancak butun dugumler cop olarak kalacaktır */
            while(!isEmpty()){ //liste dolu oldugu sürece
                removeAt(0); //her turda en bastakini sil
            }
        }
        ~LinkedList(){
            clear();
        }
};

#endif