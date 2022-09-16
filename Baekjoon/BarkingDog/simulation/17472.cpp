// Created by 길민호 on 2022/08/31.

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n, m;
int islandNum = 0;  // * 섬의 개수
int ans = INT_MAX;
int board[10][10];
int vis[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<pair<int, int>> poses;

// x의 root를 반환하는 함수
int find(int x, vector<int>& p){
    if(p[x] == - 1) return x;
    else return p[x] = find(p[x], p);
}

// * u, v가 같은 집합인지를 반환하는 함수 (union)
bool isDiff(int u, int v, vector<int>& p){
    u = find(u, p); v = find(v, p);
    if(u == v) return false;    // * root가 같으면 false 반환
    if(u < v) p[v] = u; // * 번호가 더 작은 노드에 union
    else p[u] = v;
    return true;
}

// * 모든 섬이 연결되었는지 반환하는 함수
bool isAllConn(vector<int>& p){
    int setCnt = 0;
    for(int i = 0; i < islandNum; i++)  // * root의 개수를 셈
        if(p[i] < 0) setCnt++;
    return setCnt == 1 ? true : false;  // * root의 개수가 1이면 true를 반환
}

// * 각 섬의 좌표를 반환하는 함수
vector<pair<int, int>> bfs(pair<int, int> st, int v){
    vector<pair<int, int>> poses = {st};
    queue<pair<int, int>> q;
    q.push(st);
    vis[st.x][st.y] = 1;
    board[st.x][st.y] = v;

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] == 0) continue;

            q.push({nx, ny});
            poses.push_back({nx, ny});
            vis[nx][ny] = 1;
            // * 각 섬에 서로 다른 번호를 할당시키고, 이를 이용하여 서로 다른 섬임을 확인
            board[nx][ny] = v;
        }
    }

    return poses;
}

// * cnt는 놓은 다리의 개수, lenSum : 연결된 다리의 총 길이
// * p는 union에 필요한 parent 벡터
void back(int th, int cnt, int lenSum, vector<int> p){
    if(cnt == islandNum - 1){   // * 섬의 개수 - 1개의 다리가 만들어진 경우
        if(isAllConn(p)) ans = min(ans, lenSum);
    }else if(th < poses.size() && cnt < islandNum - 1 && !isAllConn(p)){
        // * 각 좌표의 4방향에 대해 다리를 만들어 다른 섬에 연결할 수 있는 지 홗인
        // * 만들 수 있다면, 이미 두 섬이 연결되었는 지 확인, 연결되어 있지 않으면 다리를 만듦.
        pair<int, int> pos = poses[th];
        for(int dir = 0; dir < 4; dir++){
            pair<int, int> cur = poses[th];
            while(true){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                // 지도를 벗어나는 경우 break;
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                // 같은 섬인 경우 break;
                if(board[nx][ny] != 0 && board[nx][ny] == board[pos.x][pos.y]) break;
                // 다른 섬인 경우
                if(board[nx][ny] != 0 && board[nx][ny] != board[pos.x][pos.y]){
                    int curLen = max(abs(nx - pos.x), abs(ny - pos.y)) - 1; // 다리의 길이
                    // ! 다리의 길이는 2 이상이어야 한다.
                    if(curLen >= 2){
                        vector<int> tempP(6, -1);
                        copy(p.begin(), p.end(), tempP.begin());
                        bool notConn = isDiff(board[pos.x][pos.y] - 1, board[nx][ny] - 1, tempP);

                        // * 두 섬이 연결되지 않은 경우에만 다리를 설치함
                        if(notConn) back(th + 1, cnt + 1, lenSum + curLen, tempP);
                    }
                    break;
                }
                cur = {nx, ny};
            }
        }

        back(th + 1, cnt, lenSum, p);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    fill(&vis[0][0], &vis[9][10], 0);

    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] == 0 && board[i][j] != 0){
                islandNum++;
                vector<pair<int, int>> pos = bfs({i, j}, islandNum);
                // * 각 섬에 포함된 좌표를 poses에 저장
                poses.insert(poses.end(), pos.begin(), pos.end());
            }
        }
    }

    vector<int> p(6, -1);
    back(0, 0, 0, p);

    if(ans == INT_MAX) cout << -1;
    else cout << ans;
}