#include <iostream>
using namespace std;


long long int solve(int N) {

    long long int arr[101] = { 0,1,1,1,2,2,3,4,5, };

    for (int i = 9; i <= N; i++) {
        arr[i] = arr[i - 5] + arr[i - 1];
    }

    return arr[N];
    
}

int main() {    
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        cout << solve(N) << '\n';
    }
}