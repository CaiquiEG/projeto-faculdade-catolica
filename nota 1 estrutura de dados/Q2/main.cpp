#include <iostream>
#include <string>

using namespace std;

void insertion_sort(string& nome) {
    int tam = nome.length();
    for (int i = 1; i < tam; i++) {
        char letra = nome[i];
        int index = i - 1;

        while (index >= 0 && nome[index] < letra) {
            nome[index + 1] = nome[index];
            index = index - 1;
        }
        nome[index + 1] = letra;
    }
}

int main() {
    string nome;
    cout << "Digite um nome: ";
    cin >> nome;

    cout << "Nome antes de reajustar suas letras em ordem decrescente:\n" << nome << endl;

    insertion_sort(nome);

    cout << "Nome depois de reajustar suas letras em ordem decrescente:\n" << nome << endl;

    return 0;
}
