#include <iostream>

using namespace std;

void insertion_sort(string nomes[],int tam);

void insertion_sort(string nomes[],int tam){
    for(int i =1; i<tam;i++){
        string nome = nomes[i];
        int index = i-1;

        while(index >= 0 && nomes[index]>nome){
            nomes[index+1]=nomes[index];
            index = index - 1;

        }
        nomes[index+1]=nome;
    }
}
int main() {
    int qtd;
    cout << "Digite quantos nomes ira inserir na lista: ";
    cin >> qtd;
    string nomes[qtd];

    for(int i = 0; i<qtd;i++){
        cout << "\nDigite os nomes que deseja inserir na lista: ";
        cin >> nomes[i];
    }
    cout << "\nLista de nomes na ordem que foi digitada: "<< endl;
    for(int i = 0;i < qtd; i++){
        cout << nomes[i] << endl;
    }
    insertion_sort(nomes,qtd);
    cout << "\nLista de nomes em ordem alfabetica: "<< endl;
    for(int i = 0;i < qtd; i++){
        cout << nomes[i] << endl;
    }
    return 0;
}