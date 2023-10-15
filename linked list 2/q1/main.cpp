#include <iostream>

using namespace std;
class No {
public:
    int data;
    No* next;

    No(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
private:
    No* head;

public:
    LinkedList() {
        head = NULL;
    }

    void inserir(int data) {
        No* new_No = new No(data);
        if (head == NULL) {
            head = new_No;
        } else {
            No* Noatual = head;
            while (Noatual->next != NULL) {
                Noatual = Noatual->next;
            }
            Noatual->next = new_No;
        }
    }

    int tamanho() {
        int count = 0;
        No* Noatual = head;
        while (Noatual != NULL) {
            count++;
            Noatual = Noatual->next;
        }
        return count;
    }

    int acharmeio() {
        No* slow = head;
        No* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == NULL || fast->next == NULL) {
                break;
            }
        }
        return slow->data;
    }


    void removernaposicao(int position) {
        if (position < 0 || position >= tamanho()) {
            return;
        }
        if (position == 0) {
            No* temp = head;
            head = head->next;
            delete temp;
        } else {
            No* Noatual = head;
            for (int i = 0; i < position - 1; i++) {
                Noatual = Noatual->next;
            }
            No* temp = Noatual->next;
            Noatual->next = temp->next;
            delete temp;
        }
    }


    void monstarLista() {
        No* Noatual = head;
        while (Noatual != NULL) {
            cout << Noatual->data << " -> ";
            Noatual = Noatual->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList linkedList;
    for (int i = 1; i <= 6; i++) {
        linkedList.inserir(i);
    }

    linkedList.monstarLista();  

   cout << "Tamanho da lista: " << linkedList.tamanho() << endl;  

    int meio = linkedList.acharmeio();
    cout << "Valor do meio: " << meio << endl;  



    linkedList.removernaposicao(2);
    cout << "Lista apos remover o valor na posicao 2: " << endl;
    linkedList.monstarLista();  

    return 0;
}
