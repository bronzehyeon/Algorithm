#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int arr[10001] = {};

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp]++;
    }

    for (int i = 0; i < 10001; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i << '\n';
        }
    }

    return 0;
}