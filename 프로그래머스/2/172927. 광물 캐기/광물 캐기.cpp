#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int N = minerals.size();
    
    int tool = 0;
    for(int i = 0; i < 3; i++){
        tool += 5 * picks[i]; 
    }
    int M = min(N, tool); 
    
    int fatigue[3][3] = {
        {1, 1, 1}, 
        {5, 1, 1}, 
        {25, 5, 1}
    };
    
    unordered_map<string, int> mineral_map = { {"diamond", 0}, {"iron", 1}, {"stone", 2} };

    vector<pair<int, int>> groups;
    int sum = 0;
    for(int i = 0; i < M; i += 5) {
        int group_size = min(5, M - i);
        groups.push_back({i, group_size}); 
    }

    vector<pair<int, int>> group_difficulties;
    for(auto& group : groups) {
        int difficulty = 0;
        for(int i = group.first; i < group.first + group.second; i++) {
            difficulty += fatigue[2][mineral_map[minerals[i]]]; 
        }
        group_difficulties.push_back({difficulty, group.first});
    }
    sort(group_difficulties.begin(), group_difficulties.end(), greater<pair<int,int>>());

    for(auto& group_info : group_difficulties) {
        int group_start = group_info.second;
        int group_size = min(5, M - group_start); 

        int pick_type = -1;
        if(picks[0] > 0) {
            pick_type = 0; 
            picks[0]--;
        } else if(picks[1] > 0) {
            pick_type = 1; 
            picks[1]--;
        } else if(picks[2] > 0) {
            pick_type = 2; 
            picks[2]--;
        }

        for(int i = group_start; i < group_start + group_size; i++) {
            string mineral = minerals[i];
            answer += fatigue[pick_type][mineral_map[mineral]];
        }
    }

    return answer;
}