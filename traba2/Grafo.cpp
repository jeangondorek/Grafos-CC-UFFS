/*
* Trabalho 2 - Coloracao
*
* GEN254 - Grafos - 2025/1
*
* Nome:      JEAN CANOVA
* Matricula: 1921101059
* Nome:      GUSTAVO ALBERTON
* Matricula: XXXX
*/

#include "Grafo.h"
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

Grafo::Grafo(int num_vertices) {
    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Grafo::NumeroVertices(){
    return num_vertices_;
}

int Grafo::NumeroArestas(){
    return num_arestas_;
}

bool Grafo::ExisteAresta(Aresta aresta){
    if (matriz_adj_[aresta.v1][aresta.v2] == 1){
        return true;
    }
    
    return false;
}

void Grafo::AdicionaAresta(Aresta aresta){
    if (ExisteAresta(aresta)){
        cout << "Aresta ja existe, v1: " << aresta.v1 << ", v2: " << aresta.v2 << endl;
        return;
    }

    if (aresta.v1 == aresta.v2){
        cout << "Não é permitido laço" << endl;
        return;
    }

    lista_arestas_.push_back(aresta);
    num_arestas_++;

    matriz_adj_[aresta.v1][aresta.v2] = 1;
    matriz_adj_[aresta.v2][aresta.v1] = 1;
}

void Grafo::constroi_coloracao_1(){
    vector<int> cores(num_vertices_, 0);
    int qtdCores = 0;

    for (int i = 0; i < num_vertices_; i++){
        set<int> coresaux;
        for (int u = 0; u < num_vertices_; u++){
            if (matriz_adj_[i][u] == 1 && cores[u] != 0) {
                coresaux.insert(cores[u]);
            }
        }

        int menorcor = 1;
        while (coresaux.count(menorcor) != 0){
            menorcor++;
        }
        cores[i] = menorcor;
        if (menorcor > qtdCores) {
            qtdCores = menorcor;
        }
    }

    cout << "Numero de cores: " << qtdCores << endl;

    for(int k = 1; k <= qtdCores; k++){
        cout << "Cor " << k << ": ";
        for (int i = 0; i < num_vertices_; i++)
        {
            if (cores[i] == k) {
                cout << " " << i;
            }
        }
        cout << endl;
    }
}

void Grafo::constroi_coloracao_2() {

}

int Grafo::grau(int v) {
    int grau = 0;
    for (int i = 0; i < num_vertices_; i++) {
        if (matriz_adj_[v][i] == 1) {
            grau++;
        }
    }
    return grau;
}
