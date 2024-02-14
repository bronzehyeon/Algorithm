#include <iostream>
using namespace std;

int arr[9];
bool visited[9];

void dfs(int count, int N, int M)
{
    if (count == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[count] = i;
            dfs(count + 1, N, M);
            visited[i] = false;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    dfs(0, N, M);
}