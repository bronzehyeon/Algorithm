#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

bool customCompare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first)
        return a.first > b.first;
    else
        return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int N = genres.size();
    set<int> s;
    int idx = 0;
    vector<pair<int,int>> v[100];
    vector<int> p(100,0);
    unordered_map<string, int> m;
    for(int i = 0; i < N; i++){
        if(m.count(genres[i]) == 0){
            m[genres[i]] = idx;
            v[idx].push_back({plays[i], i});
            p[idx] += plays[i];
            idx++;
        }
        else{
            int genNum = m[genres[i]];
            v[genNum].push_back({plays[i], i});
            p[genNum] += plays[i];
        }
    }
    vector<pair<int,int>> rank;
    for(int i = 0; i < idx; i++){
        rank.push_back({p[i],i});
    }
    sort(rank.begin(), rank.end());
    
    for(int i = idx -1;i>=0;i--){
        int genNum = rank[i].second;
        sort(v[genNum].begin(), v[genNum].end(), customCompare);
        for(int j = 0; j < 2 && j < v[genNum].size(); j++){
            answer.push_back(v[genNum][j].second);
        }
    }
    
    return answer;
}