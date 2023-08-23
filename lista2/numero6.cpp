#include <iostream>
#include <cmath>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	
	int num,i=5;
	bool primo=true;
	cout << "Digite um numero: ";
	cin >> num;
	
	
	if(num <= 1 ){
		primo = false;
	}else if (num <= 3){
		primo = false;
	}else if (num % 2 == 0 || num % 3 == 0) {
        primo = false;
	}else{
	  while (i * i <= num) {
        if (num % i == 0 || num % (i + 2) == 0) {
            primo = false;
            break;
        }
        i += 6;
    }	
}
	if (primo){
		cout << num << " e um numero primo."<<endl;
	}else{
		cout << num<<" nao e um numero primo."<< endl;
	}
	return 0;
}
