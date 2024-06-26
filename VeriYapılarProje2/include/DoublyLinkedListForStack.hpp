/** 
* @file Dosya adı
* @description Programınızın açıklaması ne yaptığına dair.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment Kaçıncı ödev olduğu
* @date Kodu oluşturduğunuz Tarih
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#ifndef DOUBLYLINKEDLISTFORSTACK_HPP
#define DOUBLYLINKEDLISTFORSTACK_HPP
#include "Stack.hpp"
struct NodeListForStack {
    Stack data;
    NodeListForStack* prev;
    NodeListForStack* next;

    NodeListForStack(Stack item) : data(item), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedListForStack {
private:
    NodeListForStack* head;
    NodeListForStack* tail;

public:
    DoublyLinkedListForStack();
    void push_back(Stack item);
    Stack pop_back();
    bool is_empty(void);
    int size();
    Stack getValueOfIndex(int index);
    void clear();
    ~DoublyLinkedListForStack();
};

#endif

