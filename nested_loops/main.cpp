#include <iostream>

using namespace std;

int main()
{
    int N = 10, M = 10;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j == 0 || j == M - 1 || i == 0 || i == N - 1)
                cout << "*";
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    int r = 5;
    for (int i = -r; i < r + 1; i++) {
        for (int j = -r; j < r + 1; j++) {
            if (i * i + j * j <= r * r)
                cout << "*";
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
