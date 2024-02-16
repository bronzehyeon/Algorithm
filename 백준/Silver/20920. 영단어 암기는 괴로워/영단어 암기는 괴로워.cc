#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;



int main() {
    int N, M;
    cin >> N >> M;

    int maxLen = 0;
    int appear = 1;
    map<string, int> voca;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        if (word.length() >= M) {
            if (voca.find(word) == voca.end()) {
                voca.insert({ word, 1 });
            }
            else {
                voca[word] += 1;
                if (voca[word] > appear)
                    appear = voca[word];
            }
            if (word.length() > maxLen)
                maxLen = word.length();
        }
    }

    map<string, int>::iterator iter = voca.begin();

    set<string> sameFrequency;

    for (int i = appear; i > 0; i--) {
        iter = voca.begin();
        while (iter != voca.end()) {
            if (iter->second == i) {
                sameFrequency.insert(iter->first);
                voca.erase(iter++);
            }
            else
                iter++;
        }
        for (int i = maxLen; i > 0; i--) {
            set<string>::iterator iter2 = sameFrequency.begin();
            while (iter2 != sameFrequency.end()) {
                if ((*iter2).length() == i) {
                    cout << *iter2 << '\n';
                    sameFrequency.erase(iter2++);
                }
                else
                    iter2++;
            }
        }
    }  
}