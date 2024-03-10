#include <iostream>

using namespace std;

int arr[1024][1024], dp[1024][1024];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }
    int x1, y1, x2, y2;
    int ans;
    for (int i = 0; i < M; i++)
    {
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        ans = dp[x2 - 1][y2 - 1] - dp[x1 - 2][y2 - 1] - dp[x2 - 1][y1 - 2] + dp[x1 - 2][y1 - 2];
        cout << ans << '\n';
    }
    
}