/**
* @G211210586 - @G211210584
* 1. ogretim B grubu
* Odev 2
* 28.07.2023-09.08.2023
* Ahmed Hachüseyin -> ahmed.hachuseyin@ogr.sakarya.edu.tr
* Kays Alsaran -> ghaith.alsaaran@ogr.sakarya.edu.tr
*/

#include "BinaryTree.hpp"
#include "DoublyLinkedListForIntegral.hpp"

void BinaryTree::insertNode(Node* currentNode, Node* newNode) {
    if (newNode->data < currentNode->data) {
        if (currentNode->left == nullptr) {
            currentNode->left = newNode;
        }
        else {
            insertNode(currentNode->left, newNode);
        }
    }
    else {
        if (currentNode->right == nullptr) {
            currentNode->right = newNode;
        }
        else {
            insertNode(currentNode->right, newNode);
        }
    }
}

int BinaryTree::calculateHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);

    return 1 + max(leftHeight, rightHeight);
}

int BinaryTree::calculateSum(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    return node->data + calculateSum(node->left) + calculateSum(node->right);
}

void BinaryTree::postorderTraversal(Node* node, DoublyLinkedListForIntegral& dllist) {
    if (node != nullptr) {
        postorderTraversal(node->left, dllist);
        postorderTraversal(node->right, dllist);
        dllist.push_back(node->data);
    }
}

DoublyLinkedListForIntegral BinaryTree::postorderTraversal() {
    DoublyLinkedListForIntegral dllist;
    postorderTraversal(root, dllist);
    return dllist;
}

void BinaryTree::insert(int data) {
    Node* newNode = new Node(data);

    if (root == nullptr) {
        root = newNode;
    }
    else {
        insertNode(root, newNode);
    }
}
