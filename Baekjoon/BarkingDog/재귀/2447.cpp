#include <bits/stdc++.h>
using namespace std;

int board[2200][2200];

void star(int sx, int ex, int sy, int ey){
    int n = ex - sx;
    if(n == 2){
        for(int i = sx; i <= ex; i++)
            for(int j = sy; j <= ey; j++){
                if(!(i == sx + 1 && j == sy + 1)) board[i][j] = '*';;
            }
                
    }else{
        n = (ex - sx + 1) / 3;
        // 1층
        star(sx, sx + n - 1, sy, sy + n - 1);   // 좌상단
        star(sx, sx + n - 1, sy + n, sy + (n*2) - 1);   // 상단
        star(sx, sx + n - 1, sy + (n*2), ey);   // 우상단
        // 2층
        star(sx + n, sx + (n*2) - 1, sy, sy + n - 1);   
        //star(sx + n, sx + (n*2) - 1, sy + n, sy + (n*2) - 1);    // 중간은 공백으로 비워둠
        star(sx + n, sx + (n*2) - 1, sy + (n*2), ey);   
        // 3층
        star(sx + (n*2), ex, sy, sy + n - 1);   
        star(sx + (n*2), ex, sy + n, sy + (n*2) - 1);   
        star(sx + (n*2), ex, sy + (n*2), ey);  
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    fill(&board[0][0], &board[2199][2200], ' ');

    star(0, n - 1, 0, n-1);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << board[i][j];
        cout << "\n";
    }
}
