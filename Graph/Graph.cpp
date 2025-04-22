#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int num_vertices) {
    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Graph::NumeroVertices(){
    return num_vertices_;
};
int Graph::NumeroArestas(){
    return num_arestas_;
};

bool Graph::ExisteAresta(Aresta aresta){
    if (matriz_adj_[aresta.v1][aresta.v2] == 1){
        return true;
    }
    
    return false;
};

void Graph::AdicionaAresta(Aresta aresta){
    if (ExisteAresta(aresta)){
        cout << "Aresta ja existe";
        return;
    }

    if (aresta.v1 == aresta.v2){
        cout << "Não é permitido laço";
        return;
    }
    
    matriz_adj_[aresta.v1][aresta.v2] = 1;
    matriz_adj_[aresta.v2][aresta.v1] = 1;
    num_arestas_++;
};

void Graph::RemoveAresta(Aresta aresta){
    if (!ExisteAresta(aresta)){
        cout << "Aresta não existe";
        return;
    }

    matriz_adj_[aresta.v1][aresta.v2] = 0;
    matriz_adj_[aresta.v2][aresta.v1] = 0;
    num_arestas_--;
};

void Graph::PrintGraph() {
    for (int i = 0; i < num_vertices_; i++) {
        bool temVizinho = false;
        for (int j = 0; j < num_vertices_; j++) {
            if (matriz_adj_[i][j] == 1) {
                if (!temVizinho) {
                    cout << i;
                    temVizinho = true;
                }
                cout << " -> " << j;
            }
        }
        if (temVizinho) {
            cout << endl;
        }
    }
}

void Graph::DestroyGraph(){
    matriz_adj_.clear();
    num_vertices_ = 0;
    num_arestas_ = 0;
};

void Graph::ExistePasseio(){
    int p1, p2, p3, p4, p5;
    cout << "Digite 5 elementos para validar passeio" << endl;
    cin >> p1 >> p2 >> p3 >> p4 >> p5;
    if (matriz_adj_[p1][p2] == 1 && matriz_adj_[p2][p3] == 1 && matriz_adj_[p3][p4] == 1 && matriz_adj_[p4][p5] == 1){
        cout << "Existe passeio" << endl;
    } else {
        cout << "Não existe passeio" << endl;
    }
};

bool Graph::ExisteCaminho(int v, int w, std::vector<int>& marcado_, int num_vertices, int identacao) {
    cout << string(identacao * 2, ' ') << "caminho(" << v << ", " << w << ")" << endl;

    marcado_[v] = 1;

    if (v == w) return true;

    for (int u = 0; u < num_vertices; u++) {
        if (matriz_adj_[v][u] != 0 && marcado_[u] == 0) {
            if (ExisteCaminho(u, w, marcado_, num_vertices, identacao + 1)) {
                return true;
            }
        }
    }

    return false;
};



