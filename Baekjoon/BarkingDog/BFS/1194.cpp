// Created by 길민호 on 2022/08/10.

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

char board[100][100];
int vis[100][100][65];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

// st는 시작 지점
// distInit는 앞서 이동한 거리
// keys는 현재 갖고 있는 키를 나타내는 이진수
void bfs(pair<int, int> st, int distInit, int keys){
    queue<pair<int, int>> q;
    q.push(st);
    vis[st.x][st.y][keys] = distInit + 1;   // 방문 표시 배열에 시작점을 (앞서 이동한 거리 + 1)로 설정

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;    // 미로를 벗어나는 경우
            char c = board[nx][ny]; // 다음에 이동할 곳의 문자
            if(c == '#') continue; // 벽인 경우

            if((c >= 'A' && c <= 'Z')){ // 문인 경우
                int key = c - 'A';  // 해당 문을 여는 키를 나타내는 비트의 위치
                if(keys & (1 << key)){ // 비트마스킹으로 열쇠를 가지고 있는지 확인
                    // 현재 keys 상태로 아직 방문한 적이 없거나
                    // 이전에 keys 상태에서 (nx, ny)로 이동한 것 보다, 현재 위치에서 방문하는 것이 더 최단거리인 경우
                    // 문을 열고 이동해봄
                    if(vis[nx][ny][keys] == 0 ||
                       vis[nx][ny][keys] > vis[cur.x][cur.y][keys] + 1){
                        board[nx][ny] = '.';    // 문을 빈 공간으로 만듦
                        // (nx, ny)가 시작점, keys는 그대로, distInit은 현재까지 이동한 거리
                        bfs({nx, ny}, vis[cur.x][cur.y][keys], keys);
                        board[nx][ny] = c;  // 문을 원래 상태로 복구
                    }
                }
            }else if(c >= 'a' && c <= 'z'){   // 열쇠인 경우
                int key = c - 'a';  // 해당 열쇠를 갖고 있는지 나타내는 bit의 위치
                int addKey = keys | (1 << key); // or 연산을 통해 keys에 현재 위치에 놓인 키를 추가
                // addKey 상태로 아직 방문한 적이 없거나
                // 이전에 addKey 상태에서 (nx, ny)로 이동한 것 보다, 현재 위치에서 방문하는 것이 더 최단거리인 경우
                // 키를 습득하고 이동
                if(vis[nx][ny][addKey] == 0 ||
                   vis[nx][ny][addKey] > vis[cur.x][cur.y][keys] + 1){
                    // (nx, ny)가 시작점, keys는 현재 위치에 놓인 키를 추가한 이진수, distInit은 현재까지 이동한 거리
                    bfs({nx, ny}, vis[cur.x][cur.y][keys], addKey);
                }
            }else{  // 빈 칸인 경우
                // keys 상태로 방문하지 않은 경우,
                // 현재 상태에서 (nx, ny) 위치로 이동하는 것이 더 최단거리인 경우
                // (nx, ny) 위치로 이동
                if(vis[nx][ny][keys] == 0
                   || vis[nx][ny][keys] > vis[cur.x][cur.y][keys] + 1){
                    q.push({nx, ny});
                    vis[nx][ny][keys] = vis[cur.x][cur.y][keys] + 1;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    pair<int, int> st;  // 민식이의 위치

    for(int i = 0; i < n; i++){ // 미로 입력 받음
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == '0') st = {i, j}; // 민식이의 위치 저장
        }
    }

    // BFS를 수행하며, 미로를 탈출하는데 드는 최소 이동횟수를 계산
    bfs(st, 0, 0); // 아직 이동하지 않았으므로, distInit은 0으로 설정

    int ans = INT_MAX;
    for(int i = 0; i < n; i++){ // 도착 가능한 탈출구 중에서 가장 최단 거리를 출력
        for(int j = 0; j < m; j++){
            if(board[i][j] == '1'){
                for(int k = 0; k < 64; k++){
                    if(vis[i][j][k] != 0){
                        ans = min(ans, vis[i][j][k] - 1);
                    }
                }
            }
        }
    }

    if(ans == INT_MAX) ans = -1;
    cout << ans << "\n";
}

/*
5 5
....1
#1##A
.1.#a
....0
.1.#.
-> 3
*/