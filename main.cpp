#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char** argv) {
    using namespace std;

    std::vector<std::string> nomes;
    nomes.push_back("Maria");
    nomes.push_back("Bruna");
    nomes.push_back("Alberto");
    nomes.push_back("Joao");

    cout << "Ordem normal \n";
    for (int i = 0; i < 4; i++) {
        cout << nomes[i] << endl;
    }

    std::sort(nomes.begin(), nomes.end());
    cout << "Ordem alfabetica \n";
    for (const std::string& nome : nomes) {
        cout << nome << endl;
    }

    return 0;
}