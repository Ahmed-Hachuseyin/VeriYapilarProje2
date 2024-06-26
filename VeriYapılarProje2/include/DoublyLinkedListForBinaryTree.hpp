/** 
* @file Dosya adı
* @description Programınızın açıklaması ne yaptığına dair.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment Kaçıncı ödev olduğu
* @date Kodu oluşturduğunuz Tarih
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#pragma once
#include "BinaryTree.hpp"
#ifndef DOUBLYLINKEDLISTFORBINARYTREE_HPP
#define DOUBLYLINKEDLISTFORBINARYTREE_HPP

struct NodeListForBinaryTree {
    BinaryTree data;
    NodeListForBinaryTree* prev;
    NodeListForBinaryTree* next;

    NodeListForBinaryTree(BinaryTree item) : data(item), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedListBinaryTree {
private:
    NodeListForBinaryTree* head;
    NodeListForBinaryTree* tail;

public:
    DoublyLinkedListBinaryTree();
    void push_back(BinaryTree item);
    BinaryTree pop_back();
    bool is_empty();
    int size();
    BinaryTree getValueOfIndex(int index);
    NodeListForBinaryTree* getHead(); 
    void clear();
    ~DoublyLinkedListBinaryTree();
};

#endif 

