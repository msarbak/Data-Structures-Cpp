#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <cmath>
using namespace std;

template <typename Object>
class Node{
    Object data;
    Node<Object> *left;
    Node<Object> *right;
    int height;

    Node(const Object& vr, Node<Object> *sl=NULL, Node<Object> *sg = NULL) { //sol ve sag cocukalr girilmezse null oalrk atanıyor
        data = vr;
        left = sl;
        right = sg;
        height = 0;
    }
};

template <typename Object>
class AVL{ 
    private:
        Node<Object> *root;
        Node<Object> *SearchAndAdd(Node<Object> *subNode,const Object& item){
            if(subNode == NULL) subNode = new Node<Object>(item);
            else if(item <= subNode->data) {
                subNode->left = SearchAndAdd(subNode->left, item);
                
                if(Height(subNode->left) == Height(subNode->right) + 2){
                    if(item < subNode->left->data){ //duz cizgi oldu  tek cevrim yapıalcak
                        subNode = SwapWithLeftChild(subNode);
                    }else{
                        subNode->left = SwapWithrightChild(subNode->left);
                        subNode = SwapWithLeftChild();
                    }
                }
            }
            else(item > subNode->data) {
                subNode->right = SearchAndAdd(subNode->right, item);
                
                if(Height(subNode->right) == Height(subNode->left) + 2){
                    if(item > subNode->right->data){ //duz cizgi oldu  tek cevrim yapıalcak
                        subNode = SwapWithrightChild(subNode);
                    }else{
                        subNode->right = SwapWithLeftChild(subNode->right);
                        subNode = SwapWithrightChild();
                    }
                }
            }
            hsubNode->height = Height(subNode);
            return subNode;
        }
        Node<Object> *SwapWithLeftChild(Node<Object> *subNode){
            
        }
        Node<Object> *SwapWithrightChild(Node<Object> *subNode){
            
        }
        bool DeleteNode(Node<Object> *&subNode){//silme kodu aslında yok sadece cop olusmaması ıcın burada
            Node<Object> *delNode = subNode;
            
            if(subNode->right == NULL) subNode = subNode->left;
            else{
                delNode = subNode->left;
                Node<Object> *parentNode = subNode;
                while(delNode->right != NULL){
                    parentNode = delNode;
                    delNode = delNode->right;
                }
                subNode->data = delNode->data;
                if(parentNode->right = delNode->left);
            }
            delete delNode;
            return true;
        }
        void inorder(Node<Object> *subNode) {
            if(subNode != NULL) {
                inorder(subNode->left);
                cout<<subNode->data<<" ";
                inorder(subNode->right);
            }
        }
        void preorder(Node<Object> *subNode) {
            if(subNode != NULL) {
                cout<<subNode->data<<" ";
                preorder(subNode->left);
                preorder(subNode->right);
            }
        }
        void postorder(Node<Object> *subNode) {
            if(subNode != NULL) {
                postorder(subNode->left);
                postorder(subNode->right);
                cout<<subNode->data<<" ";
            }
        }
        int Height(Node<Object> *subNode) {
            if(subNode == NULL) return -1;
            return 1 + max(Height(subNode->left),Height(subNode->right));
        }
        void PrintLevel(Node<Obejct> *subNode,int level) {
            if(subNode == NULL) return;
            if(level == 0) cout<<subNode->data<<" ";
            else{
                PrintLevel(subNode->left,level - 1);
                PrintLevel(subNode->right,level - 1);
            }
        }
        bool Search(Node<Object> *subNode, const Object item) {
            if(subNode == NULL) return false;
            if(subNode->data == NULL) return true;
            if(item < subNode->data ) return Search(subNode->left,item);
            else return Search(subNode->right,item);
        }
    public:
        AVL(){
            root = NULL;
        }
        bool isEmpty()const{
            return root == NULL;
        }
        void Add(const Object& item){
            root = SearchAndAdd(root,item) //kokten basla parametreyi ekle
        }
        void inorder(){
            inorder(root);
        }
        void preorder(){
            preorder(root);
        }
        void postorder(){
            postorder(root);
        }
        void levelorder(){
            int h = Height();
            for (int level = 0; level <= h; level++){
                PrintLevel(root,level);
            }
        }
        int Height() {
            return Height(root);
        }
        bool Search(const Object& item) {
            return Search(root,item);
        }
        void Clear(){
            while(!isEmpty()) DeleteNode(root);
        }
        ~AVL(){
            Clear();
        }
};
#endif