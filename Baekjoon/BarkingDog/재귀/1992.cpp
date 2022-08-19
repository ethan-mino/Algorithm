#include <bits/stdc++.h>
using namespace std;

int board[64][64];


void quadTree(int sx, int ex, int sy, int ey){

    if(sx == ey && sy == ey){
        cout << board[sx][sy];
    }else{
        int a = board[sx][sy];
        bool flag = true;

        for(int i = sx; i <= ex; i++)
            for(int j = sy; j <= ey; j++)
                if(board[i][j] != a) flag = false;
        if(flag){
            cout << a;
        }else{
            cout << "(";

            int n = (ex - sx + 1) / 2;

            quadTree(sx, sx + n - 1, sy, sy + n - 1);    // 좌상단
            quadTree(sx, sx + n - 1, sy + n, ey);   // 우상단
            quadTree(sx + n, ex, sy, sy + n - 1);   // 좌하단
            quadTree(sx + n, ex, sy + n, ey);   // 우하단

            cout << ")";
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for(int i = 0 ; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j++)
            board[i][j] = s[j] - 48;
    }

    quadTree(0, n - 1, 0, n - 1);
}
