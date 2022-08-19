// Created by 길민호 on 2022/07/10.

#include <bits/stdc++.h>
using namespace std;

int board[1010][1010];
int s[1010][1010];  // s[x][y]는 (x, y)를 오른쪽 하단으로 하는 정사각형의 크기

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int len = 0;    // 가장 큰 정사각형의 한 변의 길이

    for(int i = 0; i < n; i++){
        string str; cin >> str;
        for (int j = 0; j < str.size(); j++){
            board[i][j] = str[j] - 48;
            len = max(len, board[i][j]);
        }
    }

    for(int x = 0; x < n; x++)
        s[x][0] = (board[x][0] == 1) ? 1 : 0;

    for(int y = 0; y < n; y++)
        s[0][y] = (board[0][y] == 1) ? 1 : 0;

    for(int x = 1; x < n; x++){
        for(int y = 1; y < m; y++){
            int size = s[x - 1][y - 1];

            int row = 0, col = 0;
            for (int i = x; i >= x - size; i--){
                if(board[i][y] == 1) col++;
                else break;
            }

            for (int i = y; i >= y - size; i--){
                if(board[x][i] == 1) row++;
                else break;
            }

            s[x][y] = min(row, col);
            len = max(len, s[x][y]);
        }
    }

    cout << len * len;
}

/*
3 3
000
000
000

3 3
000
000
001

3 3
111
111
111

5 5
11000
11000
00111
00111
00111



8 8
11111111
11110011
11110011
11111111
10011111
10011111
10011111
10011111
*/