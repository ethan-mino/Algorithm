// Created by 길민호 on 2022/07/01.

#include <bits/stdc++.h>
using namespace std;

#define SIZE 9
int board[SIZE][SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    int cur = 1;
    while(t--){
        for(int i = 0; i < SIZE; i++)
            for(int j = 0; j < SIZE; j++)
                cin >> board[i][j];

        bool dup = false;
        for(int line = 0; line < SIZE; line++){
            set<int> row, col;
            for(int th = 0; th < SIZE; th++){
                bool row_dup = binary_search(row.begin(), row.end(), board[line][th]);
                bool col_dup = binary_search(col.begin(), col.end(), board[th][line]);

                if(row_dup || col_dup) dup = true;
                row.insert(board[line][th]);
                col.insert(board[th][line]);
            }
        }

        for(int st_x = 0; st_x < SIZE / 3; st_x += SIZE / 3){
            for(int st_y = 0; st_y < SIZE / 3; st_y += SIZE / 3){
                set<int> block;
                for(int x = 0; x < SIZE / 3; x ++){
                    for(int y = 0; y < SIZE / 3; y++){
                        bool bloack_dup = binary_search(block.begin(), block.end(), board[st_x + x][st_y + y]);
                        if(bloack_dup) dup = true;
                        block.insert(board[st_x + x][st_y + y]);
                    }
                }
            }
        }

        cout << "#" << cur++ << " " << !dup << "\n";
    }
}