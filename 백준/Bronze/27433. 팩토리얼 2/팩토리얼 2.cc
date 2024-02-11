#include <iostream>
using namespace std;

long int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long int N;
    cin >> N;

    cout << factorial(N);
    
}