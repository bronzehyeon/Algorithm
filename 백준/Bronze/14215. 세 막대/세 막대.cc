#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A[3];
    cin >> A[0] >> A[1] >> A[2];
    sort(A, A + 3);
    while (A[0] + A[1] <= A[2]) A[2]--;
    cout << A[0] + A[1] + A[2];
}
