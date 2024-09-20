#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while(true){
        int billMax = bill[0] < bill[1];
        int billMin = !billMax;
        int walletMax = wallet[0] < wallet[1];
        int walletMin = !walletMax;
        if(bill[billMax] <= wallet[walletMax] && bill[billMin] <= wallet[walletMin]){
            break;
        }
        answer++;
        bill[billMax] /= 2;
    }
    
    return answer;
}