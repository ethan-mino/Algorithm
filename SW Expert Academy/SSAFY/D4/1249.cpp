// Created by 길민호 on 2022/07/01.

#include <bits/stdc++.h>
using namespace std;

#define SIZE 101
#define d first
#define pos second
#define x first
#define y second
#define INF 20000
typedef pair<int, int> pii;

int dist[SIZE][SIZE];
pair<int, int> pre[SIZE][SIZE];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int shortest(int map[SIZE][SIZE], pii st, pii end, int n){
    fill(&dist[0][0], &dist[n - 1][n], INF);
    dist[st.x][st.y] = 0;

    priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;

    pq.push({dist[st.x][st.y], st});
    while(!pq.empty()){
        pair<int, pii> cur = pq.top(); pq.pop();
        if(dist[cur.pos.x][cur.pos.y] != cur.d) continue;

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.pos.x + dx[dir];
            int ny = cur.pos.y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(dist[nx][ny] > dist[cur.pos.x][cur.pos.y] + map[nx][ny]){
                dist[nx][ny] = dist[cur.pos.x][cur.pos.y] + map[nx][ny];
                pq.push({dist[nx][ny], {nx, ny}});
                pre[nx][ny] = {cur.pos.x, cur.pos.y};
            }
        }
    }

    return dist[end.x][end.y];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    int cur = 1;

    while(t--){
        int n; cin >> n;
        int board[SIZE][SIZE];

        for(int i = 0; i < n; i++){
            string str; cin >> str;
            for(int j = 0; j < str.size(); j++)
                board[i][j] = str[j] - 48;
        }

        pii st = {0, 0}, en = {n - 1, n - 1};

        int d = shortest(board, st, en, n);
        cout << "#" << cur++ << " " << d << "\n";
    }
}