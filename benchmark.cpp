#include "benchmark.h"
#include <chrono>
#include <random>

// ==========================
// Gera vetor aleatório
// ==========================
std::vector<int> gerarVetor(int n) {
std::vector<int> v(n);


std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(0, 100000);

for (int i = 0; i < n; i++) {
    v[i] = dist(gen);
}

return v;


}

// ==========================
// Mede tempo médio
// ==========================
double medirTempo(AlgoritmoOrdenacao alg, std::vector<int> v, int repeticoes) {
double total = 0;


for (int i = 0; i < repeticoes; i++) {
    std::vector<int> copia = v; // evita modificar o original

    auto inicio = std::chrono::high_resolution_clock::now();

    alg(copia);

    auto fim = std::chrono::high_resolution_clock::now();

    double tempo = std::chrono::duration<double, std::milli>(fim - inicio).count();
    total += tempo;
}

return total / repeticoes;


}

// ==========================
// Executa benchmark
// ==========================
std::vector<std::pair<int, double>> rodarBenchmark(AlgoritmoOrdenacao alg) {
std::vector<std::pair<int, double>> dados;


int repeticoes = 10;

for (int n = 1000; n <= 20000; n += 1000) {
    std::vector<int> v = gerarVetor(n);

    double tempo = medirTempo(alg, v, repeticoes);

    dados.push_back({n, tempo});
}

return dados;


}
