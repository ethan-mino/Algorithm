// Created by 길민호 on 2022/07/01.

#include<bits/stdc++.h>
using namespace std;

int board[20][20];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    int cur = 1;

    while(t--){
        int n, m; cin >> n >> m;
        fill(&board[0][0], &board[n - 1][n], 0);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> board[i][j];

        int sum = INT_MIN;
        for(int i = 0; i < n - (m - 1); i++){
            for(int j = 0; j < n - (m - 1); j++){
                int tmp = 0;
                for(int x = i; x < i + m; x++){
                    for(int y = j; y < j + m; y++){
                        tmp += board[x][y];
                    }
                }
                sum = max(sum, tmp);
            }
        }
        cout << "#" << cur++ << " " << sum << "\n";
    }
}
