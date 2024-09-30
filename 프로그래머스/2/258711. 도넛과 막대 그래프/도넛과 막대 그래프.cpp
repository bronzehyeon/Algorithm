#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    
    int max_node = 0;
    for (int i = 0; i < edges.size(); i++) {
        max_node = max({max_node, edges[i][0], edges[i][1]});
    }
    
    vector<vector<int>> in(max_node + 1);
    vector<vector<int>> out(max_node + 1);

    
    for(int i = 0; i < edges.size();i++){
        int s = edges[i][0];
        int d = edges[i][1];
        
        in[d].push_back(s);
        out[s].push_back(d);
    }
    for(int i = 0; i <= 1000000; i++){
        if(out[i].size() == 0){
            continue;
        }
        if(in[i].size() == 0 && out[i].size() >= 2){
            answer[0] = i;
            break;
        }
    }
    
    for(int i = 0; i < out[answer[0]].size();i++){
        int x = out[answer[0]][i];
        int start = x;
        while(true){
            if(out[x].size() == 2){
                answer[3]++;
                break;
            }
            if(out[x].size() == 0){
                answer[2]++;
                break;
            }
            if(out[x][0] == start){
                answer[1]++;
                break;
            }
            x = out[x][0];
        }
    }
    
    return answer;
}