#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss;
    ss.str(s);
    
    vector<int> v;
    
    while(ss >> s) {
        v.push_back(stoi(s));
    }
    
    sort(v.begin(), v.end());
    
    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v[v.size() - 1]);
    
    
    return answer;
}