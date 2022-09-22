#ifndef HUFFMANN_HPP
#define HUFFMANN_HPP

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

#endif