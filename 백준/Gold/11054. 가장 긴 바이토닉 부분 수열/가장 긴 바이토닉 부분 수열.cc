#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int *arr = new int[N];
    int maxLen = 2;
    int *biggerThanMe = new int[N];
    int *smallerThanMe = new int[N];


    

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    smallerThanMe[0] = 1;
    biggerThanMe[N - 1] = 1;

    for (int i = 1; i < N; i++) {
        int max = 0;
        for (int k = i - 1; k >= 0; k--) {
            if (arr[k] < arr[i]) 
                if (max < smallerThanMe[k]) 
                    max = smallerThanMe[k];
        }
        smallerThanMe[i] = max + 1;
    }
    

    for (int i = N - 2; i >= 0; i--) {
        int max = 0;
        for (int k = i + 1; k < N; k++) {
            if (arr[k] < arr[i])
                if (max < biggerThanMe[k])
                    max = biggerThanMe[k];
        }
        biggerThanMe[i] = max + 1;
        if (biggerThanMe[i] + smallerThanMe[i] > maxLen)
            maxLen = biggerThanMe[i] + smallerThanMe[i];
    }

    cout << maxLen - 1;

}