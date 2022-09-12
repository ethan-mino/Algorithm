// Created by 길민호 on 2022/09/12.
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<int, int> pii;

int d[1002][1002];

int solution(vector<vector<int>> board, vector<vector<int>> skills) {
    int answer = 0;

    int n = board.size();
    int m = board[0].size();

    for(auto skill : skills){
        int type = skill[0];
        int r1 = skill[1] + 1, c1 = skill[2] + 1;
        int r2 = skill[3] + 1, c2 = skill[4] + 1;
        int degree = skill[5];

        degree = (type == 1) ? -degree : degree;

        d[r1][c1] += degree;
        d[r2 + 1][c1] -= degree;
        d[r1][c2 + 1] -= degree;
        d[r2 + 1][c2 + 1] += degree;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            d[i][j] = d[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            if(board[i][j] + d[i + 1][j + 1] > 0) answer++;
    }

    return answer;
}