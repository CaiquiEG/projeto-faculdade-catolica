#include <iostream>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
using namespace std;

    const double cl = 3.0; 
    const double litros = 18.0;   
    const double  vl = 80.0;        

    double area;
    cout << "Digite o tamanho da área a ser pintada em metros quadrados: ";
    cin >> area;

    
    double ln = ceil(area / cl);
    int cn = ceil(ln / litros);
    double pt = cn * vl;

    cout << "Quantidade de latas de tinta necessárias: " << cn << endl;
    cout << "Preço total: R$ " << pt << endl;

    return 0;
	
}
