#include <bits/stdc++.h>
using namespace std;

#define v first
#define angle second

#define x first
#define y second

int n, m; 
int board[8][8];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int direction(pair<int, int> pos, int angle, bool flag){
    int cnt = 0;
    int l = (angle == 0 || angle == 2) ? m : n;
    for(int i = 1 ; i < l; i++){
        int nx = pos.x + dx[angle] * i;
        int ny = pos.y + dy[angle] * i;
        if(nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == 6) break;
        if(board[nx][ny] == 0) {cnt++; if(flag) board[nx][ny] = 7;};
    }

    return cnt;
}

int area(pair<int, int> pos, int angle, bool flag){    // cctv의 감시 영역의 개수를 출력하는 함수
    int u = board[pos.x][pos.y];  // cctv 번호
    //cout << "angle : " << angle << "\n";
    vector<vector<vector<int>>> v = {
        {{0}, {1}, {2}, {3}}, 
        {{0, 2}, {1, 3}, {0, 2}, {1, 3}}, 
        {{3, 0}, {0, 1}, {1, 2}, {2, 3}},
        {{0, 2, 3}, {0, 1, 3}, {0, 1, 2}, {1, 2, 3}}, 
        {{0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}}
    };

    int cnt = 0;
    for(auto c : v[u - 1][angle]){
        //cout << c << " ";
        cnt += direction(pos, c, flag);
    }
    //cout << "\n";

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    vector<int> v = {5, 4, 2, 3, 1};
    for(auto a : v){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == a){
                    pair<int, int> max = {-1, 0};
                    for(int k = 0; k < 4; k++){
                        int cnt = area({i, j}, k, false);
                        if(cnt > max.v) {max.v = cnt; max.angle = k;} 
                    }
                    area({i, j}, max.angle, true);
                }
            }
        }
    }

    int ans = 0;
    //cout << "\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //cout << board[i][j] << " ";
            if(board[i][j] == 0) ans++;
        }
        //cout << "\n";
    }

    cout << ans;
}

/*
6 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 5 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

4 5
0 0 2 0 3
0 6 0 0 0
0 0 6 6 0
0 0 0 0 0

1 7
0 0 0 5 0 0 0

7 1
0
0
0
5
0
0
0

4 6
0 0 0 0 0 0
0 0 0 6 0 0
0 0 0 5 6 0
0 0 0 6 0 0

4 6
0 0 0 0 0 0
0 0 6 2 0 0
0 0 0 0 0 0
0 0 0 0 0 0

4 6
0 0 0 0 0 0
0 0 6 2 0 0
0 0 0 0 0 0
0 0 0 0 0 0

4 6
0 0 0 0 0 0
0 0 0 0 0 0
0 1 0 5 0 0
0 0 0 0 0 0

7 8
0 0 0 0 0 0 0 0 
0 6 0 0 0 0 0 0 
0 2 0 0 4 0 0 0
0 6 0 0 0 0 0 0 
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
*/