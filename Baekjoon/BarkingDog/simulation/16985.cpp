#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int z, x, y;
}pos;

int dx[6] = {-1, 0, 0, 1, 0, 0};
int dy[6] = {0, -1, 0, 0, 1, 0};
int dz[6] = {0, 0, -1, 0, 0, 1};

vector<vector<vector<int>>>maze(5, vector<vector<int>>(5, vector<int>(5)));
vector<vector<int>> rp;
vector<int> selected(5);
int vis[5][5][5];
int ans = INT_MAX;

void back(int th){
    if(th == 6){
        rp.push_back(selected);
    }else{
        for(int i = 0; i < 4; i++){
            selected[th - 1] = i;
            back(th + 1);
        }
    }
}

void bfs(vector<vector<vector<int>>> &maze, pos start, pos end){
    // 시작 지점과 도착 지점이 참가자가 들어갈 수 없는 칸이라면, bfs를 수행하지 않음
    if(maze[start.z][start.x][start.y] != 1 || maze[end.z][end.x][end.y] != 1) return;  
    
    queue<pos> q;
    fill(&vis[0][0][0], &vis[4][5][5], 0);  // 방문 상태 배열을 0으로 초기화

    // 시작 지점을 큐에 넣고, 방문 표시
    q.push(start);
    vis[start.z][start.x][start.y] = 1; 

    while(!q.empty()){
        pos cur = q.front(); q.pop();

        for(int i = 0; i < 6; i++){
            int nz = cur.z + dz[i];
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if(nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
            if(maze[nz][nx][ny] == 0 || vis[nz][nx][ny] != 0) continue;
            
            q.push({nz, nx, ny});
            vis[nz][nx][ny] = vis[cur.z][cur.x][cur.y] + 1;
        }
    }

    if(vis[end.z][end.x][end.y] != 0) // 탈출이 가능한 경우
        ans = min(ans, vis[end.z][end.x][end.y] - 1);   // 최소 이동 횟수라면 ans 업데이트
}

void rotate(vector<vector<int>>& v, int n){ // 5 * 5 크기의 판을 시계 방향으로 90도 회전시키는 함수 
    for(int a = 0; a < n; a++){
        vector<pair<int, int>> p;

        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                if(v[i][j] != 0)    // 1이 아닌 좌표를 모두 push
                    p.push_back({i, j});

        fill(v.begin(), v.end(), vector<int>(5, 0));
        for(auto t : p) v[t.second][4 - (t.first)] = 1; // 회전시킨 좌표에 1을 저장
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int order[5] = {0, 1, 2, 3, 4};

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 5; k++) // 각 판을 입력 받아 3차원 벡터에 저장
                cin >> maze[i][j][k];
    
    back(1);    // 각 판의 회전 경우의 수를 계산
    
    vector<vector<vector<int>>>temp1(5, vector<vector<int>>(5, vector<int>(5)));
    vector<vector<vector<int>>>temp2(5, vector<vector<int>>(5, vector<int>(5)));

    for(auto r : rp){   // 각 회전 경우의 수에 대해 반복하며, 미로를 탈출하기 위한 이동횟수를 계산한다.
        copy(maze.begin(), maze.end(), temp1.begin());  // maze의 바뀌지 않도록 임시 벡터에 저장

        for(int i = 0; i < 5; i++)
            rotate(temp1[i], r[i]); // 회전 경우의 수에 따라 각 판을 회전

        do{
            for(int j = 0; j < 5; j++)  // 현재 순서에 따라 판을 쌓음
                temp2[j] = temp1[order[j]];

            bfs(temp2, {0, 0, 0}, {4, 4, 4});   // bfs를 수행하여 미로를 탈출하기 위한 이동횟수를 계산
        }while(next_permutation(order, order + 5)); // 각 판을 쌓는 경우의 수에 대해 반복
    }

    if(ans == INT_MAX) cout << - 1;
    else cout << ans;
}