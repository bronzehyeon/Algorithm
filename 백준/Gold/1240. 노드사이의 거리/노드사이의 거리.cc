#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> graph[1001];
bool visit[1001];

int dfs(int src, int dest) {
    if (src == dest) {
        return 0;
    }

    visit[src] = true;
    for (int i = 0; i < graph[src].size(); i++) {
        int next = graph[src][i].first;
        int dist = graph[src][i].second;

        if (!visit[next]) {
            int result = dfs(next, dest);
            if (result != -1) {
                visit[src] = false;
                return dist + result;
            }
        }
    }
    visit[src] = false;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        int node1, node2, distance;
        cin >> node1 >> node2 >> distance;

        graph[node1].push_back(make_pair(node2, distance));
        graph[node2].push_back(make_pair(node1, distance));
    }

    for (int i = 0; i < N; i++) {
        visit[i] = false;
    }


    for (int i = 0; i < M; i++) {
        int src, dest;
        cin >> src >> dest;

        int answer = dfs(src, dest);

        cout << answer << '\n';
    }

    return 0;
}
