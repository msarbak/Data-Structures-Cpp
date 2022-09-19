#include "AVL.hpp"

int main(){
    AVL<int> *avl = new AVL<int>();
    avl->Add(1);
    avl->Add(2);
    avl->Add(3);
    avl->Add(4);
    avl->Add(5);
    avl->Add(6);
    avl->Add(7);
    avl->Add(8);
    avl->Add(9);
    avl->Add(10);
    avl->postorder();
    cout<<endl<<"Height: "<<avl->Height()<<endl;
    if(avl->Search(95)) {
        cout<<"Item found!"<<endl;
    } else{
        cout<<"Not Found!"<<endl;
    }
    avl->preorder();
    delete avl;
    return 0;
}