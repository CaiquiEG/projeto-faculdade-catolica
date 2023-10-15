#include <iostream>
using namespace std;


class No {
public:
    int dado;
    No* proximo;

    No(int valor) : dado(valor), proximo(NULL) {}
};

class ListaCircular {
private:
    No* head;

public:
    ListaCircular() : head(NULL) {}

    void inserir(int valor) {
        No* novoNo = new No(valor);
        if (head == NULL) {
            head = novoNo;
            head->proximo = head;
        } else {
            No* atual = head;
            while (atual->proximo != head) {
                atual = atual->proximo;
            }
            atual->proximo = novoNo;
            novoNo->proximo = head;
        }
    }

    int tamanho() {
        if (head == NULL) {
            return 0;
        }
        No* atual = head;
        int contador = 1;
        while (atual->proximo != head) {
            atual = atual->proximo;
            contador++;
        }
        return contador;
    }

    void remover(int posicao) {
        if (head == NULL) {
            return;
        }

        if (posicao == 0) {
            No* atual = head;
            while (atual->proximo != head) {
                atual = atual->proximo;
            }
            if (atual == head) {
                delete head;
                head = NULL;
            } else {
                atual->proximo = head->proximo;
                No* temp = head;
                head = head->proximo;
                delete temp;
            }
            return;
        }

        No* anterior = NULL;
        No* atual = head;
        int contador = 0;
        while (contador < posicao) {
            anterior = atual;
            atual = atual->proximo;
            contador++;
        }

        if (atual == head) {
            return;
        }

        anterior->proximo = atual->proximo;
        delete atual;
    }

    void imprimir() {
        if (head == NULL) {
            return;
        }

        No* atual = head;
        do {
            cout << atual->dado << " -> ";
            atual = atual->proximo;
        } while (atual != head);
        cout << endl;
    }
};

int main() {
    ListaCircular listaCircular;
    listaCircular.inserir(1);
    listaCircular.inserir(2);
    listaCircular.inserir(3);
    listaCircular.inserir(4);
    listaCircular.inserir(5);

    cout << "Lista Circular:" << endl;
    listaCircular.imprimir();

    cout << "Tamanho da lista: " << listaCircular.tamanho() << endl;

    int posicao = 2;
    listaCircular.remover(posicao);
    cout << "Removendo elemento na posicao " << posicao << ":" << endl;
    listaCircular.imprimir();

    posicao = 0;
    listaCircular.remover(posicao);
    cout << "Removendo elemento na posicao " << posicao << ":" << endl;
    listaCircular.imprimir();

    return 0;
}