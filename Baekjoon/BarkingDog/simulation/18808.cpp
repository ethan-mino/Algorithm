#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int notebook[40][40];   // 스티커를 붙일 노트북
int n, m, k;

void rotate(vector<pair<int, int>>& pos, int* n, int* m){ 
    for(int i = 0; i < pos.size(); i++){
        int nx = pos[i].y; int ny = (*n - 1) - pos[i].x;
        pos[i].x = nx; pos[i].y = ny;
    }

    int temp = *n; *n = *m; *m = temp;
}

bool attach(vector<pair<int, int>> pos){
    bool flag = false;
    for(int i = 0; i < n; i++){ // 기준 좌표는 {i, j}, 기준 좌표를 이동시키면서 스티커를 붙여봄
        for(int j = 0; j < m; j++){
            flag = true;    // 스티커를 붙일 수 있는지를 나타내는 flag
            for(auto c : pos){
                // 기준 좌표를 (0, 0)으로 잡았을 때 각 좌표의 새로운 좌표
                int nx = i + c.x; int ny = j + c.y;   

                // 이미 스티커가 붙어있거나, 노트북의 범위를 벗어나는 경우 flag를 false로 설정
                if(notebook[nx][ny] == 1 || nx < 0 || ny < 0 || nx >= n || ny >= m) 
                    flag = false;   
            }

            if(flag){   // 노트북에 스티커를 붙일 수 있다면
                for(auto c : pos){  
                    int nx = i + c.x; int ny = j + c.y;
                    notebook[nx][ny] = 1;   // 스티커를 붙임
                }
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    while(k--){ // 스티커 개수만큼 반복
        int tn, tm; cin >> tn >> tm;    // 스티커의 크기 입력 받음
        int board[10][10];  

        for(int i = 0; i < tn; i++)
            for(int j = 0; j < tm; j++)
                cin >> board[i][j]; // 스티커 입력 받음

        vector<pair<int, int>> pos;
        for(int i = 0; i < tn; i++)
            for(int j = 0; j < tm; j++)
                if(board[i][j] == 1) pos.push_back({i, j}); // 스티커의 각 좌표 push

        for(int i = 0; i < 4; i++){
            bool success = attach(pos); // 노트북에 스티커를 붙임
            if(success) break;  // 붙이기에 성공한 경우, 각 좌표를 회전시키지 않고 break
            else rotate(pos, &tn, &tm); // 붙이기에 실패한 경우, 각 좌표를 회전시킴
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(notebook[i][j] == 1) ans++; // 스티커가 붙은 칸 수 count

    cout << ans << "\n";
}