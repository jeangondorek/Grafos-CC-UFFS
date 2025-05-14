/*
 * Trabalho 1 - Zoologico
 *
 * GEN254 - Grafos - 2025/1
 *
 * Nome:      Jean Gondorek
 * Matricula: 1921101059
 * 
 * Nome:      Gustavo Sutil
 * Matricula: 2111100025
 */

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
    int num_grupos, num_rels;

    // Lê o número de grupos e o número de relações
    if (getline(arquivo, linha)) {
        istringstream iss(linha);
        if (!(iss >> num_grupos >> num_rels)) {
            cerr << "Erro ao ler número de grupos e relações." << endl;
            return;
        }

        this->DestroyGraph(); // Limpa estrutura atual
        *this = Graph(num_grupos); // Recria o grafo com novo número de grupos
    }

    // Lê as relações entre os grupos
    while (getline(arquivo, linha)) {
        istringstream iss(linha);
        int v1, v2;
        char tipo_relacao;

        if (iss >> v1 >> v2 >> tipo_relacao) {
            // Se a relação for do tipo 'A' (atacam), adiciona aresta com peso/estado 'A'
            if (tipo_relacao == 'A') {
                this->AdicionaAresta(Aresta(v1, v2, true));  // true para 'A' (atacam)
            }
            // Se a relação for do tipo 'N' (não atacam), adiciona aresta com peso/estado 'N'
            else if (tipo_relacao == 'N') {
                this->AdicionaAresta(Aresta(v1, v2, false));  // false para 'N' (não atacam)
            }
            else {
                cerr << "Erro: Tipo de relação inválido (" << tipo_relacao << ")" << endl;
            }
        } else {
            cerr << "Erro ao ler relação: " << linha << endl;
        }
    }

    cout << "Grafo carregado com sucesso!" << endl;
}
