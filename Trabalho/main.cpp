#include "Graph.h"
#include "Aresta.h"
#include <iostream>

#include <vector>

using namespace std;

int main()  {
    try {
        int expression = -1;
        int vertices = 0;
        int v1, v2;

        Graph grafo(vertices);

        while (expression != 0) {

            cout << endl;
            cout << "Escolha o que fazer: " << endl;
            cout << "1 - Criar grafo" << endl;
            cout << "2 - Adicionar aresta" << endl;
            cout << "3 - Remover aresta" << endl;
            cout << "4 - Verificar se existe aresta" << endl;
            //cout << "5 - Verificar numero de vertices" << endl;
            cout << "6 - Verificar numero de arestas" << endl;
            //cout << "7 - Imprimir grafo" << endl;
            //cout << "8 - Destruir grafo" << endl;
            //cout << "9 - Verficia passeio" << endl;
            //cout << "10 - Verifica caminho" << endl;
            cout << "11 - Carrega grafo do arquivo (arquivo: grafo.txt)" << endl;
            cout << "12 - Executa eh_bipartido_1 e eh_bipartido_2" << endl;
            cout << "0 - Sair" << endl;
            cin >> expression; 
        
            switch (expression) {
                case 1: {
                    grafo.DestroyGraph();
                    cout << "Crie o grafo digitando o número de vértices: " << endl;
                    cin >> vertices; 
                    grafo = Graph(vertices); 
                    break;
                }
                case 2: {
                    cout << "Digite os vertices da aresta: ";
                    cin >> v1 >> v2;
                    grafo.AdicionaAresta(Aresta(v1, v2));
                    break;
                }
                case 3: {
                    cout << "Digite os vertices da aresta: ";
                    cin >> v1 >> v2;
                    grafo.RemoveAresta(Aresta(v1, v2));
                    break;
                }
                case 4: {
                    cout << "Digite os vertices da aresta: ";
                    cin >> v1 >> v2;
                    Aresta aresta(v1, v2);
                    cout << "Existe aresta entre " << aresta.v1 << " e " << aresta.v2 << "? " << (grafo.ExisteAresta(aresta) ? "true" : "false") << endl;
                    break;
                }
                case 5:  {
                    cout << "Grafo criado com " << grafo.NumeroVertices() << " vertices." << endl;
                    break;
                }
                case 6: {
                    cout << "Grafo criado com " << grafo.NumeroArestas() << " arestas." << endl;
                    break;
                }
                case 7: {
                    cout << endl;
                    grafo.PrintGraph();
                    break;
                }
                case 8: {
                    grafo.DestroyGraph();
                    break;
                }
                case 9: {
                    grafo.ExistePasseio();
                    break;
                }
                case 10: {
                    std::vector<int> marcado_(grafo.NumeroVertices(), 0);
                    int v1, v2;
                    int identacao = 0;
                    cout << "Digite 2 elementos para validar caminho" << endl;
                    cin >> v1 >> v2;
                    bool existeCamino = grafo.ExisteCaminho(v1, v2, marcado_, grafo.NumeroVertices(), identacao);
                    if (existeCamino) {
                        cout << "Caminho existe entre " << v1 << " e " << v2 << endl;
                    } else {
                        cout << "Caminho não existe entre " << v1 << " e " << v2 << endl;
                    }
                    break;
                }   
                case 11: {              
                    grafo = Graph(10);
                    grafo.CarregarGrafoDoArquivo("grafo.txt");
                    break;
                }   
                case 12: {              
                    if (grafo.Bipartido1()) {
                        cout << "\nSIM" << endl;
                    } else {
                        cout << "NAO" << endl;
                    }
                    if (grafo.Bipartido2()) {
                        cout << "SIM" << endl;
                    } else {
                        cout << "NAO" << endl;
                    }
                    break;
                } 
                case 0:
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