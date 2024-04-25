#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    char arr[9][9];


    int answer = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            
        }
    }



    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int rp = -N + 1; rp < N; rp++) {
                for (int cp =  -M + 1; cp < M; cp++) {
                    string str = "";
                    int row = i, col = j;
                    while (row < N && col < M && row >= 0 && col >= 0) {
                        str += arr[row][col];
                        string rev = str;
                        
                        reverse(rev.begin(), rev.end());

                        int num = stoi(str);
                        int rnum = stoi(rev);

                        int sqrt1 = sqrt(num);
                        int sqrt2 = sqrt(rnum);



                        if(sqrt1 * sqrt1 == num && num > answer) {
                            answer = num;
                        }

                        if (sqrt2 * sqrt2 == rnum && rnum > answer) {
                            answer = rnum;

                        }

                        if (rp == 0 && cp == 0)
                            break;

                        row += rp;
                        col += cp;
                    }

                    
                    
                }
            }

        }
    }
    cout << answer;

    
}

