#include "algoritmos.h"
#include <algorithm>

// =====================
// Insertion Sort O(n²)
// =====================
void insertionSort(std::vector<int>& v) {
for (int i = 1; i < v.size(); i++) {
int chave = v[i];
int j = i - 1;


    while (j >= 0 && v[j] > chave) {
        v[j + 1] = v[j];
        j--;
    }
    v[j + 1] = chave;
}


}

// =====================
// Merge Sort O(n log n)
// =====================
void merge(std::vector<int>& v, int inicio, int meio, int fim) {
std::vector<int> temp;
int i = inicio, j = meio + 1;


while (i <= meio && j <= fim) {
    if (v[i] < v[j]) temp.push_back(v[i++]);
    else temp.push_back(v[j++]);
}

while (i <= meio) temp.push_back(v[i++]);
while (j <= fim) temp.push_back(v[j++]);

for (int k = 0; k < temp.size(); k++) {
    v[inicio + k] = temp[k];
}

}

void mergeSortRec(std::vector<int>& v, int inicio, int fim) {
if (inicio >= fim) return;


int meio = (inicio + fim) / 2;
mergeSortRec(v, inicio, meio);
mergeSortRec(v, meio + 1, fim);
merge(v, inicio, meio, fim);

}

void mergeSort(std::vector<int>& v) {
mergeSortRec(v, 0, v.size() - 1);
}

// =====================
// Busca Linear O(n)
// =====================
int buscaLinear(const std::vector<int>& v, int alvo) {
for (int i = 0; i < v.size(); i++) {
if (v[i] == alvo) return i;
}
return -1;
}

// =====================
// Busca Binária O(log n)
// =====================
int buscaBinaria(const std::vector<int>& v, int alvo) {
int inicio = 0;
int fim = v.size() - 1;



while (inicio <= fim) {
    int meio = (inicio + fim) / 2;

    if (v[meio] == alvo) return meio;
    else if (v[meio] < alvo) inicio = meio + 1;
    else fim = meio - 1;
}

return -1;

}
