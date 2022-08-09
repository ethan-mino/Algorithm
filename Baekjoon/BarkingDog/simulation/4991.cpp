#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int w, h;

int bfs(char board[20][20], pair<int, int> s, pair<int, int> d){ // s에서 d까지의 최단 거리를 구하는 함수
    int vis[20][20];
    fill(&vis[0][0], &vis[19][20], 0);
    queue<pair<int, int>> q;
    q.push(s);
    vis[s.x][s.y] = 1;

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();

        for(int dir = 0; dir < 4; dir++){
            pair<int, int> nx = {cur.x + dx[dir], cur.y + dy[dir]};
            if(nx.x < 0 || nx.y < 0 || nx.x >= h || nx.y >= w) continue;
            // 가구이거나 이미 방문한 경우 방문하지 않음
            if(board[nx.x][nx.y] == 'x' || vis[nx.x][nx.y] != 0) continue;  
            q.push(nx);
            vis[nx.x][nx.y] = vis[cur.x][cur.y] + 1;
        }
    }
    
    return (vis[d.x][d. y] == 0) ? -1 : vis[d.x][d. y] - 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        cin >> w >> h;
        if(!w && !h) break;
        
        char board[20][20];
        pair<int, int> r;   // 로봇 청소기의 위치
        vector<pair<int, int>> d;  // 더러운 칸의 좌표
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++){
                cin >> board[i][j];
                if(board[i][j] == 'o') r = {i, j};  
                if(board[i][j] == '*') d.push_back({i, j});
            }
        int ans = INT_MAX;

        // 메모이제이션을 위한 배열 m[x1][y1][x2][y2] : (x1, y1)와 (x2, y2)의 거리
        int m[20][20][20][20];  
        fill(&m[0][0][0][0], &m[19][19][19][20], 0);

        do{ // 각각의 더러운 칸 수열에 대해 반복
            pair<int, int> tr = r;  // 로봇 청소기 위치 저장
            char temp[20][20];
            memcpy(temp, board, sizeof(temp));
            int t = 0;  // 현재 수열에 대한 이동 횟수

            for(int i = 0; i < d.size(); i++){  // 각각의 더러운 칸에 대해서 반복
                temp[d[i].x][d[i].y] = 'o'; // 더러운 칸은 로봇의 위치로 변경
                temp[tr.x][tr.y] = '.'; // 로봇이 있던 위치는 빈 칸으로 변경

                if(m[tr.x][tr.y][d[i].x][d[i].y] == 0){ // 더러운 칸까지의 거리가 메모되어 있지 않다면
                    int dist = bfs(temp, tr, d[i]); // BFS를 수행하고 더러운 칸까지 최단 거리를 계산
                    m[tr.x][tr.y][d[i].x][d[i].y] = dist;   // 더러운 칸까지의 거리 메모

                    if(dist == -1) {t = INT_MAX; break;}    // 더러운 칸으로 이동할 수 없는 경우
                    else {t += dist;}   // 더러운 칸으로 이동할 수 있는 경우
                }else{  // 더러운 칸까지의 거리가 메모 되어 있다면
                    if(m[tr.x][tr.y][d[i].x][d[i].y] == -1) {t = INT_MAX; break;}
                    else {t += m[tr.x][tr.y][d[i].x][d[i].y];}
                }
                tr = d[i];  // 로봇은 더러운 칸으로 이동
            }
            ans = min(ans, t);
        }while(next_permutation(d.begin(), d.end()));

        cout << ((ans == INT_MAX) ? -1 : ans) << "\n";
    }
}


/*
7 5
.......
.o...*.
.......
.*...*.
.......
0 0

15 13
.......x.......
...o...x....*..
.......x.......
.......x.......
.......x.......
...............
xxxxx.....xxxxx
...............
.......x.......
.......x.......
.......x.......
..*....x....*..
.......x.......
0 0 
*/