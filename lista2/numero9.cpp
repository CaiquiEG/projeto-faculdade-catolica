#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	
	double salario;
	double aumentoS;
	cout << "digite seu salario: ";
	cin >> salario;
	if (salario <=280){
		 aumentoS += salario * 0.20;
		 cout << "R$ "<< salario << " Salario antes do reajuste \n20% percentual aumentado\n"<<"R$" << aumentoS<<" valor do aumento\n"<<"R$"<< aumentoS+salario<<" novo salario,apos o aumento" ;
	}else if (salario >=281 && salario <=700){
		aumentoS += salario * 0.15;
		cout << "R$ "<< salario << " Salario antes do reajuste \n15% percentual aumentado\n"<<"R$" << aumentoS<<" valor do aumento\n"<<"R$"<< aumentoS+salario<<" novo salario,apos o aumento" ;
	}else if (salario >= 701 && salario <= 1500){
		aumentoS += salario *0.10;
		cout << "R$ "<< salario << " Salario antes do reajuste \n10% percentual aumentado\n"<<"R$" << aumentoS<<" valor do aumento\n"<<"R$"<< aumentoS+salario<<" novo salario,apos o aumento" ;
	}else{
		aumentoS += salario *0.05;
		cout << "R$ "<< salario << " Salario antes do reajuste \n5% percentual aumentado\n"<<"R$" << aumentoS<<" valor do aumento\n"<<"R$"<< aumentoS+salario<<" novo salario,apos o aumento" ;
	}
	
	
	
	
	
	
	
	return 0;
}
