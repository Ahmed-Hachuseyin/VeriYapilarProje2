/**
* @G211210586 - @G211210584
* 1. ogretim B grubu
* Odev 2
* 28.07.2023-09.08.2023
* Ahmed Hachüseyin -> ahmed.hachuseyin@ogr.sakarya.edu.tr
* Kays Alsaran -> ghaith.alsaaran@ogr.sakarya.edu.tr
*/

#include "DoublyLinkedListForIntegral.hpp"
#include <iostream>
using namespace std;

DoublyLinkedListForIntegral::DoublyLinkedListForIntegral()
{
    head = tail = nullptr;
}

void DoublyLinkedListForIntegral::push_back(int item) {
    NodeList* new_node = new NodeList(item);
    if (!head) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

int DoublyLinkedListForIntegral::pop_back() {
    if (!is_empty()) {
        int popped_item = tail->data;
        NodeList* prev_node = tail->prev;
        delete tail;
        tail = prev_node;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        return popped_item;
    }
    else {
       cout<<"Liste bo�. Bo� bir listeden eleman ��karamazs�n�z."<<endl;
    }
}


bool DoublyLinkedListForIntegral::is_empty() {
    return head == nullptr;
}

int DoublyLinkedListForIntegral::size() {
    int count = 0;
    NodeList* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

int DoublyLinkedListForIntegral::getValueOfIndex(int index) {
    if (index >= 0 && index < size()) {
        NodeList* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
    
}

NodeList* DoublyLinkedListForIntegral::getHead() {
    return head;
}

void DoublyLinkedListForIntegral::clear() {
    while (!is_empty()) {
        pop_back();
    }
}

DoublyLinkedListForIntegral::~DoublyLinkedListForIntegral() {
    clear();
}
