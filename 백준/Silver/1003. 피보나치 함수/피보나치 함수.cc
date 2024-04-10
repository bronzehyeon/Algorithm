#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    int zero[50] = {1, 0};
    int one[50] = {0 , 1};

    for(int t = 0; t < T; t++){
        int N;
        cin >> N;

        for(int i = 2; i <= N; i++){
            zero[i] = zero[i-1] + zero[i-2];
            one[i] = one[i-1] + one[i-2];
        }
        cout << zero[N] << " " << one[N] << '\n';
    }

    

    return 0;
}