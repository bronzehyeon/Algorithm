#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> v[3];
    v[0] = {1, 2, 3, 4, 5};
    v[1] = {2, 1, 2, 3, 2, 4, 2, 5};
    v[2] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int ans[3] = {0,0,0};
    for(int i = 0; i < answers.size(); i++){
        for(int j = 0; j<3;j++){
            if(answers[i] == v[j][i % v[j].size()]){
                ans[j]++;
            }
        }
    }
    int sol = max({ans[0],ans[1],ans[2]});
    for(int j = 0; j<3;j++){
        if(sol == ans[j]){
            answer.push_back(j + 1);
        }
    }
    return answer;
}