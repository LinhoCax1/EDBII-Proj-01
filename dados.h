#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <functional>

// Tipo genérico de algoritmo de ordenação
typedef std::function<void(std::vector<int>&)> AlgoritmoOrdenacao;

// Mede o tempo médio de execução
double medirTempo(AlgoritmoOrdenacao alg, std::vector<int> v, int repeticoes);

// Executa o benchmark para vários tamanhos de entrada
std::vector<std::pair<int, double>> rodarBenchmark(AlgoritmoOrdenacao alg);

// Gera vetor aleatório
std::vector<int> gerarVetor(int n);

#endif
