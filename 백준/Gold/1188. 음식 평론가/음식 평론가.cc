#include <iostream>

using namespace std;

int Euclidean(int a, int b)
{
    int r = a % b;
    if (r == 0) {
        return b;
    }
    return Euclidean(b, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    if (N % M == 0) {
        cout << 0;
    }
    else {
        cout<< M - Euclidean(N, M);
    }

}
