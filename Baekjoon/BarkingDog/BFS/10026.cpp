#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

char board[100][100];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int bfs(int n){
    int cnt = 0;
    int vis[100][100] = {};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] == 0){
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;

                cnt++;
                while(!q.empty()){
                    pair<int, int> cur = q.front(); q.pop();

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];

                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(vis[nx][ny] != 0 || board[nx][ny] != board[cur.x][cur.y]) continue;

                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    
    cout << bfs(n) << "\n";

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == 'R')
                board[i][j] = 'G';

    cout << bfs(n) << "\n";
}