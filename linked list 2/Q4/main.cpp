#include <iostream>
using namespace std;

class No {
public:
    int data;
    No* prev;
    No* next;

    No(int value) : data(value), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
private:
    No* head;
    No* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void Inserir(int data) {
        No* new_No = new No(data);
        if (!head) {
            head = new_No;
            tail = new_No;
        } else {
            tail->next = new_No;
            new_No->prev = tail;
            tail = new_No;
        }
    }

    int tamanho() {
        int count = 0;
        No* NoAtual = head;
        while (NoAtual) {
            count++;
            NoAtual = NoAtual->next;
        }
        return count;
    }

    void removerNaPosicao(int position) {
        if (position < 0) return;
        if (position == 0) {
            if (head) {
                No* temp = head;
                head = head->next;
                if (head)
                    head->prev = NULL;
                delete temp;
            }
        } else {
            No* NoAtual = head;
            int count = 0;
            while (NoAtual && count < position) {
                NoAtual = NoAtual->next;
                count++;
            }
            if (NoAtual) {
                No* prevNo = NoAtual->prev;
                No* nextNo = NoAtual->next;
                if (prevNo)
                    prevNo->next = nextNo;
                if (nextNo)
                    nextNo->prev = prevNo;
                delete NoAtual;
            }
        }
    }

    No* merge(No* left, No* right) {
        No* result = NULL;
        if (!left)
            return right;
        if (!right)
            return left;
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
            if (result->next)
                result->next->prev = result;
        } else {
            result = right;
            result->next = merge(left, right->next);
            if (result->next)
                result->next->prev = result;
        }
        return result;
    }
    No* acharMeio(No* head) {
        if (!head)
            return head;

        No* slow = head;
        No* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    No* mergeSort(No* head) {
        if (!head || !head->next)
            return head;

        No* middle = acharMeio(head);
        No* nextToMiddle = middle->next;
        middle->next = NULL;

        No* left = mergeSort(head);
        No* right = mergeSort(nextToMiddle);

        return merge(left, right);
    }


    void sort() {
        head = mergeSort(head);
        if (head) {
            No* NoAtual = head;
            while (NoAtual->next) {
                NoAtual = NoAtual->next;
            }
            tail = NoAtual;
        } else {
            tail = NULL;
        }
    }


    void MostrarLista() {
        No* NoAtual = head;
        while (NoAtual) {
            cout << NoAtual->data << " -> ";
            NoAtual = NoAtual->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.Inserir(5);
    dll.Inserir(2);
    dll.Inserir(9);
    dll.Inserir(3);
    dll.Inserir(6);

    cout << "Lista original:" << endl;
    dll.MostrarLista();

    dll.sort();

    cout << "Lista ordenada:" << endl;
    dll.MostrarLista();

    cout << "Tamanho da lista: " << dll.tamanho() << endl;

    int remover = 2;
    dll.removerNaPosicao(remover);
    cout << "Lista apos remover o elemento na posicao " << remover << ":" << endl;
    dll.MostrarLista();

    return 0;
}
