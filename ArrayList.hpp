#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
using namespace std;

template <typename Object>
class ArrayList {
    private:
        Object *items;
        int length;
        int capacity;
        //---------
        void reserve(int newCapacity){
            Object *tmp = new Object[newCapacity]; //tmp lokal bir pointer fakat gosterdigi yer heap bellek bolgesinde, tmp yok edilecek ve dizi kaybetmemem lazım;
            for(int index = 0; index < length; index++){
                tmp[index]=items[index];
            }
            delete [] items; // items dizini yok ettim cunku kullanmayacagım, icerigini zaten tmp'e yedekledim .simdi yeni kapaistesiyle olusturdugum itemse tempden verileri geri yükleyip tempide silecegim
            items = tmp;
            capacity = newCapacity; 
        }
    public:
        ArrayList(){
            capacity  = 100;
            length = 0;
            items = new Object[capacity];
        }
        ArrayList(const ArrayList<Object> &right)//copy constructer, elimde bir liste var aynısından bir tane daha olusturacagım bu durumda bu func. cagırıcak
        {
            length = 0;
            capacity = max(2,2*right.size()); // right pointer degil nesnenin kendisi oyüden nokta kullandık | eger bos lsite gelirse ilk parametre olan 2 donecek, diger durumlarda normal 2 aktı boyutta liste gelecek
            items = new Object[capacity];
            for(int i = 0; i < right.size();i++) {
                add(right.elementAt(i)); // verdigim indexdteki elemanı döndürüyoru programlama dillerinde adı degisebilir At oalrak da gecebilir
            }
        }
        int size()const{
            return length;
        }
        bool isEmpty()const{
            return length == 0;
        } 
        int indexOf(const Object& item) // elemanı gonderirsin elemanın indexini dondurur 
        {
            for(int index = 0; index<length;index++) {
                if (items[index] == item) return index;
            }//olmayan eleman gonderirlirse isleyisi kesmem lazım
            throw "item not found";
        }
        const Object& elementAt(int index) {
            if(index < 0 || index >= length) throw "index out of range";
            return items[index];
        }
        // ZORLASIYOR DIKKAT!
        void insert(int index, const Object& item){
            if(index < 0 || index > length) throw "index out of range";
            if(length == capacity) reserve(2*capacity); // kapasite doldu yeni kapasite olusturacagım
            //araya eklemek icin once eklencek yeri bosaltamm lazım eleman kaybedemen, onun icinde sondan baslayıp ekleyecegim yere kadar olan tüm elemanları bir saga kaydıracagım ki güvenli sekilde yer acılsın
            for(int i=length-1; i>=index; i--){
                items[i+1] = items[i];
            } // dongu bittikten sonra dogrudan istenen yere elemanı ekleyebilirim
            items[index] = item;
            length++;
        }
        void add(const Object& item){
            insert(length,item); // item'ı en sona ekler :)
        }
        const Object& first(){
            if(isEmpty()) throw "list is empty";
            return items[0];
        }
        const Object& last(){
            if(isEmpty()) throw "list is empty";
            return items[length-1];
        }
        void removeAt(int index)// konum verilir, elemanı sil 
        {// tüm elemanları bir sola kopyalayarak silme islemi
           if(index < 0 || index >= length) throw "index out of range";
            for(int i = index+1;i<length;i++) {
                items[i-1] = items[i];
            }
            length--;
        }
         void remove(const Object& item)// veya elemanı direkt sil
        {
            int index = indexOf(item); //indexi indexof metoduyla bulup devam ediyoruz
            removeAt(index);
        }
        void clear(){
            length = 0; //onemli olan uzunluktur!!!
        }
        bool find(const Object& item) {
            for(int index=0;index<length;index++) {
                if(items[index] == item) return true;
            }
            return false;
        }
        //ekrana yazma oepratorunu yeniden tanımlıyoruz
        friend ostream& operator<<(ostream& screen,ArrayList<Object> &right) {
            screen<<endl;
            for(int index = 0; index < right.length;index++) {
                screen<<right.items[index];
                if(index+1 != right.length){
                    screen<<" || ";
                } 
            }
            return screen;
        }
        ~ArrayList() {
            delete [] items;
        }
};

#endif