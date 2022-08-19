#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[50][50];  // 각국의 인구를 저장하는 배열
int vis[50][50];    // 방문 표시 배열

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, l, r;
    cin >> n >> l >> r;

    for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++)
            cin >> board[i][j]; // 인구 입력 받음

    int ans = 0;    // 인구 이동 발생 일수
    while(true){
        vector<vector<pair<int, int>>> as;  // 연합의 좌표
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                fill(&vis[0][0], &vis[49][50], 0);

                vector<pair<int, int>> a;   // 연합의 좌표
                queue<pair<int, int>> q;   
                q.push({i, j}); 
                vis[i][j] = 1;

                while(!q.empty()){
                    pair<int, int> cur = q.front(); q.pop();
                    a.push_back(cur);

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];

                        if(nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny] != 0) continue;
                        if(abs(board[nx][ny] - board[cur.x][cur.y]) < l
                        || abs(board[nx][ny] - board[cur.x][cur.y]) > r) continue;
                        // 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
                if(a.size() > 1) as.push_back(a);   // 국경선을 공유하는 나라가 2 이상이라면
            }
        }
        
        if(as.size() == 0) break;   // 둘 이상의 나라로 구성된 연합이 존재하지 않는다면 인구 이동 종료
        else{    // 둘 이상의 나라로 구성된 연합이 존재한다면
            ans++;
            for(auto p : as){   // 각 연합에 대해 반복
                int t = 0;
                // 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)
                for(auto na : p) t += board[na.x][na.y];    
                for(auto na : p) board[na.x][na.y] = t/p.size();
            }
        }
    }
    cout << ans;
}
