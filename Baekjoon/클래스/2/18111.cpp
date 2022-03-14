#include <bits/stdc++.h>
using namespace std;

#define v first
#define h second

int n, m, b;
int board[500][500];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> m >> b;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    int s = 257, l = 0;
    for(int i = 0; i < n; i++){ // 땅의 최소 높이, 최대 높이를 찾음
        int x = *min_element(&board[i][0], &board[i][m]);
        int y = *max_element(&board[i][0], &board[i][m]);
        if(x < s) s = x; if(y > l) l = y;
    }
    
    pair<int, int> ans = {INT_MAX, -1}; 
    for(int h = s; h <= l; h++){    // 최소 높이 ~ 최대 높이 범위에서 고르는데 최소의 시간이 걸리는 땅 높이를 찾음
        int sec = 0; int block = b; // sec은 해당 높이로 땅을 고르는데 걸리는 시간, blocK은 사용 가능한 블럭의 개수
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){ // 해당 높이로 땅을 고르는데 걸리는 시간을 계산
                if(board[i][j] > h){    // 블럭이 목표 높이보다 높다면
                    sec +=  2 * (board[i][j] - h);  // 2 * (블럭 - 목표 높이)만큼 sec 증가
                    block += (board[i][j] - h); // 블럭의 개수는 (블럭 - 목표 높이)만큼 추가해줌
                }else if(board[i][j] < h){  // 블럭이 목표 높이보다 낮다면
                    sec += (h - board[i][j]);   // (블럭 - 목표 높이)만큼 sec 증가
                    block -= (h - board[i][j]); // 블럭의 개수는 (블럭 - 목표 높이)만큼 감소
                }
            }
        }

        if(block >= 0){ // 해당 높이까지 고르기 위해 필요한 블럭의 개수가 
            if(ans.v > sec){    // 더 적은 시간이 걸리는 경우
                ans.v = sec;    // 시간 업데이트
                ans.h = h;  // 높이 업데이트
            }else if(ans.v == sec && ans.h < h){    // 시간이 같은 경우
                ans.h = h;  // 높이만 업데이트
            }
        } 
    }

    cout << ans.v << " " << ans.h << "\n";
}

/*
3 3 3
5 5 1
4 3 2
5 6 7

4 3 3
5 5 1
4 3 2
5 6 7
6 8 7
*/