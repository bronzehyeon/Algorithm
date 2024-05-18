#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int cnt = 0;
vector<int> v;


void solve(int idx) {

    int left = 0, right = N - 1;

    while (left < right) {
        if (v[left] + v[right] == v[idx]) {
            if (left != idx && right != idx) {
                cnt++;
                break;
            }
            else if (left == idx)
                left++;
            else if (right == idx) 
                right--;
        }
        else if (v[left] + v[right] < v[idx]) {
            left++;
        }
        else {
            right--;
        }
    }
}


int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin>> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());


    for (int i = 0; i < N; i++) {
        solve(i);
    }

    cout << cnt;

}