#include <iostream>
using namespace std;

int num[100000];
int sum[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;


    for (int n = 0; n < N; n++) {
        cin >> num[n];
        sum[n] = num[n];
    }

    int maxSum = num[0];


    for (int i = 1; i < N; i++) {
        if (sum[i] < sum[i - 1] + num[i])
            sum[i] = sum[i - 1] + num[i];
        if (sum[i] > maxSum)
            maxSum = sum[i];
    }

    cout << maxSum;

}