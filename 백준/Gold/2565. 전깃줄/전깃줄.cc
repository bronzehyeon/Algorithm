#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    map<int, int> cable;
    int* arr = new int[N];
    int maxLen = 1;
    int* check = new int[N];

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        cable[A] = B;
    }

    map<int, int>::iterator iter = cable.begin();
   
    int i = 0;
    for (int i = 0; i < N && iter != cable.end(); i++, iter++) {
        arr[i] = iter->second;
    }

    check[N - 1] = 1;

    for (int i = N - 2; i >= 0; i--) {
        int max = 0;
        for (int k = i + 1; k < N; k++) {
            if (arr[k] > arr[i])
                if (max < check[k])
                    max = check[k];
        }
        check[i] = max + 1;
        if (check[i] > maxLen)
            maxLen = check[i];
    }

    cout << N - maxLen;
    
    

}