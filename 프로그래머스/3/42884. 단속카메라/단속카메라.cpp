#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end());
    for(int i = 0; i < routes.size();){
        int s = routes[i][0];
        int e = routes[i][1];
        int j = i+1;
        for(; j<routes.size();j++){
            if(routes[j][0] <= e){
                if(routes[j][1] < e){
                    e = routes[j][1];
                }
            }
            else{
                break;
            }
        }
        i = j;
        answer++;
    }
    
    return answer;
}