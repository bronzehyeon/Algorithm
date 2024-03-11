#include <iostream>
#include <algorithm>
using namespace std;

char board[2001][2001];

int black[2001][2001];//처음이 검은색일 경우 다시 칠해야 하는 칸
int white[2001][2001];//처음이 하얀색일 경우 다시 칠해야 하는 칸

int dp_b[2001][2001];//누적합
int dp_w[2001][2001];//누적합


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            dp_b[i][j] = 0;
            dp_w[i][j] = 0;
            if ((i + j) % 2 == 0) {
                if (board[i][j] != 'B')
                    black[i][j]++;
                else
                    white[i][j]++;
            }
            else {
                if (board[i][j] == 'B')
                    black[i][j]++;
                else
                    white[i][j]++;
            }
            dp_b[i][j] = dp_b[i][j - 1] + dp_b[i - 1][j] - dp_b[i - 1][j - 1] + black[i][j];
            dp_w[i][j] = dp_w[i][j - 1] + dp_w[i - 1][j] - dp_w[i - 1][j - 1] + white[i][j];
        }
    }

    
    int answer = N * N / 2;

    for (int i = K - 1; i < N; i++) {
        for (int j = K - 1; j < M; j++) {
            int tmp_b = dp_b[i][j] - dp_b[i][j - K] - dp_b[i - K][j] + dp_b[i - K][j - K];
            int tmp_w = dp_w[i][j] - dp_w[i][j - K] - dp_w[i - K][j] + dp_w[i - K][j - K];

            if (answer > min(tmp_b, tmp_w))
                answer = min(tmp_b, tmp_w);
        }
       
    }

    cout << answer;

}

