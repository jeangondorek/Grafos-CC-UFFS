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

#include "Grafo.h"
#include "Aresta.h"
#include <iostream>

#include <vector>

using namespace std;

int main()  {
    try {
        int vertices = 0;
        int arestas = 0;
        string ataca = "A";
        int v1, v2;

        cin >> vertices >> arestas;

        Grafo grafo(vertices);

        for (int i = 0; i < arestas; i++) {
            cin >> v1 >> v2 >> ataca;
            if (ataca == "A") {
                Aresta aresta = Aresta(v1, v2, true);
                grafo.AdicionaAresta(aresta);
            }
        }

        std::vector<int> divisao1, divisao2, divisao21, divisao22;
        std::vector<bool> removidos(grafo.NumeroVertices(), false);
        std::vector<bool> removidos2(grafo.NumeroVertices(), false);

        if (grafo.Bipartido1(divisao1, divisao2, removidos, 0)) {
            cout << "\nSIM" << endl;
        } else {
            cout << "NAO" << endl;
        }

        if (grafo.Bipartido2(divisao21, divisao22, removidos2)) {
            cout << "SIM" << endl;
        } else {
            cout << "NAO" << endl;
        }
    
    } catch (const exception &e)  {
        cerr << "Execption: " << e.what() << endl;
    
    }

    return 0;

}