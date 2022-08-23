// Created by SSAFY on 2022-08-23.

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
int board[60][60];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) v.push_back({i, j});
        }
    }

    vector<int> np;
    for(int i = 0; i < v.size() - m; i++) np.push_back(0);
    for(int i = 0; i < m; i++) np.push_back(1);

    int ans = INT_MAX;
    do{
        int vis[100][100];
        fill(&vis[0][0], &vis[n - 1][n], 0);

        queue<pair<int, int>> q;
        for(int i = 0; i < v.size(); i++){
            if(np[i] == 1) {
                q.push(v[i]);
                vis[v[i].x][v[i].y] = 1;
            }
        }

        while(!q.empty()){
            pair<int, int> cur = q.front(); q.pop();

            for(int dir = 0; dir < 4; dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(board[nx][ny] == 1 || vis[nx][ny] != 0) continue;

                q.push({nx, ny});
                vis[nx][ny] = vis[cur.x][cur.y] + 1;
            }
        }

        int t = INT_MIN;
        bool infec = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != 1){
                    if(vis[i][j] == 0) infec = false;   // 전염되지 않았다면, infec을 false로 설정
                    if(board[i][j] == 0) t = max(t, vis[i][j] - 1);
                }
            }
        }

        if(infec) {
            if(t == INT_MIN) t = 0;
            ans = min(ans, t);
        }
    }while(next_permutation(np.begin(), np.end()));

    if(ans == INT_MAX) cout << -1;
    else cout << ans << "\n";
}
