#include <iostream>
using namespace std;

long long int euclid(long long int a, long long int b) {
    if (b != 0)
        return euclid(b, a % b);
    else
        return a;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int A, B;
    cin >> A >> B;
    long long int gcd;
    if (A > B)
        gcd = euclid(A, B);
    else
        gcd = euclid(B, A);
    cout << A * B / gcd << '\n';


    return 0;
}