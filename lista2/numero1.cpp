#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	using namespace std;
	int n;
	cout << "Digite um numero(positivo ou negativo):";
	cin >> n;
	
	if(n>=0){
		cout << "Numero e positivo";
	}else{
		cout << "Numero e negativo";
	}
	
	
	
	return 0;
}
