#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	//Questão 5
	
	float metros;
	
	cout << "Digite uma distancia (em metros): ";
	cin >> metros;
	
	cout << "Distancia em centimetos: "<<metros * 100;
	
	return 0;
}
