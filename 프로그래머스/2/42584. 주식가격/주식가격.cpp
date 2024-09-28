#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    int N = prices.size();
    stack<pair<int,int>> s;
    
    for(int i = 0; i < N; i++){
        answer[i] = N - i - 1;
    }
    
    for(int i = 0; i < N; i++){
        if(!s.empty() && s.top().first > prices[i]){
            while(!s.empty() && s.top().first > prices[i]){
                int price = s.top().first;
                int time = s.top().second;
                s.pop();
                answer[time] = i - time;
            }
            
        }
        s.push({prices[i], i});
    }
    
    return answer;
}