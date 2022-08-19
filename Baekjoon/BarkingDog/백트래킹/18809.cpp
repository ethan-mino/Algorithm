#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

#define u first
#define dist second
#define pos second

int n, m, g, r; 
int board[50][50];

vector<pair<int, int>> pos; // 배양액을 뿌릴 수 있는 좌표를 저장하는 벡터
int ans = 0; // 피울 수 있는 꽃의 최대 개수

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(vector<pair<int, int>>& gv, vector<pair<int, int>>& rv){
    pair<int, int> vis[50][50];

    queue<pair<int, pair<int, int>>> q; // BFS를 수행하기 위한 queue

    // 초록색 배양액을 queue에 넣고 방문 표시 (초록색 배양액의 고유번호는 1)
    for(auto c : gv) {q.push({1, c});  vis[c.x][c.y].u = 1; vis[c.x][c.y].dist = 1;};  
    // 빨간색 배양액을 queue에 넣고 방문 표시 (빨간색 배양액의 고유번호는 2)
    for(auto c : rv) {q.push({2, c}); vis[c.x][c.y].u = 2; vis[c.x][c.y].dist = 1;};   

    int cnt = 0;    // 피울 수 있는 꽃의 개수

    while(!q.empty()){
        pair<int, pair<int, int>> cur = q.front(); q.pop();
        
        if(vis[cur.pos.x][cur.pos.y].u == 3) continue; // 꽃을 피운 위치는 배양액을 퍼트리지 않기 위함

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.pos.x + dx[dir];
            int ny = cur.pos.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue; // 정원의 인덱스를 벗어나는 경우 
            if(board[nx][ny] == 0) continue;    // 인접한 좌표가 호수인 경우

            if(vis[nx][ny].u == 0){   // 방문하지 않은 경우
                q.push({cur.u, {nx, ny}});
                // 동일한 시간에 도달했는 지 확인하기 위해 방문 표시 배열에 dist도 저장
                vis[nx][ny].dist = vis[cur.pos.x][cur.pos.y].dist + 1;    
                vis[nx][ny].u = cur.u;  // 어떤 배양액으로 부터 퍼진 것인지 표시
            }else if((vis[nx][ny].dist == vis[cur.pos.x][cur.pos.y].dist + 1) && 
            (vis[nx][ny].u == 1 && cur.u == 2 || vis[nx][ny].u == 2 && cur.u == 1)){  
                // 초록색 배양액과 빨간색 배양액이 동일한 시간에 도달한 경우
                vis[nx][ny].u = 3;  // 꽃을 피운 위치는 고유번호 3으로 표시
                cnt++;
            }
        }
    }
    ans = max(ans, cnt);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> g >> r;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> board[i][j]; // 정원 입력 받음
            if(board[i][j] == 2) pos.push_back({i, j}); // 배양액을 뿌릴 수 있는 좌표 저장
        }

    vector<int> pg, pr; // next_permutation을 이용하여 조합을 수행하기 위한 배열
                        // ex. 5C3의 경우 {0, 0, 1, 1, 1}

    for(int i = 0; i < pos.size(); i++){
        if(i < pos.size() - g) pg.push_back(0);
        if(i >= pos.size() - g) pg.push_back(1);
    }

    for(int i = 0; i < pos.size() - g; i++){
        if(i < pos.size() - (g + r)) pr.push_back(0);
        if(i >= pos.size() - (g + r)) pr.push_back(1);
    }

    do{ // 먼저 전체 배양액을 뿌릴 수 있는 땅 중 초록색 배양액을 뿌릴 땅을 선택 (combination)
        vector<pair<int, int>> gv;
        for(int i = 0; i < pos.size(); i++) // 선택된 빨간색 배양액과 그에 해당하는 좌표를 매핑
            if(pg[i] == 1) gv.push_back(pos[i]);    

        do{ // 초록색 배양액을 뿌릴 땅은 제외하고 빨간색 배양액을 뿌릴 땅을 선택한다. (combination)
            vector<pair<int, int>> rv;

            for(int i = 0; i < pr.size(); i++){ // 선택된 초록색 배양액과 그에 해당하는 좌표를 매핑
                if(pr[i] != 1) continue;
                int zero_th = 0;
                
                for(int j = 0; j < pg.size(); j++){
                    if(pg[j] == 0) {
                        zero_th++;
                        if(zero_th == i + 1){
                            rv.push_back(pos[j]);
                        }
                    }
                }
            }
            bfs(gv, rv);    // 선택된 초록색 배양액과 빨간색 배양액의 좌표를 넘겨 BFS를 수행하고, 
                            // 해당 좌표를 선택했을 때, 피울 수 있는 꽃의 최대 개수를 계산한다. 
        }while(next_permutation(pr.begin(), pr.end())); // 각 경우의 수마다 꽃의 개수 계산
    }while(next_permutation(pg.begin(), pg.end()));    // 각 경우의 수마다 꽃의 개수 계산

    cout << ans;
}