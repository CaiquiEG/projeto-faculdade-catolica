#include <iostream>


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};


void destroyTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }


    destroyTree(root->left);
    destroyTree(root->right);

    // Em seguida, destrua o nó atual
    delete root;
}


void printTree(TreeNode* root) {
    if (root != nullptr) {
        printTree(root->left);
        std::cout << root->data << " ";
        printTree(root->right);
    }
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);


    std::cout << "arvore em ordem: ";
    printTree(root);
    std::cout << std::endl;


    destroyTree(root);

    return 0;
}