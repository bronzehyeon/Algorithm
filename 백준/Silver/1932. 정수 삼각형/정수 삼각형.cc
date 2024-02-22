#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;

    int arr[500][500];

    int lastIdx = 0;

    
    cin >> arr[0][0];

    for (int i = 1; i < T; i++) {
        for (int j = 0; j <= i; j++) {
            int k;
            cin >> k;

            if (j > 0)
                arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - 1]) + k;
            else
                arr[i][j] = arr[i - 1][j] + k;
            
        }
    }

    int answer = 0;

    for (int i = 0; i < T; i++) {
        if (answer < arr[T - 1][i])
            answer = arr[T - 1][i];
    }

    cout << answer;

}