#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n, m; 
int board[50][50];
int vis[50][50];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int ans = INT_MAX;
void bfs(vector<pair<int, int>> virus){
    fill(&vis[0][0], &vis[49][50], 0);
    queue<pair<int, int>> q;
    for(int i = 0; i < virus.size(); i++) {
        q.push(virus[i]);
        vis[virus[i].x][virus[i].y] = 1;
    }

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || ny < 0|| nx >= n || ny >= n) continue;
            if(board[nx][ny] == 1 || vis[nx][ny] != 0) continue;    // 바이러스를 놓을 수 있는 곳도 이동할 수 있도록 하는 것이 중점
            q.push({nx, ny});
            vis[nx][ny] = vis[cur.x][cur.y] + 1;
        }
    }

    bool t = true; int m = INT_MIN;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0 && vis[i][j] == 0) t = false;
            m = max(m, vis[i][j]);
        }
    
    if(t) ans = min(ans, m - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<pair<int, int>> pos;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) pos.push_back({i, j});
        }

    vector<int> np;
    for(int i = 0; i < pos.size() - m; i++) np.push_back(0);
    for(int i = 0; i < m; i++) np.push_back(1);

    do{
        vector<pair<int, int>> selected;
        for(int i = 0; i < np.size(); i++) if(np[i] == 1) selected.push_back(pos[i]);
        bfs(selected);
    }while(next_permutation(np.begin(), np.end()));
    cout << ((ans == INT_MAX) ? - 1 : ans);
}