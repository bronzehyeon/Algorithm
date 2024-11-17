#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int toMinute(string time){
    int minute = 0;
    
    minute += (time[0] - '0') * 10 * 60;
    minute += (time[1] - '0') * 60;
    minute += (time[3] - '0') * 10;
    minute += (time[4] - '0');
    
    return minute;
}

string toTime(int time) {
    string s;
    int hour = time / 60;
    if (hour < 10) {
        s += '0';
    }
    s += to_string(hour);
    s += ':';
    
    int minute = time % 60;
    if (minute < 10) {
        s += '0';
    }
    s += to_string(minute);
    
    return s;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int N = timetable.size();
    
    vector<int> v;
    
    for (int i = 0; i < N; i++) {
        v.push_back(toMinute(timetable[i]));
    }
    
    sort(v.begin(), v.end());
    int idx = 0;
    int curTime = 540;
    for (int i = 0; i < n - 1; i++) {
        int onBoard = 0;
        while (idx < N && onBoard < m && v[idx] <= curTime) {
            idx++;
            onBoard++;
        }
        curTime += t;
    }
    if (N - idx < m) {
        answer = toTime(curTime);
    } else {
        answer = toTime(min(curTime,v[idx + m - 1] - 1));
    }
    
    
    return answer;
}