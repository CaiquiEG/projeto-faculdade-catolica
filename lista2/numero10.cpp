#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	
	int n1,n2,soma;
	
	cout << "Digite um numero(0-5): ";
	cin >> n1;
	cout << "Digite outro numero(0-5): ";
	cin >> n2;
	
	soma=n1+n2;
	
	switch (soma){
		case 0:
			cout << "MEIO DIA";
			break;
		case 1:
			cout << "ROCK NO SERTÃO";
			break;
		case 2:
			cout << "SAGA DE UM VAQUEIRO";
			break;
		case 3:
			cout << "BOTA PEGADO PAREA";
			break;
		case 4:
			cout << "PONTO FINAL";
			break;
		case 5:
			cout << "LUZ CÂMERA AÇÃO";
			break;
		case 6:
			cout << "TOMACONTA DE MIM";
			break;
		case 7:
			cout << "OLHA PRO CÉU";
			break;
		case 8:
			cout << "OLHINHOS DE FOGUEIRA";
			break;
		case 9:
			cout << "RANCHEIRA";
			break;
		case 10:
			cout << "AVOANTE";
			break;
		default:
			cout << "opçao invalida!!";
			break;
	}
		
	
	return 0;
}
