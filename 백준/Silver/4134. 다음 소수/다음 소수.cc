#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int T;
    cin >> T;
    
    for(long long int i = 0; i < T; i++){
        long long int N;
        cin >> N;
        
        long long int answer = N;
        if(answer <= 1)
            answer = 2;
        while(true) {
            bool prime = true;
            for (long long int j = 2; (j * j) <= answer; j++) {
                if (answer % j == 0) {
                    prime = false;
                    break;
                }
            }
            if (prime) {
                break;
            }
            answer++;
        }
        cout << answer << '\n';
    }
}