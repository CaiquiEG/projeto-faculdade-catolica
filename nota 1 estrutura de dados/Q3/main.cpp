#include <iostream>


using namespace std;

void selection_sort(string nomes[], int tam);

void selection_sort(string nomes[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int indice_min = i;


        for (int j = i + 1; j < tam; j++) {
            if (nomes[j] < nomes[indice_min]) {
                indice_min = j;
            }
        }


        if (indice_min != i) {
            swap(nomes[i], nomes[indice_min]);
        }
    }
}

int main() {

    int qtd;
    cout << "Digite quantos nomes ira inserir na lista: ";
    cin >> qtd;
    string nomes[qtd];

    for (int i = 0; i < qtd; i++) {
        cout << "Digite o nome #" << i + 1 << ": "<<endl;
        cin >> nomes[i];
    }

    cout << "\nLista de nomes na ordem que foi digitada:" << endl;
    for (int i = 0; i < qtd; i++) {
        cout << nomes[i] << endl;
    }

    selection_sort(nomes, qtd);

    cout << "\nLista de nomes em ordem alfabetica:" << endl;
    for (int i = 0; i < qtd; i++) {
        cout << nomes[i] << endl;
    }

    return 0;
}
