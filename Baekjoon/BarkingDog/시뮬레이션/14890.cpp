#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n, l;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double board[100][100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    int ans = 0;
    for(int i = 0; i < 2; i++){ // 가로, 세로에 대해 반복
        for(int j = 0; j < n; j++){ // 각 행 또는 열에 대해 반복
            pair<int, int> cur; // 현재 확인 중인 좌표
            if(i == 1) cur = {j, 0};    // 행을 검사하는 경우
            else cur = {0, j};  // 열을 검사하는 경우
            
            vector<pair<int, int>> runway;  // 현재 행 또는 열에 설치한 경사로의 좌표
            while(true){    // 해당 행 또는 열을 따라, 각 좌표를 확인
                pair<int, int> nx = {cur.x + dx[i], cur.y + dy[i]}; // 한 칸 다음의 좌표
                if(nx.x < 0 || nx.y < 0 || nx.x >= n || nx.y >= n) {ans++; break;}  // 열 또는 행의 끝에 도달한 경우 지나갈 수 있는 길

                if(abs(board[cur.x][cur.y] - board[nx.x][nx.y]) > 1) break; // 두 칸 이상 차이 나는 경우
                if(abs(board[cur.x][cur.y] - board[nx.x][nx.y]) == 0) cur = nx;    // 높이가 같은 경우
                else{  // 한 칸만 차이나는 경우 
                    pair<int, int> dir, cmp;    // inv는 경사로를 세울 방향
                    vector<pair<int, int>> t;   // 경사로를 세울 좌표
                    if(board[cur.x][cur.y] > board[nx.x][nx.y]) {dir = {dx[i], dy[i]}; cmp = nx;} // 한 칸 앞이 더 낮은 경우 진행 방향을 확인
                    else {dir = {dx[i + 2], dy[i + 2]}; cmp = cur;}  // 한 칸 앞이 더 높은 경우 진행 반대 방향을 확인
                    
                    for(int k = 0; k < l; k++){ // 높이가 같은 길의 길이를 계산, 해당 좌표를 벡터에 넣음
                        int x = cmp.x + dir.x * k, y = cmp.y + dir.y * k;
                        if(x>=0 && y>=0 && x<n && y<n && board[x][y] == board[cmp.x][cmp.y])  t.push_back({x, y});
                        else break;
                    }

                    if(t.size() < l){    // 평평한 땅의 길이가 경사로의 길이보다 짧은 경우
                        break;
                    }else{  // 경사로를 설치할 수 있는 길이가 있는 경우
                        bool overlap = false;   // 다른 경사로와 겹치는 지 여부를 나타내는 flag
                        for(auto r : runway)    // 기존에 설치한 경사로의 좌표와 비교 
                            for(auto c : t)
                                if(c.x == r.x && c.y == r.y) overlap = true;    // 겹치는 true로 설정

                        if(!overlap){   // 다른 경사로와 겹치지 않는다면
                            for(auto c : t)
                                runway.push_back(c);    // 경사로 좌표에 추가
                            if(board[cur.x][cur.y] > board[nx.x][nx.y]) // 현재 확인 좌표가 더 높은 경우
                                cur = {cur.x + dx[i] * l, cur.y + dy[i] * l}; // 다음 검사 위치는 설치한 경사로의 마지막 좌표
                            else cur = nx; // 한 칸 다음 좌표
                        }else break;
                    }
                }
            }
        }
    }


    cout << ans;
}