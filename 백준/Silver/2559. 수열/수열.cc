#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> v;

    int sum = 0;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        
        sum += tmp;
        v.push_back(sum);
    }
    int max = v[M - 1];

    for (int i = 0; i + M < N; i++) {
        if (v[i + M] - v[i] > max)
            max = v[i + M] - v[i];
    }
        
    

    cout << max;
}