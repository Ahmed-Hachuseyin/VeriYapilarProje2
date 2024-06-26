
/** 
* @file Dosya adı
* @description Programınızın açıklaması ne yaptığına dair.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment Kaçıncı ödev olduğu
* @date Kodu oluşturduğunuz Tarih
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#ifndef BINAERYTREE_HPP
#define BINAERYTREE_HPP
#include "DoublyLinkedListForIntegral.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    void insertNode(Node* currentNode, Node* newNode);
    int calculateHeight(Node* node);
    int calculateSum(Node* node);
    void postorderTraversal(Node* node, DoublyLinkedListForIntegral& dllist); 

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int data);
    int maxHeight() {
        return calculateHeight(root);
    }

    int sumOfValues() {
        return calculateSum(root);
    }

    DoublyLinkedListForIntegral postorderTraversal();
};

#endif
