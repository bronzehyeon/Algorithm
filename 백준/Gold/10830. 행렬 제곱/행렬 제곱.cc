#include <iostream>
using namespace std;

long long int arr[5][5];
long long int answer[5][5];
long long int tmp[5][5];

void matrixMul(long long int A[5][5],long long int B[5][5], long long int N) {
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < N; k++) {
                tmp[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++)
            A[i][j] = tmp[i][j] % 1000;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int N, B;
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
        answer[i][i] = 1;
    }

    while (B > 0) {
        if (B % 2 == 1) {
            matrixMul(answer, arr, N);
        }
        matrixMul(arr, arr, N);
        B /= 2;
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << answer[i][j] << " ";
        }
        cout << '\n';
    }
}