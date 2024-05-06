#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> graph[1001];
bool visit[1001];

int answer = 0;

void dfs(int src, int dest, int distance) {

    if(src == dest) {
        answer = distance;
        return;
    }

    for(int i = 0; i < graph[src].size(); i++) {
        int n_node = graph[src][i].first;
        int n_dist = graph[src][i].second;

        if(visit[n_node] == false) {
            visit[n_node] = true;
            dfs(n_node, dest, (distance + n_dist));
            visit[n_node] = false;
        }
    }
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

        visit[src] = true;
        dfs(src, dest, 0);
        visit[src] = false;

        cout << answer << '\n';

    }
    

    return 0;

}

