#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n, m, ans = INT_MIN;
int board[8][8];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int bfs(int board[][8], vector<pair<int, int>> virus){
    int vis[8][8];
    fill(&vis[0][0], &vis[7][8], 0);

    queue<pair<int, int>> q;
    for(auto v : virus){    // 바이러스의 좌표를 모두 queue에 넣어줌
        q.push(v);
        vis[v.x][v.y] = 1;
    }

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] != 0 || vis[nx][ny] != 0) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            // 바이러스가 퍼지지 않았고, 빈 칸인 경우 count
            if(vis[i][j] == 0 && board[i][j] == 0) cnt++;

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<pair<int, int>> empty;       // 빈 칸의 좌표
    vector<pair<int, int>> virus;       // 바이러스의 좌표
    
    for(int i =0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) virus.push_back({i, j});   // 바이러스의 좌표 push
            else if(board[i][j] == 0) empty.push_back({i, j});  // 빈 칸의 좌표 push
        }
    
    vector<int> np; // combination을 위한 벡터
    for(int i = 0; i < empty.size() - 3; i++) np.push_back(0);  // 빈 칸의 개수 - 3개의 0을 push
    for(int i = 0; i < 3; i++) np.push_back(1); // 1 3개 push(세우려는 벽의 개수)

    do{
        int temp[8][8]; // 벽을 추가로 세운 연구소
        memcpy(temp, board, sizeof(temp));  
        for(int i = 0; i < np.size(); i++)
            if(np[i] == 1) temp[empty[i].x][empty[i].y] = 1;    // 벽을 새로 세울 위치에 1을 저장 
        ans = max(ans, bfs(temp, virus));   // BFS 수행
    }while(next_permutation(np.begin(), np.end())); // 각각의 경우의 수에 대해 반복하며 BFS를 수행

    cout << ans;
}