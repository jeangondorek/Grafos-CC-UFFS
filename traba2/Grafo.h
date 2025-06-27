/*
* Trabalho 2 - Coloracao
*
* GEN254 - Grafos - 2025/1
*
* Nome:      JEAN
* Matricula: 1921101059
* Nome:      GUSTAVO ALBRTON
* Matricula: XXXX
*/

#ifndef GRAFO_H
#define GRAFO_H

#include "Aresta.h"

#include <vector>

class Grafo {
    private:
        int num_arestas_;
        int num_vertices_;
        std::vector<Aresta> lista_arestas_;
        std::vector<std::vector<int>> matriz_adj_;
    public:
        Grafo (int num_vertices);
        int NumeroVertices();
        int NumeroArestas();
        bool ExisteAresta(Aresta aresta);
        void AdicionaAresta(Aresta aresta);
        void constroi_coloracao_1();
        void constroi_coloracao_2();
        int Grafo::grau(int v);
};

#endif
