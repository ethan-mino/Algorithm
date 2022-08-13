// Created by 길민호 on 2022/08/13.

#include <bits/stdc++.h>
using namespace std;

// * 폴리오미오 벡터
vector<vector<vector<int>>> figures = {
        {{1, 1, 1, 1}},
        {{1, 1}, {1, 1}},
        {{1, 0}, {1, 0}, {1, 1}},
        {{1, 0}, {1, 1}, {0, 1}},
        {{1, 1, 1}, {0, 1, 0}}
};

int board[510][510];
int n, m;

// * figureIdx의 도형을 rotate
// ! 270도를 회전시킬 때 3번 회전시키지 않기 위해 rotate한 도형을 반환하는 게 아니라 figureIdx의 도형을 돌림
void rotate(int figureIdx){
    int N = figures[figureIdx].size();
    int M = figures[figureIdx][0].size();
    vector<vector<int>> rotated(M, vector<int>(N, 0));

    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){ // * 배열 돌리기처럼 [y][n - x - 1] 사용
            rotated[y][N - x - 1] = figures[figureIdx][x][y];
        }
    }

    figures[figureIdx] = rotated;
}

// * figureIdx의 도형을 각 좌표에 두고 합을 구함
int sum(int figureIdx){
    int N = figures[figureIdx].size();
    int M = figures[figureIdx][0].size();

    int ans = 0;
    for(int x = 0; x < n; x++){
        if(x + N - 1 >= n)  break;  // ! 도형의 끝이 종이를 벗어나는 경우 break
        for(int y = 0; y < m; y++){
            int sum = 0;
            if(y + M - 1 >= m)  break;  // ! 도형의 끝이 종이를 벗어나는 경우 break

            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(figures[figureIdx][i][j] == 1){  // ! 도형인 경우에만 더함
                        sum += board[x + i][y + j];
                    }
                }
            }
            ans = max(ans, sum);
        }
    }
    return ans;
}

// * 도형을 대칭시키는 함수
void symmetry(int figureIdx){
    int N = figures[figureIdx].size();
    int M = figures[figureIdx][0].size();

    for(int x = 0; x < N; x++){
        for(int y = 0; y < M / 2; y++){ // * 열의 절반만 swap
            int temp = figures[figureIdx][x][y];
            figures[figureIdx][x][y] = figures[figureIdx][x][M - y - 1];
            figures[figureIdx][x][M - y - 1] = temp;
        }
    }
}

// * 각 폴리오미노를 회전, 대칭시켜 각 좌표에 놓고 합을 구해봄
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)  // 종이 입력 받음
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    int ans = 0;
    for(int f = 0; f < figures.size(); f++){    // 각각의 도형 대해 반복
        for(int r = 0; r < 4; r++){ // 0도, 90도, 180도, 270도 돌려가며 종이에 올려놓아봄
            if(f != 1) rotate(f);   // * 1번 도형은 대칭시켜도 동일하므로 회전시키지 않음
            ans = max(ans, sum(f));
             if(f != 0 && f != 1) { // * 0번, 1번 도형은 대칭시켜도 동일하므로 대칭시키지 않음
                symmetry(f);
                ans = max(ans, sum(f));
                symmetry(f);    // ! 대칭시켜준 것을 복구시켜줌
            }
        }
    }

    cout << ans << "\n";
}

/*
5 5
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

5 5
0 0 0 0 0
0 0 6 0 0
0 1 2 3 0
0 0 5 0 0
0 0 0 0 0
-> 16

5 5
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 1
0 0 0 3 2

5 5
0 0 0 0 0
0 0 0 4 0
0 0 3 5 0
0 0 0 0 0
0 0 2 0 0

5 5
0 0 0 0 0
0 5 5 0 0
0 0 5 5 0
0 0 0 0 0
0 0 0 0 0
*/