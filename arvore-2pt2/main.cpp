#include <iostream>
#include <stack>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};


void pares(Node* node) {
    if (node != nullptr) {
        pares(node->left);
        if (node->value % 2 == 0) {
            std::cout << node->value << " ";
        }
        pares(node->right);
    }
}

void impares(Node* node) {
    if (node != nullptr) {
        impares(node->left);
        if (node->value % 2 != 0) {
            std::cout << node->value << " ";
        }
        impares(node->right);
    }
}


int contador(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + contador(node->left) + contador(node->right);
}


int somatorios(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->value + somatorios(node->left) + somatorios(node->right);
}


double media(Node* node) {
    int count = contador(node);
    if (count == 0) {
        return 0;
    }
    return static_cast<double>(somatorios(node)) / count;
}


void preordem(Node* root) {
    std::stack<Node*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        Node* node = nodeStack.top();
        nodeStack.pop();

        if (node != nullptr) {
            std::cout << node->value << " ";
            nodeStack.push(node->right);
            nodeStack.push(node->left);
        }
    }
}


void emordem(Node* root) {
    std::stack<Node*> nodeStack;
    Node* current = root;

    while (current != nullptr || !nodeStack.empty()) {
        while (current != nullptr) {
            nodeStack.push(current);
            current = current->left;
        }

        current = nodeStack.top();
        nodeStack.pop();

        std::cout << current->value << " ";

        current = current->right;
    }
}


void posordem(Node* root) {
    std::stack<Node*> stack1;
    std::stack<Node*> stack2;
    stack1.push(root);

    while (!stack1.empty()) {
        Node* node = stack1.top();
        stack1.pop();

        if (node != nullptr) {
            stack2.push(node);
            stack1.push(node->left);
            stack1.push(node->right);
        }
    }

    while (!stack2.empty()) {
        Node* node = stack2.top();
        stack2.pop();
        std::cout << node->value << " ";
    }
}

int main() {
    // Criar a árvore
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    std::cout << "Elementos pares: ";
    pares(root);
    std::cout << std::endl;

    std::cout << "Elementos impares: ";
    impares(root);
    std::cout << std::endl;

    std::cout << "Numero de nos: " << contador(root) << std::endl;
    std::cout << "Soma dos valores dos nos: " << somatorios(root) << std::endl;
    std::cout << "Media dos valores dos nos: " << media(root) << std::endl;

    std::cout << "Pre-ordem: ";
    preordem(root);
    std::cout << std::endl;

    std::cout << "Em ordem: ";
    emordem(root);
    std::cout << std::endl;

    std::cout << "Pos-ordem: ";
    posordem(root);
    std::cout << std::endl;

    // Liberar a memória
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
