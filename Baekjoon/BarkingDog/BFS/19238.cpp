// Created by 길민호 on 2022/08/05.

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define dist first
#define pa second
#define st first
#define en second
#define INF 10000
typedef pair<int, int> pii;
int n, m, f;

int board[30][30];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void printArr(int arr[30][30]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int bfs(pii start, pii end){
    int vis[30][30];
    fill(&vis[0][0], &vis[29][30], INF);

    queue<pii> q;
    start.x--; start.y--;
    end.x--; end.y--;

    q.push(start);
    vis[start.x][start.y] = 1;

    while(!q.empty()){
        pii cur = q.front(); q.pop();

        for(int dir =0 ; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(board[nx][ny] == 1 || vis[nx][ny] != INF) continue;

            q.push({nx, ny});
            vis[nx][ny] = vis[cur.x][cur.y] + 1;
        }
    }

    if(vis[end.x][end.y] == INF) return INF;
    return vis[end.x][end.y] - 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> f;

    for(int i =0; i < n; i++)
        for(int j =0 ; j < n; j++)
            cin >> board[i][j];
    pair<int, int> t;
    cin >> t.x >> t.y;

    vector<pair<pair<int, int>, pair<int, int>>> pos;
    for(int i = 0; i < m; i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        pos.push_back({{x1, y1}, {x2, y2}});
    }

    sort(pos.begin(), pos.end());

    bool s = true;
    vector<bool> b(m + 1);

    for(int cur = 0; cur < m; cur++){
        priority_queue<pair<int, int>,
                vector<pair<int, int>>, greater<>> q;

        for(int p = 0; p < m; p++){
            if(!b[p]) q.push({bfs(t, pos[p].st), p});
        }

        // 주의할 점 (먼 위치의 경우
        pii nearest = q.top(); q.pop();   // {가장 가까운 승객의 거리, 승객 번호}
        int toP = nearest.dist;  // 택시의 위치로부터 승객까지의 거리

        if(toP == INF || toP > f) {
            s = false;
            break;
        }

        f -= toP;
        int toD = bfs(pos[nearest.pa].st, pos[nearest.pa].en);    // 승객의 위치로부터 도착지까지의 거리
        if(toD == INF || toD > f) {
            s = false;
            break;
        }else {
            f += toD;
        }

        b[nearest.pa] = true;
        t = pos[nearest.pa].en;
    }

    if(s) cout << f << "\n";
    else cout << -1 << "\n";
}
