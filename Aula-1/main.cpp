#include "Circulo.h"
#include <iostream>

using namespace std;

void imprimeAreaCirculo(Circulo& c) {
    c.imprimeArea();
}

void imprimePerimetroCirculo(Circulo& c) {
    c.imprimePerimetro();
}

class Pilha {
    private:
        int elementos[100]; // Array para armazenar os elementos da pilha
        int topo; // Índice do topo da pilha    

public:
    Pilha() : topo(-1) {} // Construtor inicializa o topo como -1

    void push(int valor) {
        if (topo < 99) { // Verifica se há espaço na pilha
            elementos[++topo] = valor;
        } else {
            cout << "Pilha cheia!" << endl;
        }
    }

    int pop() {
        if (topo >= 0) { // Verifica se a pilha não está vazia
            return elementos[topo--];
        } else {
            cout << "Pilha vazia!" << endl;
            return -1; // Retorna um valor inválido se a pilha estiver vazia
        }
    }

    bool isEmpty() {
        return topo == -1;
    }

    friend ostream& operator<<(ostream& os, const Pilha& pilha) {
        os << "Pilha: ";
        for (int i = 0; i <= pilha.topo; ++i) {
            os << pilha.elementos[i] << " ";
        }
        return os;
    }
};

int main() {
    long double raiDoCeu;

    cout << "Digite o raio do circulo: "; //para escrever na tela
    cin >> raiDoCeu; //para ler um valor do teclado

    Circulo c(raiDoCeu);
    imprimeAreaCirculo(c);
    imprimePerimetroCirculo(c);

    cout << "Digite o raio do circulo2: "; //para escrever na tela
    cin >> raiDoCeu;
    c = Circulo(raiDoCeu);
    imprimeAreaCirculo(c);
    imprimePerimetroCirculo(c);


    Pilha pilha;

    // Insira dois elementos na pilha
    pilha.push(10);
    pilha.push(20);

    cout << pilha << endl;

    // Remova os dois elementos da pilha imprimindo seus valores
    while (!pilha.isEmpty()) {
        cout << "Elemento removido da pilha: " << pilha.pop() << endl;
    }

    cout << "PIlha Vazia" << pilha << endl;


    return 0;
}