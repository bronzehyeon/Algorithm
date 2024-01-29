#include <iostream>

using namespace std;

int main() {
    int arr[5];
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 4; j > i; j--) {
            if (arr[j - 1] > arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
    cout << sum/5 << '\n';
    cout << arr[2] << '\n';

    
}
