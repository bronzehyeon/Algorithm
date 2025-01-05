#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> m;
    
    for (int i = 0; i < tangerine.size(); i++) {
        m[tangerine[i]]++;
    }
    
    vector<int> v;
    
    auto iter = m.begin();
    while (iter != m.end()) {
        v.push_back(iter->second);
        iter++;
    }
    
    sort(v.begin(), v.end(), greater<>());
    
    int n = 0;
    int i = 0;
    while (n < k) {
        answer++;
        n += v[i];
        i++;
    }
    
    return answer;
}