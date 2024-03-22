#include <iostream>
using namespace std;

long long int power(long long int A, long long int B, long long int C) {
    if (B == 0)
        return 1;
    long long int temp = power(A, B / 2, C);
    long long int result = (temp * temp) % C;
    if (B % 2 == 0)
        return result;
    else
        return (result * A) % C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int A, B, C;
    cin >> A >> B >> C;

    cout << power(A, B, C);

}
