#include "Queue.hpp"
#include <cmath>
//radix sort gercek hayat problemi
// bu algorima icin 10 adet kuyruk gerekli ve dizide tutulurlar

int basamakSayisi(int sayi) {
    sayi = abs(sayi); // herturlu sayiyi positive ceviriyorum, negatif olursa algoritmayı bozuyor
    int basamak = 0;
    while(sayi > 0) {
        basamak++;
        sayi /= 10;
    }
    return basamak;
}

int enYuksekBasamakSayisi(int *items, int length) {
    int max = 0;
    for (int i = 0; i < length; i++){
        if(basamakSayisi(items[i] > max)) {
            max = basamakSayisi(items[i]); // max dan daha buyugunu buldugumda bu sayısı max olarak belirliyorum
        }   
    }
    return max;
    
}

int* radixSort(int* items, int length) {
    Queue<int> **queues = new Queue<int>*[10]; //icinde adres , dizinin kendide adres: çift ** .   kuyruk kdizinin hücresinde deil adresidne olacak
    // 10 tane kuyrugu burada olusturduk
    //suan icerde anlamsız adresler var , bizim bos kuyrukları olusturmamız lazım
    for (int i = 0; i < 10; i++) queues[i] = new Queue<int>(); // 10 kuyruk olusuyor
        int maxBasamak = enYuksekBasamakSayisi(items,length);
        int sayiIndex = 0;
        for (int i = 0; i < maxBasamak; i++){ // algoritma icin ana dongumuz, kuyruklara yerlestirme islemi en yüksek basamaga sahip sayının basamak adedince oalcaktır 
            for (int index = 0; index < 10; index++){
                if(sayiIndex < length) { //bu da kuyrukların icinde dolasacak 
                    // kuyruklara ilk ekleme kısmı, ilk ekelem ediziden kuyruklara dogru olur, sonra kuyrukalrın kendi icerisinde basamaklara gore yerlesir
                    int basamakDegeri = items[sayiIndex] % 10; // sayıyı ona boldum birler basamagını elde ettim
                    queues[basamakDegeri] -> enqueue(items[sayiIndex++]); //kuyruklar dizisi
                    //birler absamagındaki deger o degerdeki kuyruga gidiyor, bu sayıyı oraya ekledikten sonrasayıindex 1 artıyor
                } else{ //birler basmagının degerlendirmesi tamamlanmıs onlar yuzler vs.. burada
                    for (int len = queues[index]->count(); len > 0; len--){
                        int sayi = queues[index]->peek(); // sırdaki çıkmak üzere olan sayıyıı alıyoruz
                        queues[index]->dequeue(); // artık veriyi silebiliriz kaybolmasın diye peek ile almıstık
                        int basamakDegeri = (sayi/(int)pow(10,i)) % 10; // 10 un üzeri seklinde
                        queues[basamakDegeri]->enqueue(sayi); // sildigimiz degeri oradaki kuyruga ekleyecegiz
                    }
                    
                }
            }
            
        }
        
    
    int* sirali = new int [length]; // for dongıuleri bittikten sonra sıralı hale gelmeis oalcak, yeni dizitanımlayıp kullanalım
    sayiIndex = 0;
    for (int index = 0; index < 10; index++){ //kuyruklar dizisndeki her sayıyı dolasıcaz ve bu diziye yerlesicez
        while(!queues[index]->isEmpty()){ //kuyurk bos olmadıgı surece
            int sayi =  queues[index]->peek(); //cıkartmadan sayiyi elde ediyoruz 
            sirali[sayiIndex++] = sayi; // bu sayıyı sıralı dizinin icine kopaylıoruz, kopyaladıktan sorna indexi 1 artıyıoruz
            queues[index]->dequeue(); // kopayladıktan sonra kuyruktan sayısyı silebiliriz
        }
    }//cop olamamsı adına new le olusan her kuyrugu simdi silmemeiz lazım
    for (int i = 0; i < 10; i++){ 
        delete queues[i]; 
    }
    delete [] queues; //kuyrukalr dizisini de siliyoruz
    return sirali;
}

int main() {
    int sayilar[] = {167,32,19,356,478,951,5,98,301,7,};
    int *sirali = radixSort(sayilar,10);
    cout<<"Siralamanmadan onceki hali: "<<endl;
    for (int i = 0; i < 10; i++){
        cout<<sayilar[i]<<" ";
    }
    cout<<endl<<endl<<"Siralandiktan sonraki hali: "<<endl;
    for (int i = 0; i < 10; i++){
        cout<<sirali[i]<<" ";
    }
    delete [] sirali;
    cout<<endl<<endl<<"---------------"<<endl<<endl;
    
    Queue<int> *kuyruk = new  Queue<int>();
    kuyruk->enqueue(10);
    kuyruk->enqueue(4);
    kuyruk->enqueue(76);
    kuyruk->enqueue(24);
    kuyruk->enqueue(35);
    cout<<kuyruk->peek(); //10 ilk buldugunu cıkardı onceliksiz
    cout<<kuyruk->peekMax(); //76 oncelikli olarak en buyugu cıkardı
    delete kuyruk;

    return 0;
}