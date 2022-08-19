#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[8] = {-1, -1, -2, -2, 1, 1, 2, 2};
int dy[8] = {-2, 2, -1, 1, -2, 2, -1, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    cin >> cnt;

    queue<pair<int, int>> q;

    while(cnt--){
        int vis[300][300] = {};

        int l, x1, y1, x2, y2; // x1, y1은 나이트의 현재 위치, x2, y2는 나이트가 이동하려는 칸

        cin >> l;
        cin >> x1 >> y1 >> x2 >> y2;  
        q.push({x1, y1});
        vis[x1][y1] = 1;

        int ans = 0;

        while(!q.empty()){
            pair<int, int> cur = q.front(); q.pop();
            for(int dir = 0; dir < 8; dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if(nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
                if(vis[nx][ny] != 0) continue;

                vis[nx][ny] = vis[cur.x][cur.y] + 1;

                if(nx == x2 && ny == y2){
                    ans = vis[nx][ny] -1;
                    break;
                }

                q.push({nx, ny});
            }
        }
        cout << ans << "\n";
    }
}