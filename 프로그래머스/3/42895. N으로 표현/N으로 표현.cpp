#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    
    if(N == number){
        return 1;
    }
    
    vector<int> v[9];
    v[1].push_back(N);
    for(int i = 2;i <= 8; i++){
        set<int> s;
        int tmp = 0;
        for(int j = 0; j < i; j++){
            tmp = tmp * 10 + N;
        }
        s.insert(tmp);
        for(int j = 1; j < i; j++){
            for(int x = 0; x < v[i - j].size(); x++){
                int a = v[i-j][x];
                for(int y = 0; y < v[j].size(); y++){
                    int b = v[j][y];
                    s.insert(a + b);
                    s.insert(a - b);
                    s.insert(a * b);
                    if(b != 0){
                        int di = a / b;
                        s.insert(di);
                    }
                }
            }
        }
        if(s.find(number) != s.end()){
            answer = i;
            break;
        }
        for(auto iter = s.begin(); iter != s.end(); iter++){
            v[i].push_back(*iter);
        }
    }
    
    return answer;
}

