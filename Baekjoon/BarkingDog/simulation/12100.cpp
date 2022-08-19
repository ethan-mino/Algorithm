#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
int board[20][20];

vector<vector<int>> p;    
vector<int> selected(5);

int n; 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans = 0;

void permutation(int th){   // 6-th개의 이동을 선택하는 모든 경우의 수를 계산하는 함수
    if(th == 6){
        p.push_back(selected);
    }else{
        for(int i = 0; i < 4; i++){ // 0은 상, 1은 하, 2는 좌, 3은 우
            selected[th - 1] = i;
            permutation(th + 1);
        }
    }
}

void game(vector<int> & move){    // 주어진 이동 수열을 기반으로 2048 수행
    int temp[20][20];
    memcpy(temp, board, sizeof(temp));  // 여러 경우의 수에 대해 반복하기 때문에 board를 복사해서 사용

    for(int i = 0; i < move.size(); i++){   // 각각의 이동에 대해 반복
        for(int j = 0; j < n; j++){    // 각각의 행 또는 열에 대해 반복

            pair<int, int> cur; // 위치 또는 값을 변경할 좌표
            // 이동에 따라 시작 지점을 달리함 (ex. ↑인 경우 가장 위의 좌표부터 시작)
            if(move[i] == 0) cur = {0, j}; else if(move[i] == 1) cur = {n-1, j};  
            else if(move[i] == 2) cur = {j, 0}; else if(move[i] == 3) cur = {j, n - 1}; 

            queue<pair<int, int>> empty;    // 비어있는 좌표를 저장하는 큐

            while(true){    // 해당 열 또는 행의 각 좌표에 대해 반복                
                if(cur.x < 0 || cur.y < 0 || cur.x >= n || cur.y >= n) break; 

                if(temp[cur.x][cur.y] == 0){    // 현재 확인 중인 위치가 0인 경우 queue에 삽입
                    empty.push({cur.x, cur.y});
                }else {
                    pair<int, int> nx = {-1, -1}; // 다음 블럭의 좌표
                    for(int k = 1; k < n; k++){ // 다음 블럭의 위치를 찾아서 nx에 저장
                        int x = cur.x + dx[move[i]] * k;
                        int y = cur.y + dy[move[i]] * k;
                        if(x >= 0 && y >= 0 && x < n && y < n && temp[x][y] != 0){
                            nx = {x, y}; break;
                        }
                    }

                    if(nx.x != -1 && nx.y != -1 // 다음 블록이 존재하며, cur와 nx의 값이 같은 경우
                    && temp[cur.x][cur.y] == temp[nx.x][nx.y]){   
                        if(!empty.empty()){ // 빈 곳이 있는 경우
                            pair<int, int> p = empty.front(); empty.pop();  
                            // 값을 두 배로 하여 빈 곳에 블록을 이동시킨다
                            temp[p.x][p.y] = temp[cur.x][cur.y] * 2; 
                            // 현재의 위치를 queue에 넣고, 값을 0으로 변경
                            empty.push({cur.x, cur.y}); temp[cur.x][cur.y] = 0; 
                        }else{  // 빈 곳이 없는 경우
                            temp[cur.x][cur.y] *= 2;    // 값을 두 배로 변경
                        }
                        temp[nx.x][nx.y] = 0;   // 다음 블록의 값을 0으로 변경
                    }else{  // 현재 블럭과 다음 좌표
                        if(!empty.empty()){ // cur를 빈 곳으로 표시하고 빈 곳으로 블럭을 이동시킴
                            pair<int, int> p = empty.front(); empty.pop();
                            temp[p.x][p.y] = temp[cur.x][cur.y];
                            // 현재의 위치를 queue에 넣고, 값을 0으로 변경
                            empty.push({cur.x, cur.y}); temp[cur.x][cur.y] = 0; 
                        }
                        // 빈 곳이 없다면 블럭을 이동시키지도, 값을 변경하지도 않는다.
                    }
                }
                cur = {cur.x + dx[move[i]], cur.y + dy[move[i]]};   // cur의 위치를 한 칸 이동
            }
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans = max(temp[i][j], ans);   
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    
    permutation(1); // 이동의 모든 경우의 수를 구함
    for(auto c : p) game(c);    // 각 경우의 수에 대해 2048 게임 수행

    cout << ans;
}

/*
3
2 2 2
0 0 0
0 0 0

3
8 0 0
0 0 0
8 0 0

5
16 8 4 2 0
8 0 0 2 0
4 8 4 0 0
4 0 0 0 0
4 4 0 0 0
*/