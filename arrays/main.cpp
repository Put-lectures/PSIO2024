#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<vector<float>> tab(6, vector<float>(6, 5));

    // tab[0][0] = 5;
    // for (int i = 0; i < 10000; i++) {
    //     float pTab[10000000];
    //     pTab[0] = 0;

    //     // delete[] pTab;
    // } i

    vector<int> tab(100);
    for (int i = 0; i < 100; i++) {
        // tab.emplace_back(i);
        tab[i] = i;
        cout << i << " - " << tab.capacity() << " - " << tab.size() << endl;
    }

    tab.emplace_back(5);
    cout << 100 << " - " << tab.capacity() << " - " << tab.size() << endl;
    return 0;
}
