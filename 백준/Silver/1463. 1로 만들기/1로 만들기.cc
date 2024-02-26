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

    vector<int> v;

    v.push_back(0);
    v.push_back(0);

    for (int i = 2; i <= N; i++) {
        if (i % 6 == 0)
            v.push_back(min({v[i / 3], v[i / 2], v[i - 1]}) + 1);
        else if (i % 3 == 0)
            v.push_back(min({ v[i / 3], v[i - 1] }) + 1);
        else if (i % 2 == 0)
            v.push_back(min({ v[i / 2], v[i - 1] }) + 1);
        else
            v.push_back(v[i - 1] + 1);
    }

    cout << v[N];

}