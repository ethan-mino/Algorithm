#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void curve(pair<int, int> s, int dir, int g){
    vector<int> dirs; dirs.push_back(dir);  // 시작 방향을 push
    pair<int, int> cur = {s.x + dx[dir], s.y + dy[dir]};    // 1세대의 끝 점을 시작점으로 잡음
    board[s.x][s.y] = 1; board[cur.x][cur.y] = 1; // 0세대의 좌표를 배열에 1로 표시

    for(int i = 0; i < g; i++){
        int size = dirs.size(); // i 세대의 방향 수

        for(int j = size - 1; j >= 0; j--){ // i 세대의 방향의 순서를 역순으로 한 후, 각 방향에 1을 더해주고, mod 4 연산 
            dirs.push_back((dirs[j] + 1) % 4);  // 다음 세대의 방향을 push
            cur = {cur.x + dx[(dirs[j] + 1) % 4], cur.y + dy[(dirs[j] + 1) % 4]};
            if(cur.x >= 0 && cur.x <= 100 && cur.y >= 0 && cur.y <= 100)    // 0 ~ 100만 유효한 좌표
                board[cur.x][cur.y] = 1;    // 해당 좌표가 드래곤 커브의 일부임을 표시
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    while(n--){
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        curve({x, y}, d, g);    // 시작점, 시작 방향, 세대를 파라미터로 전달한 후, 드래곤 커브의 좌표를 배열에 표시한다.
    }

    int ans = 0;
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)    // 네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수를 구한다.
            if(board[i][j] && board[i + 1][j] // 네 꼭짓점이 모두 1인 경우 ans 값 증가
            && board[i][j + 1] && board[i + 1][j + 1]) ans++;

    cout << ans;
}

/*
1
0 0 0 0

1
0 0 0 1

1
3 3 0 1
*/