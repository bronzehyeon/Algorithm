#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int arr[1000001];
int ans[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> v(N);
    set<int> s;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v[i] = tmp;
        arr[tmp]++;
        s.insert(tmp);
    }

    int max = *max_element(v.begin(), v.end());

    

    for (auto iter = s.begin(); iter != s.end(); iter++) {
        int num = *iter;

        int k = 1;
        while (num * k <= max) {
            ans[num * k] += arr[num];
            k++;
        }

    }
    

    for (int i = 0; i < N; i++) {
        cout << ans[v[i]] - 1 << '\n';
    }


}
