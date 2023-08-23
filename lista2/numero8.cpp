#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;

    int num;
   	cout << "Digite o valor de n: ";
    cin >> num;

    int tat = 0;
    int tet = 1;
    int ent;

    if (num <= 0) {
        ent = 0;
    } else if (num == 1) {
        ent = 1;
    } else {
        for (int i = 2; i <= num; ++i) {
            ent = tet + tat;
            tat = tat;
            tat = ent;
        }
    }

    cout << "O enesimo termo do numero " << num << " da serie de Fibonacci e: " << ent << endl;

    return 0;
}
	

