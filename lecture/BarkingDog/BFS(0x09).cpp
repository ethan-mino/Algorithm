#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[502][502]; // 노드 배열
bool vis[502][502]; // 방문 여부 배열 (1이면 방문)
int n = 7; int m = 10;  // 행과 열 크기

int dx[4] = {-1, 0, 1, 0}; // dx, dy는 상하좌우를 처리하기 위한 배열   
int dy[4] = {0, 1, 0, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int> > q;
    vis[0][0] = 1;  // 시작 지점에 방문 표시
    q.push({0, 0});

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        cout << "(" << cur.x << ", " << cur.y << ") -> ";

        for(int dir =0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.x + dy[dir];

            if(nx <0 || nx >= n || ny < 0 || ny >= m) continue;  // 배열의 크기를 넘어가는지 확인
            if(vis[nx][ny || board[nx][ny] != 1]) continue; // 노드가 아니거나, 이미 방문했는지 확인
            vis[nx][ny] = 1;    // 큐에 넣을 때 방문 표시
            q.push({nx, ny});
        }
    }
}