#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[100][100];
int vis[100][100];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k;
    cin >> n >> m >> k;

    int cnt = 0;
    vector<int> v;

    while(k--){ 
        int pos[4];

        for(int i = 0; i < 4; i++) // 각 직사각형 입력 받음
            cin >> pos[i];

        for(int i = n - pos[3]; i < n - pos[1]; i++)    // 직사각형 부분을 1로 표시
            for(int j = pos[0]; j < pos[2]; j++)
                board[i][j] = 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0;  j < m; j++){
            if(board[i][j] == 0 && vis[i][j] == 0){

                queue<pair<int, int>> q;
                cnt++;  //   영역의 개수
                vis[i][j] =1;
                q.push({i, j});

                int area = 0;   // 각 영역의 넓이

                while(!q.empty()){
                    pair<int, int> cur = q.front(); q.pop();
                    area++;

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];

                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(board[nx][ny] == 1 || vis[nx][ny] == 1) continue;    // 직사각형 외 부분을 탐색

                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                v.push_back(area);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << cnt << "\n";    // 영역의 개수 출력
    for(auto c : v) cout << c << " ";   // 각 영역의 넓이 출력  
}