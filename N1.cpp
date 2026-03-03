#include <iostream>
using namespace std;

int main()
{
    int n;

    do
    {
        cout << "Digite um numero inteiro positivo:" << endl;
        cin >> n;

        if (n < 0)
        {
            cout << "Numero invalido, por favor digite um numero positivo!" << endl;
        }

    } while (n < 0);

    for (int i = n; i >= 1; i--)
    {
        cout << i << endl;
    }
        

    return 0;
}