#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> tab = {1, -6, 6, 7, 10, -100, 50, 3};
    int rozmiar = tab.size();
    bool przestawiono = false;
    do {
        rozmiar--;
        przestawiono = false;
        for (int i = 0; i < rozmiar; i++) {
            if (tab[i] > tab[i + 1]) {
                int tmp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tmp;
                przestawiono = true;
            }
        }
    } while (przestawiono);

    for (auto &el : tab) {
        cout << el << endl;
    }
    return 0;
}
