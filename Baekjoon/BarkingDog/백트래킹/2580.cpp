#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

vector<pair<int, int>> notFiled;
bool check = false;
void back(int th, int board[9][9]){
    if(check) return;

    if(th == notFiled.size()){
        for(int x = 0; x < 9; x++){
            for (int y = 0; y < 9; y++)
                cout << board[x][y] << " ";
            cout << "\n";
        }
        check = true;
    }else{
        pair<int, int> cur = notFiled[th];
        int x = cur.x, y = cur.y;

        bool arr[10];
        fill(arr, arr + 10, 0);

        for(int i = 0; i < 9; i++)  // 행 확인
            arr[board[x][i]] = true;
        for(int i = 0; i < 9; i++)  // 열 확인
            arr[board[i][y]] = true;

        int boxStX = 3 * (x / 3), boxStY = 3 *(y / 3);

        for(int i = boxStX; i < boxStX + 3; i++)
            for(int j = boxStY; j < boxStY + 3; j++)
                arr[board[i][j]] = true;

        for(int i = 1; i <= 9; i++){
            if(arr[i] == 0){
                board[x][y] = i;
                back(th + 1, board);
                board[x][y] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int board[9][9];

    for(int i =0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(board[i][j] == 0){
                notFiled.push_back({i, j});
            }
        }
    }

    back(0, board);
}
/*
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
*/