#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int u, b;
int answer = 0;
vector<vector<int>> possible_matches;
unordered_set<int> unique_combinations;

void dfs(int cnt, int bitmask) {
    if (cnt == b) {
        if (unique_combinations.find(bitmask) == unique_combinations.end()) {
            unique_combinations.insert(bitmask);
            answer++;
        }
        return;
    }

    for (int uid : possible_matches[cnt]) {
        if ((bitmask & (1 << uid)) == 0) { 
            dfs(cnt + 1, bitmask | (1 << uid));
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    u = user_id.size();
    b = banned_id.size();
    
    possible_matches.resize(b);

    for (int i = 0; i < b; i++) {
        string bid = banned_id[i];
        for (int j = 0; j < u; j++) {
            string uid = user_id[j];
            if (uid.length() != bid.length()) continue;

            bool isMatch = true;
            for (int k = 0; k < bid.length(); k++) {
                if (bid[k] != '*' && bid[k] != uid[k]) {
                    isMatch = false;
                    break;
                }
            }

            if (isMatch) {
                possible_matches[i].push_back(j);
            }
        }
    }

    dfs(0, 0);
    
    return answer;
}