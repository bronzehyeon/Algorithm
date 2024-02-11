#include <iostream>
using namespace std;

long int fibo(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibo (n - 2) + fibo(n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long int N;
    cin >> N;

    cout << fibo(N);
    
}