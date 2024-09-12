#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>

struct TreeNode {
private:

public:
    TreeNode(int key): key(key) {}
    int key;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    void mirror(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        mirror(root->left);
        mirror(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    void inOrder(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        inOrder(root->left);
        std::cout << root->key << " ";
        inOrder(root->right);

    }
};

#endif // TREENODE_H
