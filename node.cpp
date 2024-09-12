#include "node.h"
#include <iostream>
Node* _insert(Node* node, int key) {
    if(node == nullptr) {
        return new Node(key);
    }
    if(node->key == key) {
        return node;
    }
    if(node->key < key) {
        node->right = _insert(node->right, key);
    }else {
        node->left = _insert(node->left, key);
    }

    return node;
}

void _inOrder(Node* node)
{
    if(node != nullptr) {
        _inOrder(node->left);
        std::cout << node->key << " ";
        _inOrder(node->right);
    }
}

bool _search(Node* node, int key)
{
    bool result = false;
    if(node != nullptr) {
        if(node->key == key) {
            return true;
        }
        result = _search(node->left, key);
        if(!result) {
            result = _search(node->right, key);
        }
    }
    return result;
}

void BST::insert(int key)
{
    root = _insert(root, key);
}

bool BST::search(int key)
{
   return _search(root, key);
}

void BST::inOrder()
{
   _inOrder(root);
}
