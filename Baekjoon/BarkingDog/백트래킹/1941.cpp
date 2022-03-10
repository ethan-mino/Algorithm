#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

char seat[5][5];
bool vis[5][5];

int dx[4] = {-1, 1, 0, 0};  // 상, 하, 좌, 우
int dy[4] = {0, 0, -1, 1};
pair<int, int> selected[7];
vector<int> road[14] = {{0}, {1}, {2}, {3},
                        {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3},
                        {0, 1, 2}, {0, 1, 3}, {1, 2, 3}, 
                        {0, 1, 2, 3}};

long long ans = 0;
void princess(pair<int, int> start, int th){
    vis[start.x][start.y] = true;
    selected[th - 1] = {start.x, start.y}; // seat[start.x][start.y];

    int cnt = 0;
    if(th == 7){
        for(int i = 0; i < 7; i++){
            if(seat[selected[i].x][selected[i].y] == 'S') cnt++;
        }

        if(cnt >= 4) {
            for(int i = 0; i < 7; i++)
                cout << "(" << selected[i].x << ", " << selected[i].y << ")" << " ";
                //cout << selected[i] << " ";

            cout << "\n";
            ans++;
        }
    }else{
        for(int i = 0; i < 7; i++){
            if(seat[selected[i].x][selected[i].y] == 'S') cnt++;
        }
        // th명을 선택한 상태. 4-cnt

        if(7 - th >= 4 - cnt){
            for(int i = 0; i < 14; i++){
                int t = th;
                for(auto idx : road[i]){
                    int nx = start.x + dx[idx];
                    int ny = start.y + dy[idx];
                    
                    if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                    if(vis[nx][ny] || t > 6) continue;
                    
                    vis[nx][ny] = true; 
                    princess({nx, ny}, ++t); 
                    vis[nx][ny] = false;
                }
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++){
        string s; cin >> s;
        for(int j = 0; j < 5; j++)
            seat[i][j] = s[j];
    }
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            fill(&vis[0][0], &vis[4][5], 0);
            //cout << "(" << i << ", " << j << ")" << "\n";
            princess({i, j}, 1);
        }
    }

    cout << ans / 2;
}
