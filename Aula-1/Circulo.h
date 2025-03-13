#ifndef CIRCULO_H
#define CIRCULO_H

class Circulo {
    private:
        long double raio_;
    public:
        Circulo(long double raio);
        long double calcularArea();
        long double calcularPerimetro();
        void imprimeArea();
        void imprimePerimetro();
};

#endif
