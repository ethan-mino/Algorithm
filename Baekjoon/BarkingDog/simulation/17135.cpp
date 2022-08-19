// Created by 길민호 on 2022/08/11.

#include <bits/stdc++.h>
using namespace std;

// 제거할 수 있는 적의 최대 수를 구해야하므로, 여러 궁수가 같은 적을 공격할 수 있는 것이 핵심 조건
// 성의 가장 앞이 아닌, 뒤에도 궁수를 배치할 수 있지만, 성의 가장 앞에 궁수를 배치하는 것이 공격 범위를 가장 늘릴 수 있음
// 따라서 (성의 너비)c3을 구해서 궁수를 배치하고, 각각의 경우의 수에 대해 게임을 진행하면 됨
// 모든 궁수는 동시에 공격하기 때문에, 각 궁수가 제거할 적을 찾고, 일괄적으로 제거 해주어야 함.
#define x first
#define y second
typedef pair<int, int> pii;
int board[15][15];
int n, m, d;

int manhattan(pii p1, pii p2){  // p1 좌표와 p2 좌표 간의 거리를 계싼
    return p1.x - p2.x + abs(p1.y - p2.y);
}

int game(vector<pii> archers, vector<pii> enemys){
    int removed = 0;    // 궁수에게 제거된 적의 수

    int enemyCnt = enemys.size();
    while(enemyCnt > 0){ // 적이 모두 제거될 때까지 게임 진행
        set<pii> nearEmemys;    // 각 궁수와 가까운 적의 좌표를 저장하는 벡터

        for(auto archer : archers){ // 각 궁수와 가장 가까운 적을 찾음
            pii near = {-1, -1};    // i번째 궁수와 가장 가까운 적의 위치
            int distMin = INT_MAX;  // 가장 가까운 적과의 거리
            for(auto enemy : enemys) {    // 각 적을 순회
                int dist = manhattan(archer, enemy); // 궁수와 적과의 거리 계산

                if(dist <= d){     // 적이 사정거리 안에 있는 경우
                    if(dist < distMin   // 기존 적보다 더 가까운 경우
                    || (dist == distMin && near.y > enemy.y)){  // 거리는 같지만 더 왼쪽에 있는 경우
                        near = enemy; // 적 위치 저장
                        distMin = dist; // 적과의 거리 저장
                    }
                }
            }
            nearEmemys.insert(near); // 가장 가까운 적의 위치 insert
        }

        for(auto enemy : nearEmemys){ // 궁수에게 공격 당한 적들을 일괄 제거함
            for(auto iter = enemys.begin(); iter != enemys.end();){ // 적들을 순회
                if(enemy == (*iter)){   // 궁수에게 제거된 적인 경우
                    enemyCnt--; // 남은 적의 수 감소
                    removed++;  // 궁수의 공격에 당한 적의 수 증가
                    iter = enemys.erase(iter);  // 적 제거
                }else{
                    iter++;
                }
            }
        }

        // 성이 있는 칸으로 이동한 적을 게임에서 제외
        for(auto iter = enemys.begin(); iter != enemys.end();){
            (*iter).x++;    // 적을 한칸 아래로 이동시킴
            if((*iter).x >= n){ // 격자판을 벗어나는 경우
                enemyCnt--; // 적의 수 감소
                iter = enemys.erase(iter);  // 적 제거
            }else{
                iter++;
            }
        }
    }

    return removed; // 궁수의 공격에 당한 적의 수 반환
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d;

    vector<pii> enemys;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) enemys.push_back({i, j});
        }

    vector<int> y;
    for(int i = 0; i < m - 3; i++) y.push_back(0);
    for(int i = 0; i < 3; i++) y.push_back(1);

    int ans = INT_MIN;
    do{
        vector<int> yPos;
        for(int i = 0; i < m; i++) if(y[i] == 1) yPos.push_back(i);

        pii a1 = {n, yPos[0]};
        pii a2 = {n, yPos[1]};
        pii a3 = {n, yPos[2]};

        int removed = game({a1, a2, a3}, enemys);
        ans = max(ans, removed);
    }while(next_permutation(y.begin(), y.end()));

    cout << ans << "\n";
}

/*
5 5 10
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
-> 0

5 5 10
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 1
-> 3

15 15 10
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
-> 3
*/