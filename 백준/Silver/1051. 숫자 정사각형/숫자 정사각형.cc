#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int max = 0;
    int arr[50][50];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char tmp;
            cin >> tmp;
            arr[i][j] = tmp - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int base = arr[i][j];
            int size = max;
            while (i + size < N && j + size < M) {
                if (arr[i][j + size] == base && arr[i + size][j] == base && arr[i + size][j + size] == base) {
                    max = size;
                }
                size++;
            }
        }
    }

    cout << (max + 1) * (max + 1);

    return 0;
}