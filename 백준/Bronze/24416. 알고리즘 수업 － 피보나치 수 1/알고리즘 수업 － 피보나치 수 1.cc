#include <iostream>
using namespace std;

int recursion = 0;
int dynamic = 0;

int fibonachiRecursion(int n) {
    if (n == 1 || n == 2) {
        recursion++;
        return 1;
    }
    return fibonachiRecursion(n - 1) + fibonachiRecursion(n - 2);
}

int fibonachiDP(int n) {
    int arr[40];
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
        dynamic++;
    }
    return arr[n - 1];
}

int main() {

    int N;
    cin >> N;

    fibonachiRecursion(N);
    fibonachiDP(N);

    cout << recursion << " " << dynamic;

    //cout << recursion << " " << N - 2;

}