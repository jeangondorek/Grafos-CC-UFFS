#ifndef FIRSTGRAPH_H
#define FIRSTGRAPH_H

#include "Aresta.h"

#include <vector>

class FirstGraph {
    private:
        int num_arestas_;
        int num_vertices_;
        std::vector<std::vector<int>> matriz_adj_;
    public:
        FirstGraph (int num_vertices);
        int NumeroVertices();
        int NumeroArestas();
        bool ExisteAresta(Aresta aresta);
        void AdicionaAresta(Aresta aresta);
        void RemoveAresta(Aresta aresta);
        void PrintGraph();
        void DestroyGraph();
        void ExistePasseio();
        void ExisteCaminho();
};

#endif
