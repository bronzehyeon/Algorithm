#include <iostream>
using namespace std;

int matrixA[100][100];
int matrixB[100][100];
int answer[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrixA[i][j];
        }
    }
    
    cin >> M >> K;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> matrixB[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) {
                answer[i][j] += matrixA[i][k] * matrixB[k][j];
            }
            cout << answer[i][j] << " ";
        }
        cout << '\n';
    }

    

}