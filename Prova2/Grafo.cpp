#include "Grafo.h"
#include <iostream>

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

    matriz_adj_[aresta.v1][aresta.v2] = aresta.estado ? 1 : 0;

    lista_arestas_.push_back(aresta);
    num_arestas_++;
}

void Grafo::RemoveAresta(Aresta aresta){
    if (!ExisteAresta(aresta)){
        cout << "Aresta não existe";
        return;
    }

    matriz_adj_[aresta.v1][aresta.v2] = 0;
    matriz_adj_[aresta.v2][aresta.v1] = 0;
    num_arestas_--;
}

void Grafo::PrintGraph() {
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

void Grafo::DestroyGraph(){
    matriz_adj_.clear();
    num_vertices_ = 0;
    num_arestas_ = 0;
}

void Grafo::ExistePasseio(){
    int p1, p2, p3, p4, p5;
    cout << "Digite 5 elementos para validar passeio" << endl;
    cin >> p1 >> p2 >> p3 >> p4 >> p5;
    if (matriz_adj_[p1][p2] == 1 && matriz_adj_[p2][p3] == 1 && matriz_adj_[p3][p4] == 1 && matriz_adj_[p4][p5] == 1){
        cout << "Existe passeio" << endl;
    } else {
        cout << "Não existe passeio" << endl;
    }
}

bool Grafo::ExisteCaminho(int v, int w, std::vector<int>& marcado_, int num_vertices, int identacao) {
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
}

void Grafo::RemoveVertice(int v) {
    if (v < 0 || v >= num_vertices_) {
        cout << "Vertice invalido" << endl;
        return;
    }

    for (int i = 0; i < num_vertices_; i++) {
        matriz_adj_[v][i] = 0;
        matriz_adj_[i][v] = 0;
    }

    num_arestas_ -= num_vertices_ - 1;
    num_vertices_--;
}

vector<int> Grafo::VerificaVertices() {
    vector<int> vertices;
    for (int i = 0; i < num_vertices_; i++) {
        vertices.push_back(i);
    }
    return vertices;
}

void Grafo::DFS(int v, std::vector<bool>& visitado, const std::vector<std::vector<int>>& matriz) {
    visitado[v] = true;
    for (int u = 0; u < num_vertices_; u++) {
        if (matriz[v][u] == 1 && !visitado[u]) {
            DFS(u, visitado, matriz);
        }
    }
}
    
bool Grafo::EhFortementeConexo() {
    std::vector<bool> visitado(num_vertices_, false);

    DFS(0, visitado, matriz_adj_);
    for (bool v : visitado) {
        if (!v) return false; 
    }

    std::vector<std::vector<int>> transposto(num_vertices_, std::vector<int>(num_vertices_, 0));
    for (int i = 0; i < num_vertices_; i++) {
        for (int j = 0; j < num_vertices_; j++) {
            if (matriz_adj_[i][j] == 1) {
                transposto[j][i] = 1;
            }
        }
    }

    std::fill(visitado.begin(), visitado.end(), false);
    DFS(0, visitado, transposto);
    for (bool v : visitado) {
        if (!v) return false; 
    }

    return true;
}
