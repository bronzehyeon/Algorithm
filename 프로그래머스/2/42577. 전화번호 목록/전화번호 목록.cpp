#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> pb) {
    bool answer = true;
    
    sort(pb.begin(), pb.end());
    
    for(int i = 0; i<pb.size()-1;i++){
        if(pb[i].length() >= pb[i+1].length()){
            continue;
        }
        for(int j = 0; j < pb[i].length(); j++){
            if(pb[i][j] != pb[i+1][j]){
                break;
            }
            if(j == pb[i].length()-1){
                return false;
            }
        }
    }
    
    return answer;
}