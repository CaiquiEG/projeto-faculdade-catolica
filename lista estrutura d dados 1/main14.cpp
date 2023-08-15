#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;

	//Questão 14
	int i,j;
	for(i = 1; i<10;i++){
		cout << "Tabuada do " << i << ":\n";
		for(j = 1; j <=10;j++){
			cout << i << " x " << j << " = " << i * j << "\n";
		}
	}
	
	
	
	
	
	return 0;
}
