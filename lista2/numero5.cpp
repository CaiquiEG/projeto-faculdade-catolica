#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	int num;
	cout << "digite um numero: ";
	cin >> num;
	
	
	int j;
	cout << "Tabuada do " << num << ":\n";
	for(j = 1; j <=10;j++){
		cout << num << " x " << j << " = " << num * j << "\n";
	}
	
	
	return 0;
}
