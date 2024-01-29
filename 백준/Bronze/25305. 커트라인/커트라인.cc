#include <iostream>

using namespace std;

int main() {
    int N, k;
    cin >> N >> k;
    int arr[1001];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > i; j--) {
            if (arr[j - 1] > arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
    cout << arr[N - k] << '\n';

    
}
