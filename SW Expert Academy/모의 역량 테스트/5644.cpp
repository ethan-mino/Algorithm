// Created by 길민호 on 2022/10/14.

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define x first
#define y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

typedef struct{
    pii pos;
    int c, p, idx;
}Battery;

int dist(pii pos1, pii pos2){
    return abs(pos1.x - pos2.x) + abs(pos1.y - pos2.y);
}

vector<Battery> connectable(pii pos, vector<Battery> batteries){
    vector<Battery> connectableBatteries;
    for(auto battery : batteries){
        if(battery.c >= dist(pos, battery.pos)){
            connectableBatteries.push_back(battery);
        }
    }

    // 충전량이 가장 높은 순으로 정렬
    sort(connectableBatteries.begin(), connectableBatteries.end(), [] (Battery b1, Battery b2) -> bool {
        return b1.p > b2.p;
    });

    return connectableBatteries;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 만약 한 BC에 두 명의 사용자가 접속한 경우, 접속한 사용자의 수만큼 충전 양을 균등하게 분배한다.
    // 접속한 BC의 성능(P)만큼 배터리를 충전
    //  모든 사용자가 충전한 양의 합의 최댓값

    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int totalTime, batteryCnt; cin >> totalTime >> batteryCnt;
        int aMove[totalTime], bMove[totalTime];

        for(int i = 0; i < totalTime; i++)
            cin >> aMove[i];    // aMove[t]는 시간이 t일 때 이동할 방향 (t : 0 ~ (totalTime -1))

        for(int i = 0; i < totalTime; i++)
            cin >> bMove[i];

        vector<Battery> batteries;
        for(int i = 0; i < batteryCnt; i++){
            int x, y, c, p; cin >> x >> y >> c >> p;
            batteries.push_back({{y - 1, x - 1}, c, p, i});
        }

        pii a = {0, 0}, b = {9, 9};
        int curTime = 0;
        int charge = 0;

        while(curTime <= totalTime){
            // cout << a.x << " " << a.y << "\n";
            // 현재 위치의 배터리량 계산

            // a에 연결 가능한 배터리를 계산
            vector<Battery> connectableToA = connectable(a, batteries);

            // b에 연결 가능한 배터리를 계산
            vector<Battery> connectableToB = connectable(b, batteries);

            if(connectableToA.size() > 0 && connectableToB.size() > 0){
                int maxCharge = INT_MIN;

                for(auto aBattery : connectableToA){
                    for(auto bBattery : connectableToB) {
                        int curCharge = 0;
                        if(aBattery.idx == bBattery.idx){
                            curCharge += (bBattery.p);
                        }else{
                            curCharge += aBattery.p;
                            curCharge += bBattery.p;
                        }
                        maxCharge = max(maxCharge, curCharge);
                    }
                }
                charge += maxCharge;
            }else if(connectableToA.size() > 0){
                charge += connectableToA[0].p;
            }else if(connectableToB.size() > 0){
                charge += connectableToB[0].p;
            }

            if(curTime >= totalTime) break;

            // 한 칸 이동
            a = {a.x + dx[aMove[curTime] - 1], a.y + dy[aMove[curTime] - 1]};
            b = {b.x + dx[bMove[curTime] - 1], b.y + dy[bMove[curTime] - 1]};

            // 시간 증가
            curTime++;
        }
        cout << "#" << tc << " " << charge << "\n";
    }
}

/*
1
20 3
2 2 3 2 2 2 2 3 3 4 4 3 2 2 3 3 3 2 2 3
4 4 1 4 4 1 4 4 1 1 1 4 1 4 3 3 3 3 3 3
4 4 1 100
7 10 3 40
6 3 2 70

5
20 3
2 2 3 2 2 2 2 3 3 4 4 3 2 2 3 3 3 2 2 3
4 4 1 4 4 1 4 4 1 1 1 4 1 4 3 3 3 3 3 3
4 4 1 100
7 10 3 40
6 3 2 70
40 2
0 3 0 3 3 2 2 1 0 4 1 3 3 3 0 3 4 1 1 3 2 2 2 2 2 0 2 3 2 2 3 4 4 3 3 3 2 0 4 4
0 1 0 3 4 0 4 0 0 1 1 1 0 1 4 4 4 4 4 3 3 3 0 1 0 4 3 2 1 4 4 3 2 3 2 2 0 4 2 1
5 2 4 140
8 3 3 490
60 4
0 3 3 3 0 1 2 2 2 1 2 2 3 3 4 4 0 3 0 1 1 2 2 3 2 2 3 2 2 0 3 0 1 1 1 4 1 2 3 3 3 3 3 1 1 4 3 2 0 4 4 4 3 4 0 3 3 0 3 4
1 1 4 1 1 1 1 1 1 4 4 1 2 2 3 2 4 0 0 0 4 3 3 4 3 3 0 1 0 4 3 0 4 3 2 3 2 1 2 2 3 4 0 2 2 1 0 0 1 3 3 1 4 4 3 0 1 1 1 1
6 9 1 180
9 3 4 260
1 4 1 500
1 3 1 230
80 7
2 2 2 2 2 2 0 2 2 0 4 0 2 3 3 2 3 3 0 3 3 3 4 3 3 2 1 1 1 0 4 4 4 1 0 2 2 2 1 1 4 1 2 3 4 4 3 0 1 1 0 3 4 0 1 2 2 2 1 1 3 4 4 4 4 4 4 3 2 1 4 4 4 4 3 3 3 0 3 3
4 4 1 1 2 1 2 3 3 3 4 4 4 4 4 1 1 1 1 1 1 1 1 0 3 3 2 0 4 0 1 3 3 3 2 2 1 0 3 2 3 4 1 0 1 2 2 3 2 0 4 0 3 4 1 1 0 0 3 2 0 0 4 3 3 4 0 4 4 4 4 0 3 0 1 1 4 4 3 0
4 3 1 170
10 1 3 240
10 5 3 360
10 9 3 350
9 6 2 10
5 1 4 350
1 8 2 450
100 8
2 2 3 2 0 2 0 3 3 1 2 2 2 2 3 3 0 4 4 3 2 3 4 3 3 2 3 4 4 4 2 2 2 0 2 2 4 4 4 4 1 1 1 2 2 2 4 3 0 2 3 3 4 0 0 1 1 4 1 1 1 1 2 2 1 1 3 3 3 0 3 2 3 3 0 1 3 3 0 1 1 3 3 4 0 4 1 1 2 2 4 0 4 1 1 2 2 1 1 1
4 4 4 0 4 1 1 4 1 1 1 1 3 2 1 2 1 1 4 4 1 0 2 3 4 4 4 4 4 0 1 0 2 2 2 0 2 2 2 2 2 2 3 0 0 1 4 3 3 2 0 0 4 4 4 0 2 0 4 1 1 2 2 0 4 4 0 0 2 0 2 3 3 0 2 3 0 3 4 0 4 3 4 4 3 4 1 1 2 2 2 0 0 1 0 4 1 1 1 4
3 4 2 340
10 1 1 430
3 10 4 10
6 3 4 400
7 4 1 80
4 5 1 420
4 1 2 350
8 4 4 300
*/