/**
* @G211210586 - @G211210584
* 1. ogretim B grubu
* Odev 2
* 28.07.2023-09.08.2023
* Ahmed Hachüseyin -> ahmed.hachuseyin@ogr.sakarya.edu.tr
* Kays Alsaran -> ghaith.alsaaran@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "DoublyLinkedListForBinaryTree.hpp"

DoublyLinkedListBinaryTree::DoublyLinkedListBinaryTree() 
{
    head = tail = nullptr;
}

void DoublyLinkedListBinaryTree::push_back(BinaryTree item) {
    NodeListForBinaryTree* new_node = new NodeListForBinaryTree(item);
    if (!head) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

BinaryTree DoublyLinkedListBinaryTree::pop_back() {
    if (!is_empty()) {
        BinaryTree popped_item = tail->data;
        NodeListForBinaryTree* prev_node = tail->prev;
        delete tail;
        tail = prev_node;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        return popped_item;
    }
    else {
        cout << "Liste bo�. Bo� bir listeden eleman ��karamazs�n�z." << endl;
    }
}


bool DoublyLinkedListBinaryTree::is_empty() {
    return head == nullptr;
}

int DoublyLinkedListBinaryTree::size() {
    int count = 0;
    NodeListForBinaryTree* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

BinaryTree DoublyLinkedListBinaryTree::getValueOfIndex(int index) {
    if (index >= 0 && index < size()) {
        NodeListForBinaryTree* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

}

NodeListForBinaryTree* DoublyLinkedListBinaryTree::getHead() {
    return head;
}

void DoublyLinkedListBinaryTree::clear() {
    while (!is_empty()) {
        pop_back();
    }
}

DoublyLinkedListBinaryTree::~DoublyLinkedListBinaryTree() {
    clear();
}
