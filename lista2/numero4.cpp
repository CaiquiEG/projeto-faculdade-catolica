#include <iostream>
#include <vector>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	
	vector<int> list;
	int numero;
	char cont ='S';
	while(cont == 'S' || cont =='s'){
		cout << "Digite numeros a vontade: ";
		cin >> numero;
		list.push_back(numero);
		cout << "Quer continuar colocando numeros na lista?(S/N)";
		cin >> cont;
		if (cont == 'N' || cont == 'n'){
			break;
		}
		
	}
	int i;
	int soma=0;
	int menor = 0;
    int maior = 0;
    
	for(i=0;i<list.size();i++){
		
		if(i==0){ 
         maior=list[i];
         menor=list[i];
         }
         else if(list[i]>maior){
             maior=list[i];
         }
        else if(list[i]<menor){
            menor=list[i];
        }
		
		soma+=list[i];
	}
	cout << "O maior numero digitado foi: "<< maior << endl;
	cout << "O menor numero digitado foi: "<<  menor << endl;
	cout << "A soma de todos os numeros digitados e: "<< soma << endl;
	
	
	
	
	
	return 0;
}
