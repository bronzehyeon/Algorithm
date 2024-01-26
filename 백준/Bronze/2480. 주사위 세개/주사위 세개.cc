#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A[3];
    cin >> A[0] >> A[1] >> A[2];
    sort(A, A + 3);

    if (A[0] == A[1] || A[1] == A[2]) {
        if (A[0] == A[2]) cout << 10000 + A[0] * 1000;
        else cout << 1000 + A[1] * 100;
    }
    else cout << A[2] * 100;
}