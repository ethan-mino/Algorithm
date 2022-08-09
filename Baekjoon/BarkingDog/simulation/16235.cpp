#include <bits/stdc++.h>
using namespace std;

#define num first
#define age second

#define pos first
#define v second
#define x first
#define y second

int board[10][10], f[10][10];
int n, m, k;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            board[i][j] = 5;
            cin >> f[i][j];
        }

    list<pair<int, int>> trees[10][10];
    for(int i = 0; i < m; i++){
        int x, y, z; cin >> x >> y >> z;
        trees[x - 1][y - 1].push_back({1, z});  
    }
    
    int y = 0, ans = m;
    while(y < k){
        vector<pair<pair<int, int>, int>> deads; //  봄에 죽은 나무
        
        for(int i = 0; i < n; i++){  // 봄
            for(int j = 0; j < n; j++){
                for(auto iter = trees[i][j].begin(); iter != trees[i][j].end();){
                    int v = (*iter).num * (*iter).age;
                    if(v > board[i][j]){    // 해당 age에 양분을 먹지 못하고 죽는 나무가 있는 경우
                        pair<int, int> dead = *iter;
                        while(v > board[i][j]){ // 양분이 충분할 때까지 나무의 개수를 줄임
                            (*iter).num--; ans--;
                            v = (*iter).num * (*iter).age;
                        }

                        deads.push_back({{i, j}, (dead.num - (*iter).num) * ((*iter).age / 2)});    // 죽은 나무는 deads 벡터에 추가
                    }

                    if((*iter).num == 0) iter = trees[i][j].erase(iter);    // 남아있는 나무가 없는 경우 제거
                    else {  // 남아있는 나무가 있는 경우
                        (*iter).age++; // age 증가
                        board[i][j] -= v;   // 남아있는 나무의 개수 * 나무의 나이만큼 해당 칸의 양분을 감소시킨다.
                        iter++;
                    }
                }
            }
        }

        for(auto d : deads) board[d.pos.x][d.pos.y] += d.v; //  여름, 죽은 나무마다 나이를 2로 나눈 값을 칸에 양분으로 추가

        for(int i = 0; i < n; i++){  // 가을
            for(int j = 0; j < n; j++){
                for(auto iter = trees[i][j].begin(); iter != trees[i][j].end(); iter++){
                    if(((*iter).age) % 5 == 0){ // 가을, 나무의 나이가 5의 배수인 경우
                        for(int dir = 0; dir < 8; dir++){   // 인접한 8개의 칸에 각각 남아있는 칸의 개수만큼 age가 1인 나무를 추가
                            int nx = i + dx[dir];
                            int ny = j + dy[dir];

                            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                            if((*trees[nx][ny].begin()).age == 1) (*trees[nx][ny].begin()).num+=(*iter).num; // 이미 age가 1인 나무가 있는 경우
                            else trees[nx][ny].insert(trees[nx][ny].begin(), {(*iter).num, 1}); // age가 1인 나무가 없는 경우
                            ans += (*iter).num; // 남아있는 나무의 개수만큼 나무의 개수 늘려줌
                        }
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)  // 겨울, 각 칸에 양분을 추가한다.
            for(int j = 0; j < n; j++)
                board[i][j] += f[i][j];

        y++;
    }

    cout << ans;
}

/*
10 100 1000
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/