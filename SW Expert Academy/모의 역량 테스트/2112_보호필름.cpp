// Created by SSAFY on 2022-11-07.

#include <bits/stdc++.h>
using namespace std;

int d, w, k;

bool isColPass(int y, int board[20][20]){
    for(int x = 0; x < d; x++){
        int seq = 0;
        for(int cnt = 0; cnt < k; cnt++){
            int nx = x + cnt;
            if(nx < 0 || nx >= d) break;

            if(board[x][y] == board[nx][y]){
                seq++;
            }else{
                x = nx - 1;
                break;
            }
        }

        if(seq >= k) return true;
    }

    return false;
}

bool isPass(int board[20][20]){
    for(int col = 0; col < w; col++){
        if(!isColPass(col, board)) return false;
    }
    return true;
}

void printBoard(int board[20][20]){
    for(int i = 0; i < d; i++){
        for(int j = 0; j < w; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int minCnt = INT_MAX;
int rowColor[20];

void back(int row, int cnt, int board[20][20]){
    if(row == d){
        int temp[20][20];
        for(int r = 0; r < d; r++){
            int color = rowColor[r];

            for(int c = 0; c < w; c++){
                int nxColor = (color == 0) ? board[r][c] : (color == 1) ? 0 : 1;
                temp[r][c] = nxColor;
            }
        }

        if(isPass(temp)){
            minCnt = min(minCnt, cnt);
        }
    }else if(cnt < minCnt){
        // 0이면 약물을 투입하지 않음, 1이면 A 약물을 투입, 2이면 B 약물을 투입
        for(int i = 0; i < 3; i++){
            int nxCnt = (i == 0) ? cnt : cnt + 1;

            rowColor[row] = i;
            back(row + 1, nxCnt, board);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int board[20][20];
    int t; cin >> t;

    for(int tc = 1; tc <= t; tc++){
        cin >> d >> w >> k;

        for(int i = 0; i < d; i++){
            for(int j = 0; j < w; j++){
                cin >> board[i][j];
            }
        }

        minCnt = k;
        back(0, 0, board);
        cout << "#" << tc << " " << minCnt << "\n";
    }
}

/*
1
6 4 4
1 1 0 0
0 1 0 1
1 1 1 1
1 1 1 1
1 1 1 1
1 0 1 0
 */