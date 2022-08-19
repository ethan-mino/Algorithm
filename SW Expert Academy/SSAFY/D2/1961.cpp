// Created by 길민호 on 2022/07/01.

#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef pair<int, int> pii;

int board[10][10];
int rotated[4][10][10];
int n;

void rotate(int cnt){
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            rotated[cnt][y][n - (x + 1)] = rotated[cnt - 1][x][y];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    int cur = 1;
    while(t--){
        cin >> n;
        fill(&board[0][0], &board[n - 1][n], 0);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> rotated[0][i][j];

        for(int cnt = 1; cnt <= 3; cnt++) rotate(cnt);

        cout << "#" << cur++ << "\n";
        for(int x = 0; x < n; x++){
            for(int cnt = 1; cnt <= 3; cnt++){
                for(int y = 0; y < n; y++){
                    cout << rotated[cnt][x][y];
                }
                cout << " ";
            }
            cout << "\n";
        }
    }
}

/*
2
3
1 2 3
4 5 6
7 8 9
6
6 9 4 7 0 5
8 9 9 2 6 5
6 8 5 4 9 8
2 2 7 7 8 4
7 5 1 9 7 9
8 9 3 9 7 6
*/