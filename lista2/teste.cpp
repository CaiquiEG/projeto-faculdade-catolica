#include <iostream>
#include <cmath>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
        i += 6;
    }

    return true;
}

int main() {
    int numero;
    std::cout << "Digite um número: ";
    std::cin >> numero;

    if (is_prime(numero)) {
        std::cout << numero << " é um número primo." << std::endl;
    } else {
        std::cout << numero << " não é um número primo." << std::endl;
    }

    return 0;
}

