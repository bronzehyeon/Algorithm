#include <iostream>
#include <vector>
using namespace std;


int solve(int N) {
    vector<long long int> v;

    v.push_back(1);
    v.push_back(1);

    for (int i = 2; i <= N; i++) {
        v.push_back((v[i - 1] + v[i - 2]) % 15746);
    }

    return
        v[N];

}

int main() {    
    
    int N;
    cin >> N;

    cout << solve(N) << '\n';
    
}