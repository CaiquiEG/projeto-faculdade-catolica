#include <iostream>
#include <string>

using namespace std;


void merge(string& nome, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string leftHalf = nome.substr(left, n1);
    string rightHalf = nome.substr(mid + 1, n2);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftHalf[i] <= rightHalf[j]) {
            nome[k] = leftHalf[i];
            i++;
        } else {
            nome[k] = rightHalf[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        nome[k] = leftHalf[i];
        i++;
        k++;
    }

    while (j < n2) {
        nome[k] = rightHalf[j];
        j++;
        k++;
    }
}


void mergeSort(string& nome, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;


        mergeSort(nome, left, mid);


        mergeSort(nome, mid + 1, right);


        merge(nome, left, mid, right);
    }
}

int main() {
    string nome;
    cout << "Digite um nome: ";
    cin >> nome;

    cout << "Nome antes de reajustar suas letras em ordem crescente:\n" << nome << endl;

    int len = nome.length();
    mergeSort(nome, 0, len - 1);

    cout << "Nome depois de reajustar suas letras em ordem crescente:\n" << nome << endl;

    return 0;
}
