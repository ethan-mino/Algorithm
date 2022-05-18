#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

string board[11][11];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int n, m, k; 

typedef struct{
    int x, y;
    string str;
}pos;

long long bfs(string target){
    long long ans = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j][0] == target[0]){
                queue<pos> q;
                q.push({i, j, board[i][j]});
                
                if(board[i][j] == target) ans++;
                while(!q.empty()){
                    pos cur = q.front(); q.pop();
                    for(int dir = 0; dir < 8; dir++){
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];

                        if(nx == -1) nx = n - 1;
                        if(ny == -1) ny = m - 1;
                        if(nx == n) nx = 0;
                        if(ny == m) ny = 0;
                        
                        if(target[cur.str.size()] == board[nx][ny][0]){
                            string concat = cur.str + board[nx][ny];
                            //cout << concat << "\n";
                            if(concat == target) ans++;
                            if(concat.size() < target.size()) q.push({nx, ny, concat});
                        }
                    }
                }
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        for(int j = 0; j < m; j++)
            board[i][j] = str[j];
    }
        
    map<string, long long> d;
    for(int i = 0; i < k; i++){
        string str; cin >> str;
        int cnt;

        if(d.find(str) == d.end()) {
            cnt = bfs(str);
            d[str] = cnt;
            reverse(str.begin(), str.end());
            d[str] = cnt;
        }
        else cnt = d[str];
        cout << cnt << "\n";
    }
}   
/*
3 4 3
abcb
bcaa
abac
a
b
c
->  5 4 3
*/