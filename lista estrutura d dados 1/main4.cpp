#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;

	//Questão 4
	
	float nota1,nota2,nota3,nota4;
	float media;
	
	cout << "Digite as quatro notas bimestrais: ";
	cin >> nota1>>nota2>>nota3>>nota4;
	
	media = (nota1+nota2+nota3+nota4)/4;
	cout << "Sua media e: "<<media;
	
	
	
	
	return 0;
}
