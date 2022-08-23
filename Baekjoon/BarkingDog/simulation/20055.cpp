// Created by SSAFY on 2022-08-23.

#include <bits/stdc++.h>
using namespace std;

#define duration first
#define robot second

int cnt = 0;    // 내구도가 0인 칸의 개수
void move(deque<pair<int, int>> & cur, int curIdx, deque<pair<int, int>>& nx, int nxIdx){
    nx[nxIdx].robot = cur[curIdx].robot;
    nx[nxIdx].duration--;
    cur[curIdx].robot = -1;
    if(nx[nxIdx].duration == 0) cnt++;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;

    deque<pair<int, int>> upper, lower;    // 위 컨베이어, 아래 컨베이어
    for(int i = 0; i < 2 * n; i++) {
        int d; cin >> d;
        if(i < n) upper.push_back({d, -1});
        else lower.push_front({d, -1});
    }

    int t = 1;
    while(true){ // 내구도가 0인칸의 개수가 k개 미만일 때 동작
        // 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
        // 위 컨베이어의 뒤에서 하나를 뺀다.
        pair<int, int> back = upper.back(); upper.pop_back();
        // 아래 컨베이어의 앞에서 하나를 뺀다.
        pair<int, int> front = lower.front(); lower.pop_front();

        lower.push_back(back);
        upper.push_front(front);

        upper[n - 1].robot = -1;    // 내리는 위치의 로봇을 내려줌

        priority_queue<tuple<int, int, int>,
                vector<tuple<int, int, int>>, greater<>> pq;

        for(int i = 0; i < upper.size(); i++)
            if(upper[i].robot != -1) pq.push({upper[i].robot, 0, i});

        for(int i = 0; i < lower.size(); i++)
            if(lower[i].robot != -1) pq.push({lower[i].robot, 1, i});

        while(!pq.empty()) {
            int robotNum, q, cur;
            tie(robotNum, q, cur) = pq.top(); pq.pop();

            if(q == 0){ // 위 컨테이너
                int nx = cur + 1;
                if(nx == n){ // 아래 컨테이너로 이동해야하는 경우
                    // 이동할 칸에 로봇이 없고, 내구도가 남아있는 경우
                    if(lower[n - 1].robot == -1 && lower[n - 1].duration >= 1){
                        move(upper, cur, lower, n - 1);
                    }
                }else{  // 앞에 칸으로 이동하는 경우
                    if(upper[nx].robot == -1 && upper[nx].duration >= 1){
                        move(upper, cur, upper, nx);
                    }
                }
            }else{
                int nx = cur - 1;
                if(nx == -1){ // 위 컨테이너로 이동해야하는 경우
                    // 이동할 칸에 로봇이 없고, 내구도가 남아있는 경우
                    if(upper[0].robot == -1 && upper[0].duration >= 1){
                        move(lower, cur, upper, 0);
                    }
                }else{  // 앞에 칸으로 이동하는 경우
                    if(lower[nx].robot == -1 && lower[nx].duration >= 1){
                        move(lower, cur, lower, nx);
                    }
                }
            }
        }

        // 내리는 위치에 도달하면 그 즉시 내린다.
        upper[n - 1].robot = -1;

        int m = 0;
        for(auto u : upper) m = max(m, u.robot);
        for(auto l : lower) m = max(m, l.robot);

        // 올리는 칸의 내구도가 남아있고, 로봇이 없는 경우
        // 로봇을 올림
        if(upper[0].duration > 0 && upper[0].robot == - 1){
            upper[0].duration--;
            upper[0].robot = m + 1;
            if(upper[0].duration == 0) cnt++;
        }

        if(cnt >= k) break;
        t++;
    }

    cout << t << "\n";
}