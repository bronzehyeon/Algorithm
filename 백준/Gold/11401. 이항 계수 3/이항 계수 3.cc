#include <iostream>
using namespace std;

int num = 1000000007;

long long power(long long N, long long K) {
    long long tmp = 1;

    while (K != 0) {
        if (K % 2 != 0) tmp = (tmp * N) % num;

        N = (N * N) % num;
        K /= 2;
    }

    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int N, K;
    cin >> N >> K;

    long long int numer = 1;
    long long int denomi = 1;
    
    for (int i = N; i > N - K; i--) {
        numer *= i;
        numer %= num;
    }
    for (int i = K; i > 0; i--) {
        denomi *= i;
        denomi %= num;
    }

    cout << (numer % num * power(denomi, num - 2) % num) % num;

    return 0;

}
