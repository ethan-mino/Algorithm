#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n;  // 체스판의 크기
int board[10][10];  // 체스판
bool isused1[20];   // 우상향 대각선에 대한 상태 배열
bool isused2[20];   // 좌상향 대각선에 대한 상태 배열

int ans = 0;
void bishop(int th, int size){  // th는 우상향 대각선의 index, size는 이전에 선택한 비숍의 개수
    if(th >= 2 * n - 1){    
        ans = max(ans , size); 
    }else{
        bool flag = false;  // th번째 대각선에서 비숍을 놓았는지를 나타내는 flag

        for(int j = 0; j < n - abs(th - (n- 1)); j++){   
            int x = (n - 1 <= th) ? n - 1 - j : th - j; // th번째 대각선의 j번째 위치의 x좌표
            int y = (n - 1 <= th) ? th - (n - 1) + j : j;  // th번째 대각선의 j번째 위치의 y좌표

            if(board[x][y] == 1 && !isused1[th] && !isused2[n - 1 + (x - y)]){  // 비숍을 놓을 수 있으면서, 우상향 대각선과 좌상향 대각선에 비숍이 없는 경우
                flag = true;    
                isused1[th] = true; // 비숍을 놓는 위치에 해당하는 우상향 대각선에 true를 표시
                isused2[n - 1 + (x - y)] = true;    // 좌상향 대각선에 true를 표시
                bishop(th + 1, size + 1); 
                isused1[th] = false;    // 우상향 대각선을 false로 복구
                isused2[n - 1 + (x - y)] = false; // 좌상향 대각선을 false로 복구
            }
        }
        if(!flag) bishop(th + 1, size); // th 번째 대객선에서 비숍을 놓지 않았다면, size를 늘리지 않고, th + 1번째 비숍을 선택.
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i =0 ; i < n; i++)  // 체스판 입력 받음
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    bishop(0, 0);
    cout << ans;
}

// th = 0 -> 1
// th = 1 -> 2
// th = 2 -> 3
// th = 3 -> 4
// th = 4 -> 5
// th = 5 -> 4
// th = 6 -> 3
// th = 7 -> 2
// th = 8 -> 1
// th = 9 -> 0

/*
5
1 1 0 1 1
0 1 0 0 0
1 0 1 0 1
1 0 0 0 0
1 0 1 1 0

3
0 0 0
0 0 0
0 0 0

3
0 0 0
0 0 0
0 0 1

3
0 0 1
0 1 0
0 0 1

10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
*/