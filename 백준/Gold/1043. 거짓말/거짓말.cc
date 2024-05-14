#include <iostream>
#include <vector>

using namespace std;

int know[51];
vector<int> partyList[51];//파티 회당 참석 인원
int party[51];//파티에 진실을 아는사람이 존재하는가
vector<int> attend[51];

void change(int partyNum) {

    if (party[partyNum] == 1) {//이미 아는 사람이 있는 파티라면 이미 처리되었을 테니 패스
        return;
    }

    party[partyNum] = 1;

    for (int i = 0; i < partyList[partyNum].size(); i++) {
        if (know[partyList[partyNum][i]] != 1) {//만약 모르고 있다면
            know[partyList[partyNum][i]] = 1;//알게하고
            for (int j = 0; j < attend[partyList[partyNum][i]].size(); j++) {//참석하는 모든 파티 인원 알게하기
                change(attend[partyList[partyNum][i]][j]);
            }
        }
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int truth;
    cin >> truth;

    for (int i = 1; i <= truth; i++) {
        int tmp;
        cin >> tmp;
        know[tmp] = 1;
    }

    for (int i = 1; i <= M; i++) {
        party[i] = 0;

        int people;
        cin >> people;

        for (int j = 0; j < people; j++) {
            int tmp;
            cin >> tmp;
            partyList[i].push_back(tmp);
            attend[partyList[i][j]].push_back(i);//해당 인원이 참석하는 파티 리스트에 추가
        }
    }

    for (int i = 1; i <= M; i++) {
        if (party[i] != 1) {//이미 모두가 아는 파티면 패스
            for (int j = 0; j < partyList[i].size(); j++) {
                if (know[partyList[i][j]] == 1) {
                    change(i);
                    break;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= M; i++) {
        if (party[i] == 0)
            ans++;
    }

    cout << ans;

}
