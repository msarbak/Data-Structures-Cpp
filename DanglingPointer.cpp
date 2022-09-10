#include <iostream>
using namespace std;

class Kisi{
    private:
        string isim;
    public:
        Kisi(string isim){
            this->isim = isim;
        }
        Kisi(){
            this->isim = "";
        }
        friend ostream& operator<<(ostream& ekran, Kisi &sag){
            ekran<<sag.isim<<endl;
            return ekran;
        }
};

int main() {
    Kisi *kisi1 = new Kisi("Mehmet");
    Kisi *kisi2 = kisi1;
    cout<<*kisi1<<endl;
    delete kisi2; // hem kisi 1 i hemde 2 yi iadae eder
    Kisi *kisi3 = new Kisi("Erkan");

    //kisi 1 i iade edilmemis gibi kullanmaya calsıırsam ki iade edildi o
    cout<<*kisi1<<endl;
    // sildikten sonra aynı bolgeye yerlestirdigi icin kisi 1 degil kisi  3 yazdırılacak dikkatli kullanılmalı
    delete kisi3;
    return 0;
}