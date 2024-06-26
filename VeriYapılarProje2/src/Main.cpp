/**
* @G211210586 - @G211210584
* 1. ogretim B grubu
* Odev 2
* 28.07.2023-09.08.2023
* Ahmed Hachüseyin -> ahmed.hachuseyin@ogr.sakarya.edu.tr
* Kays Alsaran -> ghaith.alsaaran@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include "Stack.hpp"
#include "BinaryTree.hpp"
#include "DoublyLinkedListForStack.hpp"
#include "DoublyLinkedListForBinaryTree.hpp"
#include "DoublyLinkedListForIntegral.hpp"

using namespace std;

DoublyLinkedListForStack processLine(string line);
BinaryTree createBinaryTree(Stack stack);
BinaryTree findMaxHeightTree(DoublyLinkedListBinaryTree& trees);

int main() {
    string filePath = "Sayiler.txt";

    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "Dosya bulunamadi!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        DoublyLinkedListBinaryTree binaryTrees;
        DoublyLinkedListForStack stacks = processLine(line);

        for (int i = 0; i < stacks.size(); i++) {
            binaryTrees.push_back(createBinaryTree(stacks.getValueOfIndex(i)));
        }

        BinaryTree maxTree = findMaxHeightTree(binaryTrees);

        DoublyLinkedListForIntegral asciiValues = maxTree.postorderTraversal();

        NodeList* current = asciiValues.getHead();
        while (current) {
            cout << (char)current->data << " ";
            current = current->next; // Sonraki d���me ge�iyoruz
        }

        cout << endl;
    }

    return 0;
}

DoublyLinkedListForStack processLine(string line) {
    Stack _stack;
    DoublyLinkedListForStack _stacks;

    int pos = 0;
    while ((pos = line.find(' ')) != string::npos) {
        string num = line.substr(0, pos);
        line.erase(0, pos + 1);

        int number = stoi(num);

        if (!_stack.empty() && number >= _stack.Top() && number % 2 == 0) {
            _stacks.push_back(_stack);
            _stack = Stack();
        }

        _stack.push(number);
    }

    if (!_stack.empty()) {
        _stacks.push_back(_stack);
    }

    return _stacks;
}

BinaryTree createBinaryTree(Stack stack) {
    BinaryTree binaryTree;

    while (!stack.empty()) {
        int data = stack.Top();
        stack.pop();
        binaryTree.insert(data);
    }

    return binaryTree;
}

BinaryTree findMaxHeightTree(DoublyLinkedListBinaryTree& trees) {
    BinaryTree maxTree = trees.getHead()->data;

    NodeListForBinaryTree* current = trees.getHead()->next;
    while (current) {
        if (current->data.maxHeight() > maxTree.maxHeight()) {
            maxTree = current->data;
        }
        current = current->next;
    }

    return maxTree;
}
