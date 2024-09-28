#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> op) {
    vector<int> answer;
    
    map<int, int> m;
    
    for(int i = 0; i < op.size(); i++){
        if(op[i][0] == 'I'){
            int num = 0;
            if(op[i][2] == '-'){
                for(int j = 3; j < op[i].length(); j++){
                    num = num * 10 - (op[i][j] - '0');
                }
            }
            else{
                for(int j = 2; j < op[i].length(); j++){
                    num = num * 10 + (op[i][j] - '0');
                }
            }
            m[num]++;
        }
        else{
            if(m.empty()){
                continue;
            }
            auto iter = m.begin();
            if(op[i][2] == '1'){
                iter = m.end();
                iter--;
            }
            if(iter->second == 1){
                m.erase(iter);
            }
            else{
                m[iter->first]--;
            }
        }
    }
    if(m.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        auto iter = m.end();
        iter--;
        answer.push_back(iter->first);
        iter = m.begin();
        answer.push_back(iter->first);
    }
    return answer;
}