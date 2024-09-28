#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> v;
int answer = 0;

void sol(int n, int idx){
    answer += n;
    
    for(int i = idx + 1; i < v.size(); i++){
        sol(v[i] * n, i);
    }
}

int solution(vector<vector<string>> cl) {
    
    int N = cl.size();
    
    unordered_map<string, int> m;
    
    for(int i = 0; i < N; i++){
        m[cl[i][1]]++;
    }

    unordered_map<string, int>::iterator iter = m.begin();
    while(iter != m.end()){
        v.push_back(iter->second);
        iter++;
    }
    
    for(int i = 0; i < v.size(); i++){
        sol(v[i], i);
    }
    
    return answer;
}