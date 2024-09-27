#include <string>
#include <vector>
#include <queue>

using namespace std;

int diff(string s1, string s2){
    int cnt = 0;
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] != s2[i]){
            cnt++;
        }
    }
    return cnt;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    int n = words.size();
    
    for(int i = 0; i < n; i++){
        if(words[i].compare(target) == 0){
            break;
        }
        if(i == words.size() - 1){
            return 0;
        }
    }
    
    queue<pair<int,string>> q;
    q.push({0,begin});
    vector<bool> visited(n, 0);
    
    while(!q.empty()){
        int cnt = q.front().first;
        string word = q.front().second;
        q.pop();
        
        if(word.compare(target) == 0){
            answer =cnt;
            break;
        }
        
        for(int i = 0; i < n; i++){
            if(!visited[i] && diff(words[i], word) == 1){
                q.push({cnt + 1, words[i]});
                visited[i] = true;
            }
        }
        
    }
    
    
    return answer;
}