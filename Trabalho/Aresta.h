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

#ifndef ARESTA_H
#define ARESTA_H

#include <vector>

class Aresta {
    public:
        const int v1;
        const int v2;
        const bool estado; // true para 'A' (atacam), false para 'N' (não atacam)
        Aresta (int v1, int v2, bool estado);
};

#endif
