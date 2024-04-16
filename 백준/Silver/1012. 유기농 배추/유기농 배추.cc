#include <iostream>

using namespace std;

int arr[51][51];

void dfs(int i, int j) {
    arr[i][j] = 0;
    if (arr[i][j + 1] == 1) {
        dfs(i, j + 1);
    }
    if (arr[i + 1][j] == 1) {
        dfs(i + 1, j);
    }
    if (j > 0 && arr[i][j - 1] == 1) {
        dfs(i, j - 1);
    }
    if (i > 0 && arr[i - 1][j] == 1) {
        dfs(i - 1, j);
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, M, K;
        cin >> N >> M >> K;
        int count = 0;


        for (int k = 0; k < K; k++) {
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
        }

        //for (int i = 0; i < N; i++) {
        //    for (int j = 0; j < M; j++) {
        //        cout << arr[i][j] << " ";
        //    }
        //    cout << endl;
        //}

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 1) {
                    dfs(i, j);
                    count++;
                }
            }
        }
        cout << count << '\n';
    }
 
}

