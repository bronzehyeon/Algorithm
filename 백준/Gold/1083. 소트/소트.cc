#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    int arr[50];
    
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int S;
    cin >> S;

    int start = 0;
    
    while (S > 0) {
        if (start >= N) {
            break;
        }
        int maxIdx = start;
        int max = arr[start];
        //cout << "start : " << start << " S : " << S << " / ";
        for (int i = start; i <= S + start && i < N; i++) {
            if (arr[i] > max) {
                max = arr[i];
                maxIdx = i;
            }
        }
        //cout << "maxIdx : " << maxIdx << " ";
        for (int i = maxIdx; i > start; i--) {
            int tmp = arr[i - 1];
            arr[i - 1] = arr[i];
            arr[i] = tmp;
        }

        S -= (maxIdx - start);
        start++;
        //for (int i = 0; i < N; i++) {
        //    cout << arr[i] << " ";
        //}
        //cout << endl;
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    
}

