#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<string>> tickets_global;
vector<bool> used;
vector<string> answer;
bool found = false;

void dfs(string cur, vector<string>& path, int cnt) {
    if (cnt == N) {
        path.push_back(cur);
        answer = path;
        found = true;
        return;
    }
    
    for (int i = 0; i < N; ++i) {
        if (!used[i] && tickets_global[i][0] == cur) {
            used[i] = true;
            path.push_back(cur);
            dfs(tickets_global[i][1], path, cnt + 1);
            if (found) return;
            path.pop_back();
            used[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    N = tickets.size();
    tickets_global = tickets;
    sort(tickets_global.begin(), tickets_global.end());
    used.resize(N, false);
    vector<string> path;
    dfs("ICN", path, 0);
    return answer;
}
