#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b != 0)
        return gcd(b, a % b);
    else
        return a;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int tree[100000];
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }
    
    int interval[100000];
    for (int i = 1; i < N; i++) {
        interval[i - 1] = tree[i] - tree[i - 1];
    }
    
    int tree_gcd = gcd(interval[0],interval[1]);

    for (int i = 2; i < N - 1; i++) {
        tree_gcd = gcd(tree_gcd, interval[i]);
    }

    int answer = 0;
    for (int i = 0; i < N - 1; i++) {
        answer += interval[i] / tree_gcd - 1;
    }

    cout << answer;
}