#include "Circulo.h"
#include <iostream>
#include <iomanip>

using namespace std;

Circulo::Circulo(long double raio) {
    raio_ = raio;
}

long double Circulo::calcularArea() {
    return 3.1415 * raio_ * raio_;
}

long double Circulo::calcularPerimetro() {
    return 2 * 3.1415 * this -> raio_;
    // 2 métodos de acesso ao atributo raio_
    // this -> raio_ é o mesmo que raio_
}

void Circulo::imprimeArea() {
    cout << "Area do circulo: " << calcularArea() << endl;
    // se não usar using namespace std; pode usar std::cout
}

void Circulo::imprimePerimetro() {
    cout << "Perimetro do circulo: " << calcularPerimetro() << "\n";
    // \n é um caractere de escape que representa uma quebra de linha
    // é o mesmo que std::endl
    // ou << endl
}