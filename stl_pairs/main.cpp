#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Dane
{
    string imie_nazwisko;
    int telefon;
};

int main()
{
    vector<Dane> dane = {{"Piotr Kaczmarek", 40},
                         {"Jan Nowak", 20},
                         {"Jan Nowak", 30},
                         {"John Smith", 50}};
    sort(dane.begin(), dane.end(), [](const Dane &el1, const Dane &el2) {
        if (el1.imie_nazwisko == el2.imie_nazwisko) {
            return el1.telefon < el2.telefon;
        } else {
            el1.imie_nazwisko < el2.imie_nazwisko;
        }
    });
    for (auto &el : dane) {
        cout << el.imie_nazwisko << ", " << el.telefon << endl;
    }

    // vector<pair<string, int>> dane_pair = {{"Piotr Kaczmarek", 40},
    //                                        {"Jan Nowak", 20},
    //                                        {"John Smith", 50}};
    // sort(dane_pair.begin(), dane_pair.end());
    // for (auto &el : dane_pair) {
    //     cout << el.first << ", " << el.second << endl;
    // }

    return 0;
}
