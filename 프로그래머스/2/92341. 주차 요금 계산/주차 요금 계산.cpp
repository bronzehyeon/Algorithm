#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> extract(string str){
    vector<int> v;
    int hour = (str[0] - '0') * 10 + (str[1] - '0');
    int min = (str[3] - '0') * 10 + (str[4] - '0');
    int car = (str[6] - '0') * 1000 + (str[7] - '0') * 100 + (str[8] - '0') * 10 + (str[9] - '0');
    
    v.push_back(hour);
    v.push_back(min);
    v.push_back(car);
    
    return v;
}

int minute(int inH, int inM, int outH, int outM){
    return (outH-inH) * 60 + outM - inM;
}

int fee(vector<int> f, int m){
    if(f[0] >= m){
        return f[1];
    }
    else{
        int over = m - f[0];
        if(over % f[2] == 0){
            return f[1] + (over / f[2]) * f[3];
        }
        else{
            return f[1] + (over / f[2] + 1) * f[3];
        }
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<int, pair<int,int>> m;
    map<int, int> total;
    
    vector<int> v;
    for(int i = 0; i < records.size(); i++){
        v = extract(records[i]);
        int hour = v[0];
        int min = v[1];
        int car = v[2];
        
        if(m.find(car) == m.end()){
            m[car] = {hour, min};
        }
        else{
            int inHour = m[car].first;
            int inMin = m[car].second;
            m.erase(car);
            total[car] += minute(inHour, inMin, hour, min);
        }
    }
    
    auto iter = m.begin();
    while(iter != m.end()){
        int inHour = iter->second.first;
        int inMin = iter->second.second;
        int car = iter->first;
        total[car] += minute(inHour, inMin, 23, 59);
        iter++;
    }

    auto it = total.begin();
    while(it != total.end()){
        int t = it->second;
        answer.push_back(fee(fees, t));
        it++;
    }
    
    return answer;
}