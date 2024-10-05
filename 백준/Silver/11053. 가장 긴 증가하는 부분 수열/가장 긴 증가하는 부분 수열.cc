#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[1000];
    int maxLen = 1;
    int check[1000];


    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    check[N - 1] = 1;

    for (int i = N - 2; i >= 0; i--) {
        int max = 0;
        for (int k = i + 1; k < N; k++) {
            if (arr[k] > arr[i])
                if (max < check[k])
                    max = check[k];
        }
        check[i] = max + 1;
        if (check[i] > maxLen)
            maxLen = check[i];
    }

    cout << maxLen;

}