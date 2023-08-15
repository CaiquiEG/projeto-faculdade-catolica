#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;

	//Questão 12
	
	float alt,pesoH,pesoM;
	
	cout<<"Digite a altura (em metros): ";
	cin>>alt;
	
	pesoH = (72.7f * alt) + 58;
	pesoM = (62.1f * alt) - 44.7;
	
	cout << "peso ideal para homens: " << pesoH <<" kg " << endl ;
	cout << "peso ideal para mulher: " << pesoM << " kg " << endl ;
	
	
	
	
	
	return 0;
}
