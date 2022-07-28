// Created by 길민호 on 2022/07/28.

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[1010][1010];
// vis[0][x][y] = 벽을 하나 부쉈을 때 최단 거리
// vis[1][x][y] = 벽을 부수지 않았을 때의 최단 거리
int vis[2][1010][1010];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

void bfs(pair<int, int> st, int v, int wall){    // st는 시작점, wall은 깰 수 있는 벽의 개수
    queue<pair<int, int>> q;
    q.push(st);
    vis[wall][st.x][st.y] = v;

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(board[nx][ny] == 1){ // 벽인 경우
                if(wall != 0 && // 깰 수 있는 벽이 있는 경우
                (vis[wall - 1][nx][ny] == 0 // 아직 방문하지 않은 경우
                || vis[wall - 1][nx][ny] > vis[wall][cur.x][cur.y] + 1)){   // 이미 방문했지만, 현재 위치에서 방문하는 것이 더 최단거리인 경우
                    bfs({nx, ny}, vis[wall][cur.x][cur.y] + 1, wall - 1);
                }
            }else{
                if(vis[wall][nx][ny] == 0   // 아직 방문하지 않은 경우
                || vis[wall][nx][ny] > vis[wall][cur.x][cur.y] + 1){ // 이미 방문했지만, 현재 위치에서 방문하는 것이 더 최단거리인 경우
                    q.push({nx, ny});   // 방문
                    vis[wall][nx][ny] = vis[wall][cur.x][cur.y] + 1;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        for(int j = 0; j < str.size(); j++)
            board[i][j] = str[j] - 48;
    }
    bfs({0, 0}, 1, 1);

    int ans = INT_MAX;  // 벽을 깬 경우와 깨지 않은 경우 중 더 최단거리를 출력
    for(int dist : {vis[0][n - 1][m - 1], vis[1][n - 1][m - 1]}){
        if(dist != 0) ans = min(ans, dist);
    }

    if(ans == INT_MAX) cout << -1;
    else cout << ans;
}