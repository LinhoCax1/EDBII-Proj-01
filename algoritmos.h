#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <vector>

// Ordenação
void insertionSort(std::vector<int>& v);
void mergeSort(std::vector<int>& v);

// Busca
int buscaLinear(const std::vector<int>& v, int alvo);
int buscaBinaria(const std::vector<int>& v, int alvo);

#endif
