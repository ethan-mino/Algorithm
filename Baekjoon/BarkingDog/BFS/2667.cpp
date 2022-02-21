#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[25][25];
int vis[25][25];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i =0 ; i < n; i++){
        string str;
        cin >> str;

        for(int j = 0; j < n; j++)
            board[i][j] = str[j] - 48;
    }

    queue<pair<int, int>> q;

    int cnt = 0;    //   단지의 개수
    vector<int> v;  

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            if(board[i][j] == 1 && vis[i][j] == 0){
                q.push({i, j});
                vis[i][j] = 1;
                cnt++;
                int area = 0;

                while(!q.empty()){
                    pair<int, int> cur = q.front(); q.pop();
                    area++;

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];

                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny] != 0) continue;
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }

                v.push_back(area);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << cnt << "\n";
    for(auto c : v) cout << c << "\n";
}