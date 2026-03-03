#include <iostream>
using namespace std;

int main()
{
    int n;
    long long int fatorial = 1;

    cout << "Digite um numero inteiro: ";
    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        fatorial = fatorial * i;
    }

    cout << "O fatorial de " << n << " e: " << fatorial << endl;

    return 0;
}