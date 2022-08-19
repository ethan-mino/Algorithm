#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[502][502];
int vis[502][502];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)  // 그림 입력 받음
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    queue<pair<int, int>> q;    

    int p = 0;  // 그림의 개수
    int max = 0;    // 가장 넓은 그림의 넓이

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){ // 도화지를 순회
            int width = 0;  // 그림의 넓이

            if(vis[i][j] == 0 && board[i][j] == 1){ // 이미 그림으로 처리된 부분이 아니라면
                vis[i][j] = 1;  // 방문 표시하고 BFS 
                width++;
                q.push({i, j});
                p++;

                while(!q.empty()){
                    pair<int, int> cur = q.front(); q.pop();

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(board[nx][ny] != 1 || vis[nx][ny] == 1) continue;

                        vis[nx][ny] = 1;
                        width++;

                        q.push({nx, ny});
                    }
                }
            }

            if(max < width)
                max = width;
        }
    }

    cout << p << "\n";  
    cout << max << "\n";
}