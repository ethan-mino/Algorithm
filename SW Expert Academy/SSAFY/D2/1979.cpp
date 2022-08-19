#include <bits/stdc++.h>
using namespace std;

#define FILL 0
#define EMPTY 1

#define row first
#define col second

int board[20][20];
int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    int cur = 1;

    while(t--){
        cin >> n >> k;
        fill(&board[0][0], &board[n - 1][n], 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> board[i][j]; // 흰색 1, 검은색 0
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == FILL) continue;

                int x = i;
                while(x != n && board[x][j] != FILL) x++;
                int row = x - i;
                if(row == k && (i - 1 < 0 || board[i - 1][j] == FILL)) ans++;

                int y = j;
                while(y != n && board[i][y] != FILL) y++;
                int col = y - j;
                if(col == k && (y - 1 < 0 || board[i][j - 1] == FILL)) ans++;
            }
        }
        cout << "#" << cur++ << " " << ans << "\n";
    }
}