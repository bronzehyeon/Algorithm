#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

vector<int> arr;

int bs(int s, int e, int target) {
    while (s < e) {
        //cout << s << " " << e << '\n';
        int m = (s + e) / 2;
        if (target > arr[m]) {
            s = m + 1;
        }
        else if (target < arr[m]){
            e = m;
        }
        else {
            return m;
        }
    }
    return e;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        v.push_back(tmp);
    }


    arr.push_back(v[0]);

    for (int i = 1; i < N; i++) {
        int n = v[i];
        if (n > arr[arr.size() - 1]) {
            arr.push_back(n);
        }
        int idx = bs(0, arr.size() - 1, n);
        arr[idx] = n;
    }

    cout << arr.size();
}