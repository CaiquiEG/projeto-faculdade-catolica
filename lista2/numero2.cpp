#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	int num1;
	int num2;
	cout << "digite um numero: ";
	cin >> num1;
	cout << "digite outro numero: ";
	cin >> num2;
	
	if (num1 > num2){
		cout << "este numero e o maior: "<< num1;
	}else{
		cout << "este numero e o maior: "<< num2;
	}
	
	return 0;
}
