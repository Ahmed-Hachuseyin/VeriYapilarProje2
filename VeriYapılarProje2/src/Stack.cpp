/**
* @G211210586 - @G211210584
* 1. ogretim B grubu
* Odev 2
* 28.07.2023-09.08.2023
* Ahmed Hachüseyin -> ahmed.hachuseyin@ogr.sakarya.edu.tr
* Kays Alsaran -> ghaith.alsaaran@ogr.sakarya.edu.tr
*/

#include "Stack.hpp"



void Stack::push(int value) {
    NodeStack* node = new NodeStack;
    node->data = value;
    node->next = top;
    top = node;
}
void Stack::pop() {
    NodeStack* temp = top;
    top = top->next;
    delete temp;
}
int Stack::Top()
{
    return top->data;


}
bool Stack::empty() {
    return top == nullptr;
}
Stack::Stack() {
    top = nullptr;
}