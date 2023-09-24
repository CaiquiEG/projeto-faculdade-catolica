#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int tamanho = 30;
    int vetor[tamanho];

     cout << "Digite os " << tamanho << " numeros:" <<  endl;
    for (int i = 0; i < tamanho; i++) {
         cin >> vetor[i];
    }

    quickSort(vetor, 0, tamanho - 1);

     cout << "Vetor ordenado em ordem crescente:" <<  endl;
    for (int i = 0; i < tamanho; i++) {
         cout << vetor[i] << " ";
    }
     cout <<  endl;

    return 0;
}
