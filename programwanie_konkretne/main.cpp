#include <iostream>

int srednia(float *tab, int N)
{
    float suma = 0;
    for (int i = 0; i < N; i++) {
        suma += tab[i];
    }
    return suma / N;
}

int srednia(double *tab, int N)
{
    double suma = 0;
    for (int i = 0; i < N; i++) {
        suma += tab[i];
    }
    return suma / N;
}
using namespace std;

int main()
{
    // int tab[100];
    vector<float> tab(100);
    cout << srednia(tab, 100);
    return 0;
}
