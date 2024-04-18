#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , r, c;
    cin >> n >> r >> c;

    int answer = 0;

    int N = pow(2,n);

    while(N / 2 != 0){
        N /= 2;
        answer += (r / N * 2 + c / N) * N * N;
        r -= r / N * N;
        c -= c / N * N;
    }

    cout << answer;

    return 0;
}