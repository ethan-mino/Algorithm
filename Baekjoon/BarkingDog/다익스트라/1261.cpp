// Created by 길민호 on 2022/06/21.

#include <bits/stdc++.h>
using namespace std;

#define INF 10000000
#define SIZE 101
#define d second
#define pos first

char board[SIZE][SIZE];

typedef struct{
    int x, y;
}Pos;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
Pos pre[SIZE][SIZE];
int dist[SIZE][SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> m >> n;

    vector<pair<Pos, int>> linked[SIZE][SIZE];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            board[i][j] = c;

            for(int dir = 0; dir < 4; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                if(board[nx][ny] == '0'){
                    linked[i][j].push_back({{nx, ny}, 1});
                }else{
                    linked[i][j].push_back({{nx, ny}, 20000});
                }

                if(board[i][j] == '0'){
                    linked[nx][ny].push_back({{i, j}, 1});
                }else{
                    linked[nx][ny].push_back({{i, j}, 20000});
                }
            }
        }
    }

    fill(&dist[0][0], &dist[SIZE - 1][SIZE], INF);

    priority_queue<tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>> pq;

    dist[0][0] = 0;
    pq.push({0, 0, 0});

    while(!pq.empty()){
        int w, x, y;
        tie(w, x, y) = pq.top(); pq.pop();

        if(dist[x][y] != w) continue;
        for(auto nxt : linked[x][y]){
            if(dist[nxt.pos.x][nxt.pos.y] > dist[x][y] + nxt.d){
                dist[nxt.pos.x][nxt.pos.y] = dist[x][y] + nxt.d;
                pre[nxt.pos.x][nxt.pos.y] = {x, y};
                pq.push({dist[nxt.pos.x][nxt.pos.y], nxt.pos.x, nxt.pos.y});
            }
        }
    }

    vector<Pos> path;
    Pos cur = {n - 1, m - 1};
    path.push_back(cur);
    while(!(cur.x == 0 && cur.y == 0)){
        cur = pre[cur.x][cur.y];
        path.push_back(cur);
    }
    path.push_back(cur);

    int ans = 0;
    for(auto p : path){
        if(board[p.x][p.y] == '1') ans++;
    }

    cout << ans << "\n";
}

// 뱍은 평소에는 이동할 수 없지만, 알고스팟의 무기를 이용하여 벽을 부수어 버릴 수 있다.
// 벽을 부수면 빈 방과 동일한 방으로 변한다.