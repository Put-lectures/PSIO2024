#include <cmath>
#include <iostream>
using namespace std;
int silnia_rec(int N)
{
    // if (N == 0)
    //     return 1;
    cout << N << endl;
    return silnia_rec(N - 1) * N;
}
int silnia(int N = 5)
{
    int acc = 1;

    for (int i = 1; i < N; i++) {
        acc *= i;
    }

    return acc;
}

float pi(float prec)
{
    float pi = 0;
    int i = 1;
    float delta;
    do {
        delta = pow(-1, i - 1) / (2 * i - 1);
        pi += delta;
        i++;
    } while (fabs(delta) > prec);

    return 4 * pi;
}

int main()
{
    // int N = 10;
    // int acc = silnia(N);
    // cout << acc;
    // float prec = 0.00001;
    // float pi_val = pi(prec);

    // cout.precision(10);
    // cout << "pi:" << pi_val << endl;

    // float acc = 1;
    // float acc_prev = 1;
    // float N = 250;
    // for (float i = 1; i < N; i++) {
    //     acc *= i;
    //     cout << i << " - " << acc << " - " << acc / acc_prev << endl;
    //     acc_prev = acc;
    // }

    // float dt = 0.1;
    // cout.precision(16);
    // cout << dt << endl;
    // cout << 0.1 + 100000 - 100000 - 0.1 << endl;

    // if(fabs(val)< 0.0000001){

    // }
    // float acc = 0;
    // for (int i = 0; i < 100000; i++)
    //     acc += dt;

    // cout << acc;
    // cout << acc;

    // uint8_t a = 255;
    // cout << (int) a << endl;
    // a++;
    // cout << (int) a << endl;
    const int a = 0;
    auto func = [a](int x) { return x * a; };
    cout << func(2);
    cout << silnia_rec(5) << endl;
    return 0;
}
