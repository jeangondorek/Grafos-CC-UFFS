#include "FirstGraph.h"
#include <iostream>

using namespace std;

FirstGraph::FirstGraph(int num_vertices) {
    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int FirstGraph::NumeroVertices(){
    return num_vertices_;
};
int FirstGraph::NumeroArestas(){
    return num_arestas_;
};

bool FirstGraph::ExisteAresta(Aresta aresta){
    if (matriz_adj_[aresta.v1][aresta.v2] == 1){
        return true;
    }
    
    return false;
};

void FirstGraph::AdicionaAresta(Aresta aresta){
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

void FirstGraph::RemoveAresta(Aresta aresta){
    if (!ExisteAresta(aresta)){
        cout << "Aresta não existe";
        return;
    }

    matriz_adj_[aresta.v1][aresta.v2] = 0;
    matriz_adj_[aresta.v2][aresta.v1] = 0;
    num_arestas_--;
};

void FirstGraph::PrintGraph() {
    for (int i = 0; i < num_vertices_; i++) {
        bool temVizinho = false;
        for (int j = 0; j < num_vertices_; j++) {
            if (matriz_adj_[i][j] == 1) {
                if (!temVizinho) {
                    cout << i; // Imprime o vértice apenas uma vez
                    temVizinho = true;
                }
                cout << " -> " << j;
            }
        }
        if (temVizinho) {
            cout << endl; // Finaliza a linha apenas se o vértice tiver vizinhos
        }
    }
}
void FirstGraph::DestroyGraph(){
    for (int i = 0; i < num_vertices_; i++){
        matriz_adj_[i].clear();
    }
    matriz_adj_.clear();
    num_vertices_ = 0;
    num_arestas_ = 0;
};

void FirstGraph::ExistePasseio(){
    int p1, p2, p3, p4, p5;
    cout << "Existe passeio de 5 elementos" << endl;
    cin >> p1 >> p2 >> p3 >> p4 >> p5;
    if (matriz_adj_[p1][p2] == 1 && matriz_adj_[p2][p3] == 1 && matriz_adj_[p3][p4] == 1 && matriz_adj_[p4][p5] == 1){
        cout << "Existe passeio" << endl;
    } else {
        cout << "Não existe passeio" << endl;
    }
};

void FirstGraph::ExisteCaminho(){
    int c1, c2, c3, c4;
    cout << "Existe caminho de 4 elementos" << endl;
    cin >> c1 >> c2 >> c3 >> c4;
    if (matriz_adj_[c1][c2] == 1 && matriz_adj_[c2][c3] == 1 && matriz_adj_[c3][c4] == 1){
        cout << "Existe caminho" << endl;
    } else {
        cout << "Não existe caminho" << endl;
    }
};