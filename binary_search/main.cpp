#include <iostream>
#include <vector>
using namespace std;

bool znajdz(vector<int> tab, int wartosc)
{
    bool znaleziono = false;
    for (int i = 0; i < tab.size() && !znaleziono; i++) {
        if (tab[i] == wartosc) {
            znaleziono = true;
        }
    }
    return znaleziono;
}

bool znajdz_bs(vector<int> tab, int wartosc)
{
    bool znaleziono = false;
    int idx_start = 0;
    int idx_koniec = tab.size() - 1;

    while (idx_start <= idx_koniec) {
        int idx_srodek = (idx_start + idx_koniec) / 2;
        if (tab[idx_srodek] == wartosc)
            return true;
        if (tab[idx_srodek] < wartosc) {
            idx_start = idx_srodek + 1;
        } else {
            idx_koniec = idx_srodek - 1;
        }
    }

    return false;
}
int main()
{
    vector<int> tab = {-9, 4, 6, 10, 50, 100, 350, 600, 1024};

    int wartosc = 350;
    bool znaleziono = false;
    if (znajdz_bs(tab, wartosc))
        cout << "znaleziono" << endl;

    return 0;
}
