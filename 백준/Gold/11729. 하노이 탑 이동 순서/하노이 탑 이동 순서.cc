#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int N, int source, int dest, int proc) {
    if (N == 1) {
        cout << source << " " << dest << '\n';
    }
    else {
        hanoi(N - 1, source, proc, dest);
        cout << source << " " << dest << '\n';
        hanoi(N - 1, proc, dest, source);
    }
    
}



int main() {
    int N;
    cin >> N;

    cout << (int)pow(2, N) - 1 << '\n';

    hanoi(N, 1, 3, 2); 
}