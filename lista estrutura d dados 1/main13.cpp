#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	//Questão 13
	float Vh, Ht,VT;
	cout << "Digite o valor recebido por horas trabalhadas: ";
	cin >> Vh;
	
	cout << "Digite a quantidade de horas trabalhadas: ";
	cin >> Ht;
	
	VT = Vh*Ht;
	float IR,IN,SI,Sobra;
	
	cout << "Salario Total:R$"<<VT;
	
	IR = VT*0.11;
	IN = VT*0.08;
	SI = VT*0.05;
	
	Sobra = VT-IR-IN-SI;
	cout << "\nDescotado Imposto de Renda:R$"<<IR;
	cout << "\nDescontado INSS:R$"<<IN;
	cout << "\nDescontado Sindicato:R$"<<SI;
	cout << "\nValor final :"<<Sobra;
	
	
	
	return 0;
}
