#include <iostream>
#include <map>
using namespace std;

int euclid(int a, int b) {
    if (b != 0)
        return euclid(b, a % b);
    else
        return a;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int A, B;
        cin >> A >> B;
        int gcd;
        if (A > B)
            gcd = euclid(A, B);
        else
            gcd = euclid(B, A);

        cout << A * B / gcd << '\n';

    }
    return 0;
}