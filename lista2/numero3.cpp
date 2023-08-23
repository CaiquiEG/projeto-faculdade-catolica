#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	char letra;
	cout << "digite M para Masculino e F para Feminino: ";
	cin >> letra ;
	
	if (letra == 'M' || letra == 'm'){
		cout << "Masculino";
	}else if( letra == 'F' || letra == 'f'){
		cout << "Feminino";
	}else{
		cout << "Bug mental";
	}
	
	
	return 0;
}
