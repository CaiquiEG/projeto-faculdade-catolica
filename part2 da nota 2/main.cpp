#include <iostream>
#include <queue>
#include <string>
#include <list>
using namespace std;


struct Disciplina {
    string nome;
    int creditos;
    list<string> conteudo;

    Disciplina(string n, int c) : nome(n), creditos(c) {}
};


struct Aluno {
    string nome;
    string cpf;
    int idade;
    string matricula;
    list<Disciplina> disciplinas;

    Aluno(string n, string c, int i, string m) : nome(n), cpf(c), idade(i), matricula(m) {}
};


bool isEmpty(queue<Aluno>& filaDeAlunos) {
    return filaDeAlunos.empty();
}


int tamanhoFila(queue<Aluno>& filaDeAlunos) {
    return filaDeAlunos.size();
}


void adicionarAluno(queue<Aluno>& filaDeAlunos, Aluno aluno) {
    filaDeAlunos.push(aluno);
}


Aluno alunoNaFrente(queue<Aluno>& filaDeAlunos) {
    return filaDeAlunos.front();
}


void removerAluno(queue<Aluno>& filaDeAlunos) {
    filaDeAlunos.pop();
}


void adicionarDisciplina(Aluno& aluno, Disciplina disciplina) {
    aluno.disciplinas.push_back(disciplina);
}



void removerDisciplina(Aluno& aluno, const string& nomeDisciplina) {
    for (list<Disciplina>::iterator it = aluno.disciplinas.begin(); it != aluno.disciplinas.end(); ) {
        if (it->nome == nomeDisciplina) {
            it = aluno.disciplinas.erase(it);
        } else {
            ++it;
        }
    }
}





void listarDisciplinas(Aluno& aluno) {
    cout << "Disciplinas do aluno " << aluno.nome << ":" << endl;
    for (const Disciplina& disciplina : aluno.disciplinas) {
        cout << "Nome: " << disciplina.nome << ", Creditos: " << disciplina.creditos << endl;
    }
}


void adicionarConteudo(Disciplina& disciplina, string novoConteudo) {
    disciplina.conteudo.push_back(novoConteudo);
}


void removerConteudo(Disciplina& disciplina, string conteudo) {
    disciplina.conteudo.remove(conteudo);
}


void listarConteudos(const Disciplina& disciplina) {
    cout << "Conteudos da disciplina " << disciplina.nome << ":" << endl;
    for (const string& conteudo : disciplina.conteudo) {
        cout << conteudo << endl;
    }
}


void listarTodosAlunos(queue<Aluno>& filaDeAlunos) {
    queue<Aluno> filaCopia = filaDeAlunos;

    while (!filaCopia.empty()) {
        Aluno aluno = filaCopia.front();
        cout << "Nome: " << aluno.nome << ", CPF: " << aluno.cpf << ", Matricula: " << aluno.matricula << endl;
        listarDisciplinas(aluno);
        for (const Disciplina& disciplina : aluno.disciplinas) {
            listarConteudos(disciplina);
        }
        cout << endl;
        filaCopia.pop();
    }
}


int main() {
    queue<Aluno> filaDeAlunos;

    Aluno aluno1("Caiqui", "123456789", 20, "2023001");
    aluno1.disciplinas.push_back(Disciplina("Matematica", 4));
    adicionarAluno(filaDeAlunos, aluno1);

    Aluno aluno2("Gustavo", "987654321", 22, "2023002");
    aluno2.disciplinas.push_back(Disciplina("Fisica", 5));
    adicionarAluno(filaDeAlunos, aluno2);


    Aluno aluno3("Joao", "123456789", 20, "2023001");
    aluno3.disciplinas.push_back(Disciplina("Matematica", 4));
    aluno3.disciplinas.push_back(Disciplina("Historia", 3));
    aluno3.disciplinas.push_back(Disciplina("Fisica", 4));
    filaDeAlunos.push(aluno3);

        Aluno aluno4("Julio", "987654321", 22, "2023002");
        aluno4.disciplinas.push_back(Disciplina("Quimica", 5));
        filaDeAlunos.push(aluno2);

        adicionarConteudo(aluno1.disciplinas.front(), "algebra linear");


        listarTodosAlunos(filaDeAlunos);


        removerDisciplina(aluno1, "Historia");


        listarDisciplinas(aluno1);


        removerConteudo(aluno1.disciplinas.front(), "Algebra linear");


        listarConteudos(aluno1.disciplinas.front());


        bool vazia = isEmpty(filaDeAlunos);
        cout << "A fila de alunos esta vazia? " << (vazia ? "Sim" : "Nao") << endl;


        int tamanho = tamanhoFila(filaDeAlunos);
        cout << "Tamanho da fila de alunos: " << tamanho << endl;

    Aluno alunoFrente = alunoNaFrente(filaDeAlunos);
    cout << "Aluno na frente da fila: " << alunoFrente.nome << endl;


    removerAluno(filaDeAlunos);
    cout << "Removendo aluno da frente da fila." << endl;


    Disciplina disciplina1("Matematica", 4);
    Disciplina disciplina2("Historia", 3);

    adicionarDisciplina(aluno2, disciplina1);
    adicionarDisciplina(aluno2, disciplina2);


    listarDisciplinas(aluno2);

        return 0;
    }

