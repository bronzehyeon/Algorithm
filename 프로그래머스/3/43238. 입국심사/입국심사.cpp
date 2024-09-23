#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long s = 0;
    sort(times.begin(), times.end());
    long long e = (long long) times[times.size() - 1] * n;
    
    while(s < e){
        long long m = (s+e) / 2;
        long long sum = 0;
        
        for(int i = 0; i < times.size(); i++){
            //long long time = (long long) times[i];
            sum += m / times[i];
        }
        if(sum < n){
            s = m + 1;
        }
        else{
            e = m;
        }
    }
    answer = e;
    return answer;
}