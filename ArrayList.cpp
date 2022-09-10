//listenin dizi üzreinde gerceklesitirmi,arkaplanda dizi bulıunmaktadır,methodlar ile islem yapılır
//dizinin avantajı olan anlık erisimden faydalanabiliri, dez avantaj dizi boyutu sınırlı doldugu zaman yeni dizi olusturup elemnalar kopyalanır

#include "ArrayList.hpp"

int main() {
    ArrayList<int> *numbers = new ArrayList<int>();
    numbers->add(100);
    numbers->add(200);
    numbers->add(300);
    numbers->insert(1,500);
    cout<<*numbers<<endl;
    numbers->remove(200);
    numbers->removeAt(0);
    cout<<*numbers<<endl;
    delete numbers;
    return 0;
}