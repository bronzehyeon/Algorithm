#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    vector<int> copy(v);
    sort(copy.begin(), copy.end());

    copy.erase(unique(copy.begin(), copy.end()), copy.end());

    for (int i = 0; i < N; i++) {
        vector<int>::iterator iter = lower_bound(copy.begin(), copy.end(), v[i]);
        cout << iter - copy.begin() << " ";
    }
    
}