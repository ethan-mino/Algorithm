// Created by 길민호 on 2022/08/15.

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

// ! 모래가 이동하는 좌표를 현재 방향에 따라 정의
int tx[4][10] = {
        {-1, -1, -1, -2, 0, 0, 1, 1, 1, 2},
        {-1, 0, 1, 0, 1, 2, 1, 0, -1, 0},
        {1, 1, 1, 2, 0, 0, -1, -1, -1, -2},
        {1, 0, -1, 0, -1, -2, -1, 0, 1, 0}
};

int ty[4][10] = {
        {1, 0, -1, 0, -1, -2, -1, 0, 1, 0},
        {-1, -1, -1, -2, 0, 0, 1, 1, 1, 2},
        {-1, 0, 1, 0, 1, 2, 1, 0, -1, 0},
        {1, 1, 1, 2, 0, 0, -1, -1, -1, -2}
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// ! 각 좌표의 모래의 이동 비율
int rate[] = {1, 7, 10, 2, 55, 5, 10, 7, 1, 2};
int board[500][500];
int order[500][500];
int n;

void printArr(int arr[500][500]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

// * 1. (0, 0)부터 시작하여 달팽이 모양으로 순서를 정함.
// * 2. (n / 2, n / 2)부터 시작하여, 앞서 정한 순서를 따라 이동
// *    2-1. 이동하면서 모래를 옮김
// *    2-2. 현재 위치가 (0, 0)이 되면 종료

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    pair<int, int> cur = {0, 0};
    pair<int, int> mid = {n / 2, n / 2};
    int dir = 2;
    int num = 1;
    order[0][0] = num++;

    // * 1. (0, 0)부터 시작하여 달팽이 모양으로 순서를 정함.
    while(!(cur.x == mid.x && cur.y == mid.y)){
        int nx = cur.x + dx[dir];
        int ny = cur.y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n || order[nx][ny] != 0){
            dir = (dir + 1) % 4;    // * 이미 방문했거나 격자를 벗어나는 경우 방향을 바꿈
            continue;
        }

        // * 한 칸씩 이동하고, order 배열에 이동 순서를 저장
        order[nx][ny] = num++;
        cur.x = nx, cur.y = ny;
    }

    int ans = 0; // 격자 밖으로 이동한 모래의 양
    // * 2. (n / 2, n / 2)부터 시작하여, 앞서 정한 순서를 따라 이동
    cur = mid;  // (n / 2, n / 2)부터 시작
    while(!(cur.x == 0 && cur.y == 0)){ // * 현재 위치가 (0, 0)이 되면 종료
        for(int dir = 0; dir < 4; dir++){   // * 4 방향을 확인하여 다음 이동할 좌표를 찾음
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(order[nx][ny] != order[cur.x][cur.y] -1) continue;

            // ! 현재 좌표에 원래 있던 모래의 비율만큼 이동해야하므로
            // ! 현재 좌표에 원래 있던 모래의 양을 origin 변수에 유지
            int origin = board[nx][ny];

            for(int i = 0; i < 10; i++){
                // ! α로 이동하는 모래는 다른 좌표에 모두 이동시키고 난 후 남은 모래를 이동시키기 위해 continue
                if(i == 4) continue;

                // * 모래가 이동하는 좌표
                int tnx = nx + tx[dir][i];
                int tny = ny + ty[dir][i];

                int sand = origin * rate[i] / 100; // ! 이동하는 모래의 양 (origin의 비율만큼 이동)
                board[nx][ny] -= sand;  // * board에는 줄어든 모래의 양을 기록

                // * 격자를 벗어나는 경우 ans에 더해줌
                // * 다른 좌표로 이동하는 경우 해당 좌표의 모래의 양에 더해줌
                if(tnx < 0 || tny < 0 || tnx >= n || tny >= n){
                    ans += sand;
                }else{
                    board[tnx][tny] += sand;
                }
            }

            // ! α의 좌표
            int fnx = nx + tx[dir][4];
            int fny = ny + ty[dir][4];

            // * α의 좌표가 격자판을 벗어하는 경우 ans에 더해줌
            // * α의 좌표가 격자판 내에 있는 경우 해당 좌표에 모래의 양에 더해줌
            if(fnx < 0 || fny < 0 || fnx >= n || fny >= n){
                ans += board[nx][ny];
            }else{
                board[fnx][fny] += board[nx][ny];
            }

            // ! 원래 위치의 모래 양은 0으로 설정
            board[nx][ny] = 0;
            // cur -> (nx, ny)로 이동
            cur.x = nx, cur.y = ny;
        }
    }

    cout << ans << "\n";
}