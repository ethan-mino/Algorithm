#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int r, c, t;
int board[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void air(pair<int, int> a, int dir){  // a는 공기청정기 아래 칸의 좌표, f가 1이면 윗 바람, 0이면 아래 바람
    pair<int, int> cur = a; // 공기청정기 위치

    while(true){
        pair<int, int> nx = {cur.x + dx[dir], cur.y + dy[dir]};
        // 다음 칸이 방을 벗어나거나 공기청정기와 같은 행인 경우 방향을 바꿈
        if(nx.x < 0 || nx.y < 0 || nx.x >= r || nx.y >= c || (cur.x == a.x && cur.y == c - 1)) {
            if(board[a.x - 1][a.y] == -1) dir = ((dir == 0) ? dir = 3 : dir - 1);
            else dir = (dir + 1) % 4;
            nx = {cur.x + dx[dir], cur.y + dy[dir]};
        }
        
        // 다음 칸이 공기청정기라면, 현재 칸에 0을 채우고 종료
        if(nx.x == a.x && nx.y == a.y)  {board[cur.x][cur.y] = 0; break;} 
            
        if(cur.x == a.x && cur.y == a.y){   // 현재 위치가 공기청정기라면
            board[nx.x][nx.y] = 0;  // 공기청정기로 들어간 미세먼지는 모두 정화된다
        }else{  // 현재 위치가 공기청정기가 아니라면
            board[cur.x][cur.y] = board[nx.x][nx.y];    // 한 칸씩 당김
        }
        cur = nx;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> t;
    pair<int, int> a;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
            if(board[i][j] == -1) a = {i, j}; // 공기청정기의 위치
        }

    int time = 0;
    while(time < t){
        int temp[50][50];
        fill(&temp[0][0], &temp[49][50], 0);

        for(int i = 0; i < r; i++){ // 미세먼지가 확산된다
            for(int j = 0; j < c; j++){
                if(board[i][j] > 0){  // 해당 칸에 미세먼지가 있는 경우
                    int n = 0; // 미세먼지가 확산된 방향의 개수
                    for(int dir = 0; dir < 4; dir++){
                        pair<int, int> nx = {i + dx[dir], j + dy[dir]};
                        if(nx.x < 0 || nx.y < 0 || nx.x >= r || nx.y >= c || board[nx.x][nx.y] == -1) continue;
                        temp[nx.x][nx.y] += board[i][j] / 5;   // 확산되는 양
                        n++;    // 확산된 방향의 개수
                    }

                    board[i][j] -= (board[i][j] / 5) * n;   // (r,c)애 넘운 미세먼지의 양
                }
            }
        }
 
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                board[i][j]+=temp[i][j];    // 해당 칸으로 확산된 미세먼지의 양을 더해줌

        // 공기청정기가 작동한다.
        air({a.x - 1, a.y}, 0);  // 위쪽 공기청정기 바람
        air(a, 2);  // 아래쪽 공기청정기 바람

        time++; // 시간 증가
    }

    int ans = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(board[i][j] != -1)
                ans += board[i][j];

    cout << ans;
}

/*
3 3 1
0 30 7
-1 10 0
-1 0 20


4 5 1
1 2 3 4 5
-1 1 2 3 4
-1 4 5 6 7
2 3 4 5 6
*/