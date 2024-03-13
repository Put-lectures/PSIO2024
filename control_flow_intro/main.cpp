#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <string>
using namespace std;

int main()
{
    // char znak;
    // cout << "czy chcesz kontynuowac (t/n)?";
    // cin >> znak;
    // if (znak == 't' || znak == 'T') {
    //     cout << "kontynuacja";
    // }
    // else
    //     cout << "do widzenia";

    // for (int i = 0; i < 10; i++) {
    //     cout << i;
    // }
    set<string> slowa;
    fstream plik("/home/piotr/Downloads/gpl-3.0.txt", ios::in);
    if (plik.is_open()) {
        string slowo;
        while (!plik.eof()) {
            plik >> slowo;
            slowa.emplace(slowo);
        }
    }

    for (auto &el : slowa) {
        cout << el << endl;
    }
    // for (int i = 0; i < slowa.size(); i++) {
    //     cout << slowa[i] << endl;
    // }
    char znak;
    do {
        cout << "czy chcesz kontynuowac (t/n)?";
        cin >> znak;
        if (znak == 't' || znak == 'T') {
            cout << "kontynuacja";
        } else
            cout << "do widzenia";
    } while (znak != 't' && znak != 'T' && znak != 'n' && znak != 'N');

    // !(znak == 't' || znak == 'T' || znak == 'n' || znak == 'N')
    return 0;
}
