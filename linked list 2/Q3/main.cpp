#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(NULL), prev(NULL) {}
};

class DoublyLinkedList {
public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int tamanho() {
        int count = 0;
        Node* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }

    void remover(int position) {
        if (position < 0) {
            return;
        }

        Node* current = head;
        int count = 0;

        while (current != NULL && count != position) {
            current = current->next;
            count++;
        }

        if (current == NULL) {
            return;
        }

        if (current == head) {
            head = current->next;
        } else {
            current->prev->next = current->next;
        }

        if (current == tail) {
            tail = current->prev;
        } else {
            current->next->prev = current->prev;
        }

        delete current;
    }

    int encontrarMaior() {
        if (head == NULL) {
            cerr << "A lista está vazia." << endl;
            return -1;
        }

        int maior = head->data;
        Node* current = head;

        while (current != NULL) {
            if (current->data > maior) {
                maior = current->data;
            }
            current = current->next;
        }

        return maior;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

private:
    Node* head;
    Node* tail;
};

int main() {
    DoublyLinkedList lista;
    lista.append(10);
    lista.append(5);
    lista.append(15);
    lista.append(20);
    lista.append(7);

    cout << "Lista: ";
    lista.display();

    int tamanho = lista.tamanho();
    cout << "Tamanho da lista: " << tamanho << endl;

    int maior = lista.encontrarMaior();
    if (maior != -1) {
        cout << "Maior valor na lista: " << maior << endl;
    }

    lista.remover(2);
    cout << "Lista apos a remocao da posicao 2: ";
    lista.display();

    return 0;
}