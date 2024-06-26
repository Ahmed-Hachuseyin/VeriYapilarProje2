/**
* @G211210586 - @G211210584
* 1. ogretim B grubu
* Odev 2
* 28.07.2023-09.08.2023
* Ahmed Hachüseyin -> ahmed.hachuseyin@ogr.sakarya.edu.tr
* Kays Alsaran -> ghaith.alsaaran@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "DoublyLinkedListForStack.hpp"

DoublyLinkedListForStack::DoublyLinkedListForStack()
{
    head = tail = nullptr;
}

void DoublyLinkedListForStack::push_back(Stack item) {
    NodeListForStack* new_node = new NodeListForStack(item);
    if (!head) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

Stack DoublyLinkedListForStack::pop_back() {
    if (!is_empty()) {
        Stack popped_item = tail->data;
        NodeListForStack* prev_node = tail->prev;
        delete tail;
        tail = prev_node;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        return popped_item;
    }
    else {
        std::cout << "Liste bo�. Bo� bir listeden eleman ��karamazs�n�z." << std::endl;
    }
}
                                                                                            



bool DoublyLinkedListForStack::is_empty(void) {
    return head == nullptr;
}

int DoublyLinkedListForStack::size() {
    int count = 0;
    NodeListForStack* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

Stack DoublyLinkedListForStack::getValueOfIndex(int index) {
    if (index >= 0 && index < size()) {
        NodeListForStack* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

}



void DoublyLinkedListForStack::clear() {
    while (!is_empty()) {
        pop_back();
    }
}

DoublyLinkedListForStack::~DoublyLinkedListForStack() {
    clear();
}
