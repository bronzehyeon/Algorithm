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

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        if (A >= 2)
            cout << v[B - 1] - v[A - 2] << '\n';
        else
            cout << v[B - 1] << '\n';
    }


}