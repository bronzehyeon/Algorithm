#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int N = book_time.size();
    
    sort(book_time.begin(), book_time.end());
    
    vector<int> out;
    
    for(int i = 0; i < N; i++){
        int checkin = stoi(book_time[i][0].substr(0,2)) * 60 + stoi(book_time[i][0].substr(3,5));
        int checkout = stoi(book_time[i][1].substr(0,2)) * 60 + stoi(book_time[i][1].substr(3,5)) + 10;
        
        bool need = true;
        
        for(int j = 0; j < out.size(); j++){
            if(out[j] <= checkin){
                out[j] = checkout;
                need =false;
                break;
            }
        }
        if(need){
            out.push_back(checkout);
        }
    }
    
    answer = out.size();
    return answer;
}