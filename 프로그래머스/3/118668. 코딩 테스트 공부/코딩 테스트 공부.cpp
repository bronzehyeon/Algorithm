#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    int max_alp = 0;
    int max_cop = 0;

    for(int i = 0; i < problems.size(); i++){
        int alp_req = problems[i][0];
        int cop_req = problems[i][1];
        
        if(max_alp < alp_req){
            max_alp = alp_req;
        }
        
        if(max_cop < cop_req){
            max_cop = cop_req;
        }
    }
    
    
    vector<vector<int>> costs(max_alp + 1, vector<int>(max_cop + 1, 2100000000));
    
    alp = min(max_alp, alp);
    cop = min(max_cop, cop);
    costs[alp][cop] = 0;

    for(int a = alp; a <= max_alp; a++){
        for(int c = cop; c <= max_cop; c++){
            if(a + 1 <= max_alp){
                costs[a+1][c] = min(costs[a+1][c], costs[a][c] + 1);
            }
            if(c + 1 <= max_cop){
                costs[a][c+1] = min(costs[a][c+1], costs[a][c] + 1);
            }
            
            for(int i = 0; i < problems.size(); i++){
                int alp_req = problems[i][0];
                int cop_req = problems[i][1];
                int alp_rwd = problems[i][2];
                int cop_rwd = problems[i][3];
                int cost = problems[i][4];

                if(alp_req > a || cop_req > c){
                    continue;
                }
                int next_alp = a + alp_rwd;
                int next_cop = c + cop_rwd;

                int na = min(next_alp, max_alp);
                int nc = min(next_cop, max_cop);
                
                costs[na][nc] = min(costs[na][nc], costs[a][c] + cost);
            }
        }
    }
    
    answer = costs[max_alp][max_cop];
    
    return answer;
}