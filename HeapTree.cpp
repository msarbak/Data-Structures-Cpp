#include "HeapTree.hpp"
#include <cstdlib>

int HeapTree::LeftChildIndex(int index){
    return 2 * index + 1;
}
int HeapTree::RightChildIndex(int index){
    return 2 * index + 2;
}
int HeapTree::ParentIndex(int index){
    return (index - 1) / 2; // asagı indikce 2 ye carpıyoruz yukarı cıkarken 2 ye böl
}
void HeapTree::HeapfyUp(int index){
    int parentIndex;
    if(index != 0){ //0 da kok var
        parentIndex = ParentIndex(index);
        if(items[parentIndex] > items[index]) {//degis tokus durumu
            Swap(items[parentIndex], items[index]);

            HeapfyUp(parentIndex); // yerdegistirme oldukca cagiricam (ozyineleme)  koke dogru gidewcektir, aynı zamanda da durma noktasıdır
        }
    }
}
void HeapTree::HeapfyDown(int index){
    int leftIndex, rightIndex, minIndex;
    leftIndex = LeftChildIndex(index);
    rightIndex = RightChildIndex(index);
    
    if(rightIndex >= length) {
        if(leftIndex >= length) return; //durma noktası, yaprak dugum
        else minIndex = leftIndex;
    }
    else{
        if(items[leftIndex] <= items[rightIndex]) {
            minIndex = leftIndex;
        } else{
            minIndex = rightIndex;
        }
    }
    if(items[index] > items[minIndex]) {
        Swap(items[index], items[minIndex]);

        HeapfyDown(minIndex); //son noktası yapraga indigi durumdur, asagi dogru gidiyoruz
    }
}
void HeapTree::Swap(int& val1, int& val2){
    int tmp = val1;
    val1 = val2;
    val2 = tmp;
}
HeapTree::HeapTree(int size){
    items = new int[size];
    capacity = size;
    length = 0;
}
bool HeapTree::isEmpty(){
    return length == 0;
}
void HeapTree::add(int item){
    if(length == capacity) throw"Tree is full!";
    items[length] = item;
    length++;
    HeapfyUp(length - 1); //agacın dengesi bozulmjus olabilir, 0dan basladıgı icim -1
}
int HeapTree::getMinValue(){
    if(isEmpty()) throw "Tree is empty!";
    int minValue = items[0];
    items[0] = items[length - 1]; // en asagi sagdakini koke tasidik
    length--;
    if(length > 0) HeapfyDown(0); //kokten baslayacak
    return minValue;
}
HeapTree::~HeapTree(){
    delete [] items;
}

int main(){ 
    cout<<endl<<endl;
    HeapTree *agac = new HeapTree(50);
    int *sayilar = new int[50];

    cout<<"Dizinin ilk hali: "<<endl;
    for(int i = 0; i < 50; i++){
        sayilar[i] = rand()%100+1; //1 ile 100 arasında rastgele sayilar olusturacak
        agac->add(sayilar[i]);
        cout<<sayilar[i]<<" ";
    }
    
    cout<<endl<<endl;
    int index;
    while(!agac->isEmpty()) { //bos olamdıgı surece surekli veriyi silecek
        sayilar[index++] = agac->getMinValue();
    }

    cout<<"Dizinin sirali hali: "<<endl;
    for (int i = 0; i < 50; i++){
        cout<<sayilar[i]<<" ";
    }
    cout<<endl<<endl;

    delete [] sayilar;
    delete agac;
    return 0;
}
