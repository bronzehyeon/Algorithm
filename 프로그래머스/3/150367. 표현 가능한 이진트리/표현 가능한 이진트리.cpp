#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string str = "";

void binary(long long n){
    string s = "";
    while(n){
        s += to_string(n % 2);
        n /= 2;
    }
    int len = s.length();
    int i = 1;
    while(i < len){
        i = i * 2 + 1;
    }
    for(int j = 0; j < i - len; j++){
        s+='0';
    }
    str = s;
}

bool inorder(int s, int e){
    if(s == e){
        return true;
    }
    int m = (s + e) / 2;
    int child1 = (s + m) / 2;
    int child2 = (m + e) / 2 + 1;
    
    if(str[m] == '0' && (str[child1] == '1' || str[child2] == '1')){
        return false;
    }
    
    return inorder(s, m - 1) && inorder(m + 1, e);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    int N = numbers.size();
    
    for(int i = 0; i < N; i++){
        binary(numbers[i]);
        
        answer.push_back(inorder(0, str.length() - 1));
    }
    
    
    return answer;
}