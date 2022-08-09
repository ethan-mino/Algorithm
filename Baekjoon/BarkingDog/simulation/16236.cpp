#include <bits/stdc++.h>
using namespace std;

typedef struct{int x, y;}pos;   // 좌표에 대한 구조체
typedef struct{pos p; int size, num;}shark; // 상어에 대한 구조체 (size : 상어의 크기, num : 현재 크기에서 잡아먹은 물고기 수)
typedef struct{pos p; int dist;}fish;   // 물고기에 대한 구조체 (dist : 상어로부터의 거리)

int board[20][20], vis[20][20];
int n;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool cmp(fish f1, fish f2){ // 잡아먹을 수 있는 물고기를 정렬하기 위한 기준 함수
    if(f1.dist == f2.dist){
        if(f1.p.x == f2.p.x){ return f1.p.y < f2.p.y;
        }else return f1.p.x < f2.p.x;
    }else return f1.dist < f2.dist;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    shark s;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> board[i][j]; // 공간 입력 받음
            if(board[i][j] == 9) s = {i, j, 2, 0};  // 상어의 위치, 크기, 잡아먹은 물고기 수 저장
        }
            
    int ans = 0;    // 도움을 요청하지 않고 물고기를 잡아먹을 수 있는 시간
    while(true){
        fill(&vis[0][0], &vis[19][20], 0);  // 방문 표시 배열 0으로 초기화
        queue<pos> q;
        vector<fish> fishes;    // 잡아먹을 수 있는 물고기들을 저장하는 벡터
        q.push({s.p.x, s.p.y}); // 상어의 위치가 BFS의 시적점
        vis[s.p.x][s.p.y] = 1;  // 상어의 위치 방문 표시

        while(!q.empty()){
            pos cur = q.front(); q.pop();

            for(int dir = 0; dir < 4; dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(board[nx][ny] > s.size || vis[nx][ny] != 0) continue;
                q.push({nx, ny});
                vis[nx][ny] = vis[cur.x][cur.y] + 1;    // 거리 저장
                
                if(board[nx][ny] != 0 && board[nx][ny] < s.size)    // 상어보다 크기가 작은 물고기가 있는 칸이라면
                    fishes.push_back({{nx, ny}, vis[nx][ny]});  // 해당 물고기의 정보 push
            }
        }

        if(fishes.size() == 0){ // 잡아먹을 수 있는 물고기가 없는 경우 종료
            break;
        }else{  // 잡아먹을 수 있는 물고기가 존재하는 경우
            sort(fishes.begin(), fishes.end(), cmp);    // 거리, 위치에 따라 정렬
            fish f = fishes[0]; // 거리가 가장 가깝고, 가장 위, 가장 왼쪽에 있는 물고기를 선택

            ans += vis[f.p.x][f.p.y] - 1;   // 시간 증가
            board[s.p.x][s.p.y] = 0;    // 기존 상어의 위치를 0으로 만듦.
            s.p = f.p; s.num++; // 상어의 위치를 옮김, 상어가 잡아먹은 물고기 수 증가
            board[s.p.x][s.p.y] = 9;    // 물고기의 기존 위치를 9로 만듦.
            if(s.num == s.size){    // 상어의 크기와 같은 수의 물고기를 먹은 경우
                s.num = 0;  // 물고기의 개수를 줄이고 상어의 크기를 늘려줌
                s.size++;
            }
        }
    }
    cout << ans;
}