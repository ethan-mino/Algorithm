#include <bits/stdc++.h>
using namespace std;

int arr[3] = {};
int board[3000][3000];

void paper(int sx, int ex, int sy, int ey){
    int v = board[sx][sy];
    bool flag = true;

    if(sx == ex && sy == ey){
        arr[board[sx][ey] + 1]++;
        return;
    }

    for(int i = sx; i <= ex; i++)
        for(int j = sy; j <= ey; j++)
            if(board[i][j] != v)
                flag = false;

    if(flag){
        arr[v + 1]++;
    }else{
        int n = (ex - sx + 1) / 3;
        paper(sx, sx + n - 1, sy, sy + n - 1);
        paper(sx, sx + n - 1, sy + n, sy + n * 2 - 1);
        paper(sx, sx + n - 1, sy + n * 2, ey);

        paper(sx + n, sx + n * 2 - 1, sy, sy + n - 1);
        paper(sx + n, sx + n * 2 - 1, sy + n, sy + n * 2 - 1);
        paper(sx + n, sx + n * 2 - 1, sy + n * 2, ey);
        
        paper(sx + n * 2, ex, sy, sy + n - 1);
        paper(sx + n * 2, ex, sy + n, sy + n * 2 - 1);
        paper(sx + n * 2, ex, sy + n * 2, ey);
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
    for(auto e : arr) cout << e << "\n";
}

/*
9
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
0 1 -1 0 1 -1 0 1 -1
0 -1 1 0 1 -1 0 1 -1
0 1 -1 1 0 -1 0 1 -1


9
1 0 0 1 1 1 -1 -1 -1
0 -1 0 1 1 1 -1 -1 -1
0 0 1 1 1 1 -1 -1 -1
1 1 1 0 0 0 0 0 0
1 1 1 0 -1 0 0 0 0
1 1 1 0 0 0 0 0 0
0 1 -1 0 1 -1 0 1 -1
0 -1 1 0 1 -1 0 1 -1
0 1 -1 1 0 -1 0 1 -1

9
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0


9 
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1

9
-1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1
*/
