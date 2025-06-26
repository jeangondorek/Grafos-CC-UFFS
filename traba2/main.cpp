/*
* Trabalho 2 - Coloracao
*
* GEN254 - Grafos - 2025/1
*
* Nome:      JEAN
* Matricula: 1921101059
* Nome:      GUSTAVO ALBRTON
* Matricula: XXXX
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
        int v1, v2;
        string exec = "P";

        cin >> vertices >> arestas;

        Grafo grafo(vertices);

        for (int i = 0; i < arestas; i++) {
            cin >> v1 >> v2;
            Aresta aresta = Aresta(v1, v2);
            grafo.AdicionaAresta(aresta);
        }

        cin >> exec;

        if (exec == "P"){
            grafo.constroi_coloracao_1();
        }
        
//        if (exec == "A"){
  //          grafo.constroi_coloracao_1();
    //        grafo.constroi_coloracao_2();
      //  }
    
    } catch (const exception &e)  {
        cerr << "Execption: " << e.what() << endl;
    
    }

    return 0;

}