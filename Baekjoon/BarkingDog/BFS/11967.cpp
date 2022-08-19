// Created by 길민호 on 2022/07/27.
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define a first
#define b second

int board[101][101];
int vis[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
map<pair<int, int>, vector<pair<int, int>>> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int ans = 1;
    vector<pair<int, int>> avail;

    for(int i = 0; i < m; i++){
        pair<int, int> a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        a.x--; a.y--;
        b.x--; b.y--;
        s[a].push_back(b);

        if(a.x == 0 && a.y == 0) {
            avail.push_back(b);
        }
    }

    // 현재 방문할 수 있지만, 방문하지 않은 방 중, 스위치가 있는 방의 불을 켬
    pair<int, int> st = {0, 0};
    board[st.x][st.y] = 1;

    bool end = false;

    while(!end){
        fill(&vis[0][0], &vis[n - 1][n], 0);
        queue<pair<int, int>> q;
        bool on1 = false, on2 = false;

        q.push(st);
        vis[st.x][st.y] = 1;

        for(auto pos : avail) {
            if(board[pos.x][pos.y] != 1){
                board[pos.x][pos.y] = 1;
                ans++;
            }
        }

        if(!avail.empty()) on1 = true;
        avail.clear();

        while(!q.empty()){
            pair<int, int> cur = q.front(); q.pop();

            for(int dir = 0; dir < 4; dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(vis[nx][ny] != 0 || board[nx][ny] != 1) continue;
                vector<pair<int, int>> ns = s[{nx, ny}];

                for(auto pos : ns){
                    if(board[pos.x][pos.y] != 1 && !(pos.x == 0 && pos.y == 0)) {
                        avail.push_back(pos);
                    }
                }

                q.push({nx, ny});
                vis[nx][ny] = vis[cur.x][cur.y] + 1;
            }
        }
        if(!avail.empty()) on2 = true;

        if(!on1 && !on2) end = true;
    }
    cout << ans << "\n";
}

/*
3 6
1 1
*/