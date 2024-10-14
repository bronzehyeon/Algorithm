#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isEnd(vector<string>& board, char c){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != c){
                break;
            }
            if(j == 2){
                return true;
            }
        }
        for(int j = 0; j < 3; j++){
            if(board[j][i] != c){
                break;
            }
            if(j == 2){
                return true;
            }
        }
    }
    if(board[1][1] != c){
        return false;
    }
    if(board[0][0] == c && board[2][2] == c){
        return true;
    }
    if(board[2][0] == c && board[0][2] == c){
        return true;
    }
    return false;
}

int solution(vector<string> board) {
    int answer = 1;
    
    int o = 0;
    int x = 0;
    
    bool oEnd = isEnd(board,'O');
    bool xEnd = isEnd(board,'X');
     
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == 'O'){
               o++; 
            }
            else if(board[i][j] == 'X'){
                x++;
            }
        }
    }
    if(!(o-x == 1 || o-x==0)){
        return 0;
    }
    
    if(oEnd && x == o){
        return 0;
    }
    if(xEnd && o > x){
        return 0;
    }
    
    return answer;
}