#include <iostream>
#include <fstream>
#include "algoritmos.h"
#include "benchmark.h"
#include "analise.h"


void salvarCSV(const std::string& nome, const std::vector<std::pair<int,double>>& dados) {
    std::ofstream arquivo(nome);

    arquivo << "n,tempo\n";
    for (auto& p : dados) {
        arquivo << p.first << "," << p.second << "\n";
    }

    arquivo.close();
}


int main() {
std::cout << "=== ANALISE DE COMPLEXIDADE ===\n\n";


// ==========================
// Testando Insertion Sort
// ==========================
std::cout << "Testando Insertion Sort...\n";

auto dadosInsertion = rodarBenchmark(insertionSort);

salvarCSV("insertion.csv", dadosInsertion);

std::string resultadoInsertion = encontrarMelhorFuncao(dadosInsertion);

std::cout << "Complexidade estimada: " << resultadoInsertion << "\n\n";


// ==========================
// Testando Merge Sort
// ==========================
std::cout << "Testando Merge Sort...\n";

auto dadosMerge = rodarBenchmark(mergeSort);

salvarCSV("merge.csv", dadosMerge);

std::string resultadoMerge = encontrarMelhorFuncao(dadosMerge);

std::cout << "Complexidade estimada: " << resultadoMerge << "\n\n";


std::cout << "=== FIM ===\n";

return 0;

}
