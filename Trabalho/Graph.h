#ifndef GRAPH_H
#define GRAPH_H

#include "Aresta.h"

#include <vector>

class Graph {
    private:
        int num_arestas_;
        int num_vertices_;
        std::vector<std::vector<int>> matriz_adj_;
        std::vector<Aresta> lista_arestas_;
    public:
        Graph (int num_vertices);
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
        void CarregarGrafoDoArquivo(const char* nome_arquivo);
        bool Bipartido1(std::vector<int> &divisao1, std::vector<int> &divisao2, std::vector<bool> &removidos);
        bool Bipartido2(std::vector<int> &divisao1, std::vector<int> &divisao2, std::vector<bool> &removidos);
        bool ReturnSePodeInserirDivisao(const std::vector<int>& divisao, int v);
        bool DFSVerificaBipartido(int v, std::vector<int>& conjunto);
};

#endif
