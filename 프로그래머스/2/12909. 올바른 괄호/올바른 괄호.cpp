#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    st.push(s[0]);
    for(int i = 1; i < s.length(); i++){
        if(s[i] == '('){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                return false;
            }
            if(st.top() == '('){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    if(!st.empty()){
        return false;
    }
    cout << "Hello Cpp" << endl;

    return answer;
}