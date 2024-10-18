#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int N = enroll.size();
    
    vector<int> answer(N);
    
    unordered_map<string,int> um;
    
    for(int i = 0; i < N; i++){
        string name = enroll[i];
        um[name] = i;
    }
    
    for(int i = 0; i < seller.size(); i++){
        int cur = um[seller[i]];
        int price = amount[i] * 100;
        if(referral[cur] == "-"){
            answer[cur] += price - price/10;
            continue;
        }
        int parent = um[referral[cur]];
        
        while(price > 0){
            answer[cur] += price - price / 10;
            price /= 10;
            cur = parent;
            if(referral[parent] == "-"){
                answer[parent] += price - price/10;
                break;
            }
            parent = um[referral[parent]];
        }
        
    }
    
    
    return answer;
}