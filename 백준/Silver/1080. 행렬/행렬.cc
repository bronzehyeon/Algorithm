#include <iostream>

using namespace std;

int A[50][50];
int B[50][50];
int N, M;

void swap(int a, int b) {
    if (a + 3 > N || b + 3 > M) {
        return;
    }
    for (int i = a; i < a + 3; i++) {
        for (int j = b; j < b + 3; j++) {
            if (A[i][j] == 0) {
                A[i][j] = 1;
            }
            else {
                A[i][j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char tmp;
            cin >> tmp;
            A[i][j] = tmp - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char tmp;
            cin >> tmp;
            B[i][j] = tmp - '0';
        }
    }


    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != B[i][j]) {
                swap(i, j);
                count++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != B[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }
    

    cout << count;
    
}

