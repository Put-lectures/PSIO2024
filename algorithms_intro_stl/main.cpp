#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

bool wiekszy_0(const float &arg)
{
    return arg > 0;
}

class Wiekszy_niz
{
    float prog_;

public:
    Wiekszy_niz(float prog = 0)
        : prog_(prog)
    {}
    void set_prog(float prog) { prog_ = prog; }

    bool operator()(const float &arg) { return arg > prog_; }
};

int main()
{
    vector<float> tab = {10, -5, 3, 6, 1, 0, 3};
    float prog = 3.5;
    // cout << count_if(tab.begin(), tab.end(), wiekszy_0) << endl;//predykat jako funkcja

    // cout << count_if(tab.begin(), tab.end(), [prog](const float &arg) { return arg > prog; })
    //      << endl; //predykat jako wyrazenie lambda

    Wiekszy_niz predykat(3);
    predykat.set_prog(1);
    cout << count_if(tab.begin(), tab.end(), predykat) << endl; //predykat jako predicate object

    sort(tab.begin(), tab.end(), [](const float &el1, const float &el2) {
        return fabs(el1) > fabs(el2);
    });

    for (auto &el : tab) {
        cout << el << endl;
    }
    return 0;
}
