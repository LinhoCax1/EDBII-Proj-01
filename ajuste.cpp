#include "ajuste.h"
#include <cmath>
#include <limits>

// ==========================
// Funções assintóticas
// ==========================
double f_log(int n) {
return log2(n);
}

double f_n(int n) {
return n;
}

double f_nlogn(int n) {
return n * log2(n);
}

double f_n2(int n) {
return n * n;
}

double f_n3(int n) {
return (double)n * n * n;
}

// ==========================
// Cálculo de erro
// ==========================
double calcularErro(
const std::vector<std::pair<int, double>>& dados,
double (*f)(int)
) {
double soma_c = 0;


// calcula constante c média
for (auto& par : dados) {
    int n = par.first;
    double tempo = par.second;

    soma_c += tempo / f(n);
}

double c = soma_c / dados.size();

// calcula erro quadrático
double erro = 0;

for (auto& par : dados) {
    int n = par.first;
    double tempo = par.second;

    double estimado = c * f(n);
    erro += pow(tempo - estimado, 2);
}

return erro;


}

// ==========================
// Escolha da melhor função
// ==========================
std::string encontrarMelhorFuncao(
const std::vector<std::pair<int, double>>& dados
) {
double menorErro = std::numeric_limits<double>::max();
std::string melhor = "";


struct Funcao {
    std::string nome;
    double (*f)(int);
};

std::vector<Funcao> funcoes = {
    {"O(log n)", f_log},
    {"O(n)", f_n},
    {"O(n log n)", f_nlogn},
    {"O(n^2)", f_n2},
    {"O(n^3)", f_n3}
};

for (auto& func : funcoes) {
    double erro = calcularErro(dados, func.f);

    if (erro < menorErro) {
        menorErro = erro;
        melhor = func.nome;
    }
}

return melhor;

}
