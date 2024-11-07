#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    int N = gems.size();
    
    int s = 0;
    int e = 0;
    
    unordered_map<string, int> um;
    
    for (int i = 0; i < N; i++) {
        um[gems[i]]++;
    }
    
    int gemCount = um.size();
    um.clear();
    
    vector<pair<int,int>> v;
    
    bool isComplete = false;
    int len;
    
    int x;
    int y;
    
    for (int i = 0; i < N; i++) {
        string gem = gems[i];
        e = i;
        if (um.find(gem) == um.end()) {
            um[gem]++;
        } else {
            um[gem]++;
            while (um[gems[s]] > 1 && s < e) {
                um[gems[s]]--;
                s++;
            }
            if (isComplete && e - s < len) {
                x = s;
                y = e;
                len = e - s;
            }
        }
        if (!isComplete && um.size() == gemCount) {
            isComplete = true;
            len = e - s;
            x = s;
            y = e;
        }
    }
    
    answer.push_back(x + 1);
    answer.push_back(y + 1);
    
    return answer;
}