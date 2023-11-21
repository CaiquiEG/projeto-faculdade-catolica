#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Implementação básica de uma fila
class MyQueue {
private:
    struct QueueNode {
        Node* data;
        QueueNode* next;
        QueueNode(Node* node) : data(node), next(nullptr) {}
    };

    QueueNode* front;
    QueueNode* rear;

public:
    MyQueue() : front(nullptr), rear(nullptr) {}

    void push(Node* node) {
        QueueNode* newNode = new QueueNode(node);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    Node* pop() {
        if (front == nullptr) {
            return nullptr;
        }
        QueueNode* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        Node* data = temp->data;
        delete temp;
        return data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

// Função para verificar se a árvore é uma árvore binária completa
bool isCompleteBinaryTree(Node* root) {
    if (!root)
        return true;

    MyQueue queue;
    queue.push(root);

    while (!queue.isEmpty()) {
        Node* current = queue.pop();

        if (current == nullptr) {
            while (!queue.isEmpty()) {
                Node* temp = queue.pop();
                if (temp != nullptr)
                    return false;
            }
            break;
        }

        queue.push(current->left);
        queue.push(current->right);
    }

    return true;
}

int main() {
    // Exemplo de uso
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    std::cout << "Complete Binary Tree: " << isCompleteBinaryTree(root) << std::endl;

    // Libere a memória da árvore (não é tratado completamente aqui por brevidade)
    return 0;
}
