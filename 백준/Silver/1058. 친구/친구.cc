#include <iostream>

using namespace std;


int N;
int arr[50][50];
int ans[50];
int b[50];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char tmp;
            cin >> tmp;
            if (tmp == 'Y' && i != j) {
                arr[i][j] = 1;
                arr[i][i] += arr[i][j];
            }
            else if(tmp == N && i != j){
                arr[i][j] = 0;
            }
            
        }
        ans[i] = arr[i][i];
    }

    int max = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1 && i != j ) {
                for (int k = 0; k < N; k++) {
                    if (arr[i][k] == 0 && arr[j][k] == 1 && i != k && j != k) {//나(i)는 친구가 아닌데 내 친구(j)의 친구라면
                        b[k] = 1;
                    }
                }
            }
        }
        for (int j = 0; j < N; j++) {
            ans[i] += b[j];
            b[j] = 0;
        }
        if (ans[i] > max) {
            max = ans[i];
        }
    }

    cout << max;

    
}

