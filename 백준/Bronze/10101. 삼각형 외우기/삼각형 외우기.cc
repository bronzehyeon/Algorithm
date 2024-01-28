#include <iostream>

using namespace std;

int main() {
    int A[3];
    cin >> A[0] >> A[1] >> A[2];
    if (A[0] + A[1] + A[2] != 180) cout << "Error";
    else if (A[0] == 60 && A[1] == 60) {
        cout << "Equilateral";
    }
    else if (A[0] == A[1] || A[1] == A[2] || A[0] == A[2]) {
        cout << "Isosceles";
    }
    else {
        cout << "Scalene";
    } 
}
