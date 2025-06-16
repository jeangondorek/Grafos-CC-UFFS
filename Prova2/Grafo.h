#ifndef GRAFO_H
#define GRAFO_H

#include "Aresta.h"

#include <vector>

class Grafo {
    private:
        int num_arestas_;
        int num_vertices_;
        std::vector<std::vector<int>> matriz_adj_;
        std::vector<Aresta> lista_arestas_;
    public:
        Grafo (int num_vertices);
        int NumeroVertices();
        int NumeroArestas();
        bool ExisteAresta(Aresta aresta);
        void AdicionaAresta(Aresta aresta);
        void RemoveAresta(Aresta aresta);
        void RemoveVertice(int v);
        std::vector<int> VerificaVertices();
        void PrintGraph();
        void DestroyGraph();
        void ExistePasseio();
        bool ExisteCaminho(int v1, int v2, std::vector<int>& marcado_, int num_vertices, int identacao);
        bool EhFortementeConexo();
        void DFS(int v, std::vector<bool>& visitado, const std::vector<std::vector<int>>& matriz);
};

#endif
