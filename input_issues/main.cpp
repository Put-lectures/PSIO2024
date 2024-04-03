#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a;
    vector<int> tab;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        tab.emplace_back(a);
        if (!cin.good()) {
            cout << "ledne dane";
            cin.sync();
            // cin.ignore(10, '\n');
            // cin.sync();
        }
    }
    for (auto &el : tab)
        cout << el << endl;
    return 0;
}
