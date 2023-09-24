#include <iostream>

using namespace std;
char lugares[10][10];
char lu[10]={'A','B','C','D','E','F','G','H','I','J'};
void Lugares(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++) {
            lugares[i][j] = 'V';
        }
    }
}
void Mostrar_lugares(){
    cout << "\n\t\tLUGARES VAGOS\n   1   2   3   4   5   6   7   8   9   10\n_________________________________________\n";
    for(int i=0;i<10;i++){
        cout << lu[i];
        for(int j=0;j<10;j++){
            cout << "| "<<lugares[i][j]<<" ";
        }
        cout << "|\n";
    }
}
int Checa_Uso(int l,int c){
    if (l >= 0 && l < 10 && c >= 0 && c < 10 && lugares[l][c] == 'V') {
        return 1;
    } else {
        return 0;
    }

}
void escolha() {
    char linha;
    int coluna;

    do {
        cout << "\n Digite a letra da fileira: ";
        cin >> linha;
        cout << "Digite o numero da coluna: ";
        cin >> coluna;
        cout << endl;

        int indice = -1;

        for (int i = 0; i < 10; i++) {
            if (lu[i] == linha) {
                indice = i;
                break;
            }
        }

        if (indice != -1) {
            if (Checa_Uso(indice, coluna - 1) == 0) {
                cout << "Lugar já está ocupado, escolha outro.\n";
            } else {
                lugares[indice][coluna - 1] = 'X';
                break;
            }
        } else {
            cout << "Fileira inválida." << endl;
        }
    } while (true);
}



void menu(){
    cout << "1-Iniciar Venda\n"
            "2-Mostrar Lugares\n"
            "3-Relatorio de Vendas\n"
            "4-Encerrar Vendas\n"
            "5-Encerrar Programa";
}

int main() {
    Lugares();
    int opcao = 0;
    int cont = 0;
    int continuar = 1;

    while (continuar == 1) {
        menu();
        cout << "\nDigite a opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                Mostrar_lugares();
                escolha();
                cont++;
                break;
            case 2:
                Mostrar_lugares();
                break;
            case 3:
                cout << "\nRelatorio: \n"
                        "Lugares vendidos:" << cont << "\nValor arrecadado: R$" << cont * 12.50<<"\n";
                break;
            case 4:
                cout << "\nRelatorio: \n"
                        "Lugares vendidos:" << cont << "\nValor arrecadado: R$" << cont * 12.50<<"\n";
                cout << "Encerrando vendas";
                Lugares();
                cont=0;
                break;
            case 5:

                continuar = 0;
                break;
            default:
                cout << "Opcao invalida";
                break;
        }
    }


}
