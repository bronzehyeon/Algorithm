#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int A[3];
        cin >> A[0] >> A[1] >> A[2];
        sort(A, A + 3);
        if (A[2] == 0) break;
        if (A[0] + A[1] <= A[2]) cout << "Invalid" << '\n';
        else if ( A[0] == A[2]) {
            cout << "Equilateral" << '\n';
        }
        else if (A[0] == A[1] || A[1] == A[2]) {
            cout << "Isosceles" << '\n';
        }
        else {
            cout << "Scalene" << '\n';
        }
    } 
}
