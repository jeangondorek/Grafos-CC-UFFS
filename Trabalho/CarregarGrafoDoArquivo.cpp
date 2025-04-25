#include "Graph.h"
#include "Aresta.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void Graph::CarregarGrafoDoArquivo(const char* nome_arquivo) {
    std::ifstream arquivo(nome_arquivo); 
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nome_arquivo << std::endl;
        return;
    }

    string linha;
    int num_vertices;

    // Lê o número de vértices
    if (getline(arquivo, linha)) {
        istringstream iss(linha);
        if (!(iss >> num_vertices)) {
            cerr << "Erro ao ler número de vértices." << endl;
            return;
        }

        this->DestroyGraph(); // limpa estrutura atual
        *this = Graph(num_vertices); // recria o grafo com novo número de vértices
    }

    // Lê as arestas
    while (getline(arquivo, linha)) {
        istringstream iss(linha);
        int v1, v2;
        char separador;

        if (iss >> v1 >> separador >> v2 && separador == ',') {
            this->AdicionaAresta(Aresta(v1, v2));
        } else {
            cerr << "Erro ao ler aresta: " << linha << endl;
        }
    }

    cout << "Grafo carregado com sucesso!" << endl;
}
