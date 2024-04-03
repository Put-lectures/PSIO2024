#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    list<int> tab = {1, 3, 99, 0, 6, 6, -10, 6, 30, 0};

    for (auto itr = tab.begin(); itr != tab.end(); itr++) {
        if (*itr == 0) {
            itr = tab.emplace(itr, 99);
            itr++;
            // tab.emplace(itr, 99);
        }
    }

    for (auto itr = tab.begin(); itr != tab.end();) {
        if (*itr == 6) {
            itr = tab.erase(itr);
            // tab.emplace(itr, 99);
        } else {
            itr++;
        }
    }
    vector<int> tab_v(tab.begin(), tab.end());
    // tab.sort();

    sort(tab_v.begin(), tab_v.end());

    for (auto &el : tab_v) {
        cout << el << endl;
    }
    // cout << "liczba elementów == 0: " << count(tab.begin(), tab.end(), 0);
    // auto itr = tab.begin();

    // while (itr != tab.end()) {
    //     cout << *itr << endl;
    //     itr++;
    // }

    return 0;
}
