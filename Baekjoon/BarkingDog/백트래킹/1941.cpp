#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

char seat[5][5];
int vis[5][5], board[5][5];
int ans = 0;
int pos[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
               1, 1, 1, 1, 1, 1, 1};

bool bfs(vector<pair<int, int>> v){ // v에 담긴 좌표들이 서로 이어져있는지 확인하는 함수
    fill(&vis[0][0], &vis[4][5], 0);    // 방문 표시 배열과 board를 0으로 초기화
    fill(&board[0][0], &board[4][5], 0);    

    for(auto c : v) board[c.x][c.y] = 1;    //  각 좌표들의 위치를 board에 1로 표시

    queue<pair<int, int>> q;    // 인접한 좌표들을 담을 queue
    q.push({v[0].x, v[0].y});   // bfs의 시작점은 첫 번째 좌표
    vis[v[0].x][v[0].y] = 1;    // 시작점에 방문 표시

    while(!q.empty()){  // bfs 수행
        pair<int, int> cur = q.front(); q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if(board[nx][ny] != 1 || vis[nx][ny] == 1) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }

    for(auto c : v)    // 좌표들 중 방문하지 않은 것이 있다면 false 반환
        if(vis[c.x][c.y] == 0) return false;

    return true;    //  모두 이어져있다면 true 반환
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++){ // 자리 배치도 입력 받음.
        string s; cin >> s;
        for(int j = 0; j < 5; j++){
            seat[i][j] = s[j];
        }
    }

    do{
        vector<pair<int, int>> v;   // 선택한 좌표를 저장할 vector

        for(int i = 0; i < 25; i++){
            if(pos[i] == 1) v.push_back({(i / 5), (i % 5)});    // 선택한 좌표 저장
        }

        bool flag = bfs(v); // bfs로 선택한 좌표들이 이어지는지 확인

        if(flag) {  // 선택한 좌표들이 이어진다면
            int cnt = 0;
            for(auto c : v) if(seat[c.x][c.y] == 'S') cnt++;    // 좌표들 중 'S'의 개수 count

            if(cnt >= 4) ans++; // 'S'의 개수가 4이상이라면 경우의 수 증가
        }
    }while(next_permutation(pos, pos+25));  // 25개 중 7개 선택(조합 - 순서 고려 X)
    
    cout << ans;
}

/*
YYYYY
SYSYS
YYYYY
YSYYS
YYYYY

YYYYY
SYSYS
YYYYY
YYSYS
YYYYY
*/