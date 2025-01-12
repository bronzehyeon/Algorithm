#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);
    answer[0] = 0;
    answer[1] = 0;
    
    set<string> s;
    
    s.insert(words[0]);
    
    for (int i = 1; i < words.size(); i++) {
        if (words[i - 1][words[i - 1].length() - 1] != words[i][0] || s.find(words[i]) != s.end()) {
            answer[0] = i % n + 1 ;
            answer[1] = i / n + 1;
            break;
        }
        s.insert(words[i]);
    }
    

    return answer;
}