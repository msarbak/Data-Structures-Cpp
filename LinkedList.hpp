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
        }
};

#endif