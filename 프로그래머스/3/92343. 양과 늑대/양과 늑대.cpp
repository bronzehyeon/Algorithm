#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> graph[17];
int answer = 0;

bool visited[17][18][18];

vector<int> animal;

void dfs(int cur, int sheep, int wolf){
    if(answer < sheep){
        answer = sheep;
    }
    
    for(int i = 0; i < graph[cur].size();i++){
        int next = graph[cur][i];
        
        if(animal[next] == 1){
            if(wolf + 1 < sheep){
                if(!visited[next][sheep][wolf + 1]){
                    animal[next] = -1;
                    visited[next][sheep][wolf + 1] = true;
                    dfs(next,sheep,wolf + 1);
                    animal[next] = 1;
                    visited[next][sheep][wolf + 1] = false;
                }
            }
        }
        else if(animal[next] == 0){
            if(!visited[next][sheep + 1][wolf]){
                animal[next] = -1;
                visited[next][sheep + 1][wolf] = true;
                dfs(next, sheep + 1, wolf);
                animal[next] = 0;
                visited[next][sheep + 1][wolf] = false;
            }
        }
        else{
            if(!visited[next][sheep][wolf]){
                visited[next][sheep][wolf] = true;
                dfs(next, sheep, wolf);
                visited[next][sheep][wolf] = false;
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    animal = info;
    memset(visited,false,sizeof(visited));
    
    animal[0] = -1;
    dfs(0, 1, 0);
    
    return answer;
}