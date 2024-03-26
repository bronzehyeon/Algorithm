#include <iostream>
#include <map>
using namespace std;

map<long long, long long> m;

long long fibo(long long N) {
    if (N == 0) return 0;
    if (N == 1) return 1;
    if (N == 2) return 1;
    if (m.count(N) > 0) return m[N];

    if (N % 2 == 0) {
        long long t = N / 2;
        long long tmp1 = fibo(t - 1); long long tmp2 = fibo(t);
        m[N] = ((2 * tmp1 + tmp2) * tmp2) % 1000000007;
        return m[N];
    }
    long long t = (N + 1) / 2;
    long long temp1 = fibo(t); long long temp2 = fibo(t - 1);
    m[N] = (temp1 * temp1 + temp2 * temp2) % 1000000007;
    return m[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;

    
    cout << fibo(N);

}