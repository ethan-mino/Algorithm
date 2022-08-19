#include <bits/stdc++.h>
using namespace std;

int board[128][128];
int arr[2];

void paper(int sx, int ex, int sy, int ey){
    if(sx == ex && sy == ey) arr[board[sx][sy]] ++;
    else{
        int f = board[sx][sy];
        bool flag = true;

        for(int i = sx; i <= ex; i++)
            for(int j = sy; j <= ey; j++)
                if(board[i][j] != f) flag = false;
        if(flag){
            arr[board[sx][sy]]++;
        }else{
            int n = (ex - sx + 1) / 2;

            // 좌상단
            paper(sx, sx + n - 1, sy, sy + n - 1);
            // 우상단
            paper(sx, sx + n - 1, sy + n, ey);
            // 좌하단
            paper(sx + n, ex, sy, sy + n - 1);
            // 우하단
            paper(sx + n, ex, sy + n, ey);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    for(int i = 0; i < n; i++)    
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    paper(0, n-1, 0, n-1);
    cout << arr[0] << "\n";
    cout << arr[1] << "\n";
}

/*

8
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0
1 0 0 0 1 1 1 1
0 1 0 0 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1


8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1

8
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

8
0 0 0 1 1 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 1 
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
*/