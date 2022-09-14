#include "BST.hpp"


int main(){
    BST<int> *agac = new BST<int>();
    agac->add(45);
    agac->add(2);
    agac->add(18);
    agac->add(9);
    agac->add(50);
    agac->add(40);
    agac->add(23);

    agac->preorder();
    cout<<endl<<endl;
    agac->postorder();
    cout<<endl<<endl;
    cout<<"Yukseklik: "<<agac->Height()<<endl;
    delete agac;
    return 0;
}