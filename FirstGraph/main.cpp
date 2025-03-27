#include "FirstGraph.h"
#include "Aresta.h"
#include <iostream>

using namespace std;

int main()  {
    try {
        int expression = 0;
        int vertices;
        int v1, v2;

        FirstGraph grafo(vertices);

        while (expression != 10) {

            cout << endl;
            cout << "Escolha o que fazer: " << endl;
            cout << "0 - Criar grafo" << endl;
            cout << "1 - Adicionar aresta" << endl;
            cout << "2 - Remover aresta" << endl;
            cout << "3 - Verificar se existe aresta" << endl;
            cout << "4 - Verificar numero de vertices" << endl;
            cout << "5 - Verificar numero de arestas" << endl;
            cout << "6 - Imprimir grafo" << endl;
            cout << "7 - Destruir grafo" << endl;
            cout << "8 - Verficia passeio" << endl;
            cout << "9 - Verifica caminho" << endl;
            cout << "10 - Sair" << endl;
            cin >> expression; 
        
            switch (expression) {
                case 0: {
                    grafo.DestroyGraph();
                    cout << "Crie o grafo digitando o número de vértices: " << endl;
                    cin >> vertices; 
                    grafo = FirstGraph(vertices); 
                    break;
                }
                case 1: {
                    cout << "Digite os vertices da aresta: ";
                    cin >> v1 >> v2;
                    Aresta aresta(v1, v2);
                    grafo.AdicionaAresta(aresta);
                    break;
                }
                case 2: {
                    cout << "Digite os vertices da aresta: ";
                    cin >> v1 >> v2;
                    Aresta aresta2(v1, v2);
                    grafo.RemoveAresta(aresta2);
                    break;
                }
                case 3: {
                    cout << "Digite os vertices da aresta: ";
                    cin >> v1 >> v2;
                    Aresta aresta3(v1, v2);
                    cout << "Existe aresta entre " << aresta3.v1 << " e " << aresta3.v2 << "? " << (grafo.ExisteAresta(aresta3) ? "true" : "false") << endl;
                    break;
                }
                case 4:  {
                    cout << "Grafo criado com " << grafo.NumeroVertices() << " vertices." << endl;
                    break;
                }
                case 5: {
                    cout << "Grafo criado com " << grafo.NumeroArestas() << " arestas." << endl;
                    break;
                }
                case 6: {
                    cout << endl;
                    grafo.PrintGraph();
                    break;
                }
                case 7: {
                    grafo.DestroyGraph();
                    break;
                }
                case 8: {
                    grafo.ExistePasseio();
                    break;
                }
                case 9: {
                    grafo.ExisteCaminho();
                    break;
                }
                case 10:
                    break;
                default:
                    break;
                }
        }
    
    } catch (const exception &e)  {
        cerr << "Execption: " << e.what() << endl;
    
    }

    return 0;

}