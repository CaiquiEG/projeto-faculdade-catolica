#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	int soma_I=0,soma_P=0,n=0;
	while (n<1000){
		cout << "Digite um numero: ";
		cin >> n;
		if(n%2==0){
			soma_P+=n;
		}else{
			soma_I+=n;
		}
	}
	
	cout << "A soma dos numenos pares e "<< soma_P;
	cout << "\nA soma dos numenos impares e "<< soma_I;
	
		
	
	
	
	return 0;
}
