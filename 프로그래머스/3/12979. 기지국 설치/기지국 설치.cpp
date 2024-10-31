#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int idx = 0;
    
    for (int i = 1; i <= n; i++) {
        if (idx >= stations.size()){
            i += w * 2;
            answer++;
        }
        else if(i + w < stations[idx]){
            answer++;
            i += w * 2;
        }
        else {
            i = stations[idx] + w;
            idx++;
        }
    }
    
    return answer;
}