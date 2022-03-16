#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

char board[12][6];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int ans = 0;

void drop(){
    for(int i = 0; i < 6; i++){
        pair<int, int> cur = {11, i};
        queue<pair<int, int>> empty;

        while(true){
            if(cur.x < 0) break;

            pair<int, int> nx = {cur.x - 1, cur.y};
            
            if(board[cur.x][cur.y] == '.'){
                empty.push({cur.x, cur.y});
            }else{
                if(!empty.empty()){
                    pair<int, int> p = empty.front(); empty.pop();
                    board[p.x][p.y] = board[cur.x][cur.y];
                    board[cur.x][cur.y] = '.'; empty.push({cur.x, cur.y});
                }
            }
            cur = nx;
        }
    }
}

vector<vector<pair<int, int>>> chain(){
    int vis[12][6];
    fill(&vis[0][0], &vis[11][6], 0);
    vector<vector<pair<int, int>>> cluster;

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            vector<pair<int, int>> c;
            
            if(board[i][j] != '.'){
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;

                while(!q.empty()){
                    pair<int, int> cur = q.front(); q.pop();
                    c.push_back(cur);

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];

                        if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
                        if(board[nx][ny] != board[cur.x][cur.y] || board[nx][ny] == '.' || vis[nx][ny] == 1) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
                if(c.size() >= 4) cluster.push_back(c);
            }
        }
    }

    return cluster;
}

void game(){
    while(true){
        vector<vector<pair<int, int>>> cluster = chain();

        if(cluster.empty()) break;

        for(auto c : cluster)
            for(auto p : c) 
            board[p.x][p.y] = '.';
        
        ans++;
        drop();
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 12; i++){
        string str; cin >> str;
        for(int j = 0; j < str.size(); j++)
            board[i][j] = str[j];
    }

    game();
    cout << ans;
}

/*
..RR..
..RR..
..GG..
..GG..
..PP..
..PP..
..YY..
..YY..
..BB..
..BB..
..GG..
..GG..
*/