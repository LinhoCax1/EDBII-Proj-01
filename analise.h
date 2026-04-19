#ifndef ANALISE_H
#define ANALISE_H

#include <vector>
#include <string>

// Calcula o erro de ajuste para uma função f(n)
double calcularErro(
const std::vector<std::pair<int, double>>& dados,
double (*f)(int)
);

// Encontra qual função melhor se ajusta
std::string encontrarMelhorFuncao(
const std::vector<std::pair<int, double>>& dados
);

#endif
