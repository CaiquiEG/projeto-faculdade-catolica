#include <iostream>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	
	//Questão 6
	
	float raio;
	
	cout << "Digite o raio do circulo: ";
	cin >> raio;
	
	float area=pow(raio,2)*3.14;
	
	cout << "Area do circulo: "<<area;
	
	
	return 0;
}
