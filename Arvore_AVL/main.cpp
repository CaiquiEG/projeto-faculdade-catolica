#include <iostream>

using namespace std;
struct No {
    int chave;
    No* esquerda;
    No* direita;
    int altura;

    No(int k) : chave(k), esquerda(nullptr), direita(nullptr), altura(1) {}
};

int obterMaximo(int a, int b) {
    return (a > b) ? a : b;
}

int altura(No* no) {
    return (no == nullptr) ? 0 : no->altura;
}

int obterBalanceamento(No* no) {
    return (no == nullptr) ? 0 : altura(no->esquerda) - altura(no->direita);
}

No* rotacionarDireita(No* y) {
    No* x = y->esquerda;
    No* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = 1 + obterMaximo(altura(y->esquerda), altura(y->direita));
    x->altura = 1 + obterMaximo(altura(x->esquerda), altura(x->direita));

    return x;
}

No* rotacionarEsquerda(No* x) {
    No* y = x->direita;
    No* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = 1 + obterMaximo(altura(x->esquerda), altura(x->direita));
    y->altura = 1 + obterMaximo(altura(y->esquerda), altura(y->direita));

    return y;
}

No* inserir(No* no, int chave) {
    if (no == nullptr) {
        return new No(chave);
    }

    if (chave < no->chave) {
        no->esquerda = inserir(no->esquerda, chave);
    } else if (chave > no->chave) {
        no->direita = inserir(no->direita, chave);
    } else {

        return no;
    }

    no->altura = 1 + obterMaximo(altura(no->esquerda), altura(no->direita));

    int balanceamento = obterBalanceamento(no);


    if (balanceamento > 1 && chave < no->esquerda->chave) {
        return rotacionarDireita(no);
    }

    if (balanceamento < -1 && chave > no->direita->chave) {
        return rotacionarEsquerda(no);
    }

    if (balanceamento > 1 && chave > no->esquerda->chave) {
        no->esquerda = rotacionarEsquerda(no->esquerda);
        return rotacionarDireita(no);
    }

    if (balanceamento < -1 && chave < no->direita->chave) {
        no->direita = rotacionarDireita(no->direita);
        return rotacionarEsquerda(no);
    }

    return no;
}

No* obterNoComMenorValor(No* no) {
    No* atual = no;
    while (atual->esquerda != nullptr) {
        atual = atual->esquerda;
    }
    return atual;
}

No* removerNo(No* raiz, int chave) {
    if (raiz == nullptr) {
          cout << "O no com chave " << chave << " nao existe na arvore." <<   endl;
        return raiz;
    }

    if (chave < raiz->chave) {
        raiz->esquerda = removerNo(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = removerNo(raiz->direita, chave);
    } else {
        if (raiz->esquerda == nullptr || raiz->direita == nullptr) {
            No* temp = raiz->esquerda ? raiz->esquerda : raiz->direita;

            if (temp == nullptr) {
                temp = raiz;
                raiz = nullptr;
            } else {
                *raiz = *temp;
            }

            delete temp;
        } else {
            No* temp = obterNoComMenorValor(raiz->direita);

            raiz->chave = temp->chave;

            raiz->direita = removerNo(raiz->direita, temp->chave);
        }
    }

    if (raiz == nullptr) {
        return raiz;
    }

    raiz->altura = 1 + obterMaximo(altura(raiz->esquerda), altura(raiz->direita));

    int balanceamento = obterBalanceamento(raiz);

    if (balanceamento > 1 && obterBalanceamento(raiz->esquerda) >= 0) {
        return rotacionarDireita(raiz);
    }

    if (balanceamento > 1 && obterBalanceamento(raiz->esquerda) < 0) {
        raiz->esquerda = rotacionarEsquerda(raiz->esquerda);
        return rotacionarDireita(raiz);
    }

    if (balanceamento < -1 && obterBalanceamento(raiz->direita) <= 0) {
        return rotacionarEsquerda(raiz);
    }

    if (balanceamento < -1 && obterBalanceamento(raiz->direita) > 0) {
        raiz->direita = rotacionarDireita(raiz->direita);
        return rotacionarEsquerda(raiz);
    }

    return raiz;
}

void imprimirEmOrdem(No* raiz) {
    if (raiz != nullptr) {
        imprimirEmOrdem(raiz->esquerda);
          cout << raiz->chave << " ";
        imprimirEmOrdem(raiz->direita);
    }
}

int main() {
    No* raiz = nullptr;

    // Inserção
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 25);

      cout << "Arvore AVL apos a insercao: ";
    imprimirEmOrdem(raiz);
      cout <<   endl;

    raiz = removerNo(raiz, 5);

      cout << "Arvore AVL apos a remocao: ";
    imprimirEmOrdem(raiz);

    return 0;
}

