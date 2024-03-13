#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<double> values = {1, 4, 6, -9, 10};
    double min = values[0];
    for (auto el : values) {
        if (el < min) {
            min = el;
        }
    }
    cout << "minimalna wartos wynosi" << min;

    int n = 1235;
    bool czy_pierwsza = true;
    for (int i = 2; i < sqrt(n) && czy_pierwsza; i++) {
        if (n % i == 0)
            czy_pierwsza = false;
    }
    cout << czy_pierwsza;

    return 0;
}
