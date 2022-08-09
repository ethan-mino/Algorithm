#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

char board[12][6];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int ans = 0;

void drop(){    // 뿌요들을 아래로 내리는 함수
    for(int i = 0; i < 6; i++){ // 각 열에 대해 반복
        pair<int, int> cur = {11, i};   // 현재 확인하려는 좌표 (시작점은 열의 가장 아래 좌표)
        queue<pair<int, int>> empty;    // 빈 곳의 좌표를 저장하는 queue

        while(true){ 
            if(cur.x < 0) break;
            
            if(board[cur.x][cur.y] == '.'){ // 현재 좌표가 빈 곳이라면, queue에 삽입
                empty.push({cur.x, cur.y});
            }else{  // 빈 곳이 아니라면
                // 빈 곳이 있다면, 가장 아래의 빈 곳에 이동시키고, 기존 자리는 빈 곳으로 처리
                if(!empty.empty()){ 
                    pair<int, int> p = empty.front(); empty.pop();  
                    board[p.x][p.y] = board[cur.x][cur.y];
                    board[cur.x][cur.y] = '.'; empty.push({cur.x, cur.y});
                }
                // 빈 곳이 없다면, 이동하지 않음
            }
            cur = {cur.x - 1, cur.y};   // 한 칸 위의 좌표로 이동
        }
    }
}

vector<vector<pair<int, int>>> chain(){ // 4개 이상의 푸요가 연결되어 있는 좌표를 반환하는 함수
    int vis[12][6];
    fill(&vis[0][0], &vis[11][6], 0);

    vector<vector<pair<int, int>>> cluster;

    for(int i = 0; i < 12; i++){    // 필드 각각의 좌표에 대해 반복
        for(int j = 0; j < 6; j++){
            vector<pair<int, int>> c;
            
            if(board[i][j] != '.'){ // 빈 곳이 아니라면 해당 지점부터 BFS 수행
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
                        if(vis[nx][ny] == 1) continue;  // 이미 방문한 경우, 다시 방문하지 않음
                        // 인접한 좌표가 같은 색의 푸요가 아니거나, 현재 좌표가 빈 곳이라면 방문하지 않음
                        if(board[nx][ny] != board[cur.x][cur.y] || board[nx][ny] == '.') 
                            continue;  

                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
                if(c.size() >= 4) cluster.push_back(c); // 4개 이상의 푸요가 연결된 경우만 삽입
            }
        }
    }
    return cluster;
}

void game(){
    while(true){
        vector<vector<pair<int, int>>> cluster = chain();
        if(cluster.empty()) break;  // 4개 이상 연결된 푸요가 없다면 종료
        for(auto c : cluster)   // 4개 이상으로 구성된 각각의 연결에 대해
            for(auto p : c) 
                board[p.x][p.y] = '.';  // 빈 곳으로 만듦.
        
        ans++;  // 연쇄 증가
        drop();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 12; i++){    // 필드 입력 받음
        string str; cin >> str;
        for(int j = 0; j < str.size(); j++)
            board[i][j] = str[j];
    }

    game(); // 게임 수행
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