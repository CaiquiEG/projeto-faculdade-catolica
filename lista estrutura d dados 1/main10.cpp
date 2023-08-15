#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	//Questão 10
	
	float gcl;
	
	cout << "temperatura em  graus Celsius: ";
	cin >> gcl;
	
	cout <<"Temperatura convertida para Fahrenheit : " << (gcl*1.8)+32;
	
	
	return 0;
}
