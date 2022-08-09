#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n, m;
char board[10][10];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int tilt(char b[][10], int dir){    // 게임판을 dir 방향으로 기울이는 함수
    int it; // 반복 횟수 (상/하 기울임인 경우 m번 반복, 우/좌 기울임인 경우 n번 반복)
    if(dir == 0 || dir == 2) it = m;  
    else it = n;

    bool escape[2] = {false, false};    // 구슬이 탈출했는지 나타내는 flag 배열 (0 : 빨간 구슬, 1 : 파란 구슬)
    for(int j = 0; j < it; j++){    // 
        pair<int, int> cur; // 검사 좌표
        if(dir == 0) cur = {1, j};  // 위쪽 기울임인 경우 (위에서 부터 검사)
        else if(dir == 1) cur = {j, m - 2}; // 오른쪽 기울임인 경우
        else if(dir == 2) cur = {n - 2, j}; // 아래쪽 기울임인 경우
        else cur = {j, 1};  // 왼쪽 기울임인 경우
        
        while(true){    // 구슬을 만날 때까지 기울임 반대 방향으로 이동
            // 검사 좌표가 게임판을 벗어나는 경우
            if(cur.x < 0 || cur.y < 0 || cur.x >= n || cur.y >= m) break;   

            if(b[cur.x][cur.y] == 'R' || b[cur.x][cur.y] == 'B'){   // 검사하는 좌표에 구슬이 있는 경우
                pair<int, int> marble = {cur.x, cur.y}; // 구슬의 좌표

                while(true){    // 구슬을 기울임 방향으로 이동시킴
                    pair<int, int> nx = {marble.x+dx[(dir+2)%4],marble.y+dy[(dir+2)%4]};    // 구슬의 이동할 좌표

                    // 구슬이 이동할 위치가 벽이거나, 구슬인 경우 더이상 이동하지 않음
                    if(b[nx.x][nx.y] == '#' || b[nx.x][nx.y] == 'R' || b[nx.x][nx.y] == 'B') break; 
                    else if (b[nx.x][nx.y] == 'O'){ // 구슬이 이동할 위치가 구멍인 경우
                        // 빨간 구슬인 경우 0을 true로, 파란 구슬인 경우 1을 true로 set
                        if(b[marble.x][marble.y] == 'R') escape[0] = true;  
                        else escape[1] = true;

                        // 구슬이 빠져나가므로 구슬의 위치를 '.'으로 변경
                        b[marble.x][marble.y] = '.';    
                        break;  // 더이상 구슬을 이동시키지 않음
                    }else{  // 빈 칸인 경우
                        b[nx.x][nx.y] = b[marble.x][marble.y];  // 구슬을 빈 칸으로 이동시킴
                        b[marble.x][marble.y] = '.';    // 구슬의 이전 위치는 빈 칸으로 만듦
                        marble = nx;    // 구슬을 이동시킴
                    }
                }
            }
            cur = {cur.x + dx[dir], cur.y + dy[dir]};   // 검사 좌표를 기울임 반대 방향으로 한 칸 이동시킴
        }
    }

    if(escape[1]) return -1;  // 파란 구슬이 탈출한 경우
    else if(escape[0]) return 1; // 빨간 구슬만 탈출한 경우
    else return 0; // 아무 구슬도 탈출하지 못한 경우
}

int ans = INT_MAX;
void c(char board[][10], int th){ // 보드를 기울이는 모든 경우의 수를 계산
    if(th < 11){
        char temp[10][10];
        for(int i = 0; i < 4; i++){ // 0 : 상, 1 : 우, 2 : 하, 3 : 좌
            memcpy(temp, board, sizeof(temp));
            int isEscape = tilt(temp, i);   // 선택된 방향으로 기울임
            if(isEscape == 1) ans = min(ans, th);   // 빨간 구슬만 탈출한 경우
            else if(isEscape == 0) c(temp, th + 1); // 아무 구슬도 탈출하지 못한 경우
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    c(board, 1);
    cout << ((ans == INT_MAX) ? -1 : ans);
}


/*
8 8
########
#......#
#..B...#
#......#
#.O..R.#
#......#
#......#
########

8 8
########
#......#
#......#
#......#
#.O.BR.#
#......#
#......#
########

8 8
########
#......#
#......#
#......#
#.OB#R.#
#......#
#......#
########

8 8
########
#......#
#......#
#......#
#.OR#B.#
#......#
#......#
########

8 8
########
#......#
#......#
#......#
#.O.#B.#
###....#
#R#....#
########

10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#...#.#..#
###.##...#
#O..#....#
##########

10 10
##########
#..R..##B#
#...#.##.#
#####.##.#
#......#.#
#.########
#...#....#
###.##.#.#
#.#....#O#
##########
*/