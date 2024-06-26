/** 
* @file Dosya adı
* @description Programınızın açıklaması ne yaptığına dair.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment Kaçıncı ödev olduğu
* @date Kodu oluşturduğunuz Tarih
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

struct NodeList {
    int data;
    NodeList* prev;
    NodeList* next;

    NodeList(int item) : data(item), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedListForIntegral {
private:
    NodeList* head;
    NodeList* tail;

public:
    DoublyLinkedListForIntegral();
    void push_back(int item);
    int pop_back();
    bool is_empty();
    int size();
    int getValueOfIndex(int index);
    NodeList* getHead(); // Yeni eklenen getHead metodu.
    void clear();
    ~DoublyLinkedListForIntegral();
};


#endif 
