#include <iostream>
#include<set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int max = 2;
    set<int> prime;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        if (max < N) {
            for (int i = max; i < N; i++) {
                bool isPrime = true;
                for (int j = 2; (j * j) <= i; j++) {
                    if (i % j == 0) {
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime) {
                    prime.insert(i);
                }
            }
            max = N;
        }


        int count = 0;
        for (set<int>::iterator iter = prime.begin(); iter != prime.end() && N / 2 >= *iter; iter++) {            
            if (prime.find(N - *iter) != prime.end())
                count++;
        }
        cout << count << '\n';

    }
}