// Created by 길민호 on 2022/11/05.
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[10][10];
vector<pair<int, int>> persons, stairs;
deque<pair<int, int>> stairWait[2];

int manhattan(pair<int, int> a, pair<int, int> b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int minDownTime = INT_MAX;
void back(int personIdx){
    if(personIdx == persons.size()){
        int curMaxDownTime = INT_MIN; // 현재 경우의 수에 대해 두 계단 중 대기하는 사람이 모두 내려가는데 더 오래 걸리는 시간
        for(int stairIdx = 0; stairIdx < 2; stairIdx++){
            pair<int,int> curStair = stairs[stairIdx];
            int onStairCnt = 0; // 현재 계단에 올라간 사람의 수

            priority_queue<int, vector<int>, greater<>> arrvalTimes;
            for(int waitIdx = 0; waitIdx < stairWait[stairIdx].size(); waitIdx++){
                int personToStair = manhattan(stairWait[stairIdx][waitIdx], stairs[stairIdx]);
                arrvalTimes.push(personToStair);
            }

            int waitIdx = 0;
            int curTime = 0;
            queue<int> onStairPersons;   // 계단 위에 올라가 있는 사람을 저장 (해당 사람이 이동 완료하는 시각을 저장)

            while(!arrvalTimes.empty() || !onStairPersons.empty()){
                while(!onStairPersons.empty()){
                    int curExitTime = onStairPersons.front();
                    if(curExitTime == curTime){
                        onStairPersons.pop();
                    }else{
                        break;
                    }
                }

                while(!arrvalTimes.empty() && onStairPersons.size() < 3){
                    int curArrival = arrvalTimes.top();

                    if(curArrival <= curTime){
                        arrvalTimes.pop();
                        int exitTime = curTime + board[curStair.x][curStair.y];
                        onStairPersons.push(exitTime);
                    }else{
                        break;
                    }
                }

                curTime++;
            }
            curMaxDownTime = max(curMaxDownTime, curTime);
        }
        minDownTime = min(minDownTime, curMaxDownTime);
    }else{
        for(int stairIdx = 0; stairIdx < 2; stairIdx++){
            stairWait[stairIdx].push_back(persons[personIdx]);
            back(personIdx + 1);
            stairWait[stairIdx].pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int n; cin >> n;

        persons.clear();
        stairs.clear();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> board[i][j];
                if(board[i][j] == 1) persons.push_back({i, j});
                else if(board[i][j] >= 2) stairs.push_back({i, j});
            }
        }

        minDownTime = INT_MAX;
        back(0);

        cout << "#" << tc << " " << minDownTime << "\n";
    }
}
/*
1
4
1 1 0 3
1 0 0 0
0 0 0 3
0 0 0 0

1
4
1 0 0 3
0 0 0 0
0 0 0 3
0 0 0 0
*/