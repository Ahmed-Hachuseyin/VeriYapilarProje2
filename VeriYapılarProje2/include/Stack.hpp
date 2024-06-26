/** 
* @file Dosya adı
* @description Programınızın açıklaması ne yaptığına dair.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment Kaçıncı ödev olduğu
* @date Kodu oluşturduğunuz Tarih
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#ifndef STACK_HPP
#define STACK_HPP


class NodeStack {
public:
    int data;
    NodeStack* next;
};

class Stack {
private:
    NodeStack* top;

public:

    Stack();
    void push(int value);
    void pop();
    int Top();
    bool empty();

};


#endif 
