#ifndef NODE_H
#define NODE_H

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int item): key(item) {
        left = nullptr;
        right = nullptr;
    }

};

class BST
{
private:
    Node* root;
public:

    void insert(int key);
    bool search(int key);
    bool remove(int value);
    void inOrder();
};




#endif // NODE_H
