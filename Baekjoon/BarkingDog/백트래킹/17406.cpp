// Created by SSAFY on 2022-11-07.
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define x first
#define y second

int n, m, k;

// 아래, 오른쪽, 위쪽, 왼쪽
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int r[6], c[6], s[6];
bool selected[6];

void rotateLine(pii leftUpper, pii rightLower, int board[50][50]){
    int startPosValue = board[leftUpper.x][leftUpper.y];
    pii leftLower = {rightLower.x, leftUpper.y};
    pii rightUpper = {leftUpper.x, rightLower.y};

    pii curPos = leftUpper;
    int curDir = 0;

    while(true){
        int nx = curPos.x + dx[curDir];
        int ny = curPos.y + dy[curDir];

        if(nx == leftUpper.x && ny == leftUpper.y) break;
        board[curPos.x][curPos.y] = board[nx][ny];

        curPos = {nx, ny};

        if(curPos == leftLower || curPos == rightLower || curPos == rightUpper){
            curDir++;
        }
    }

    board[leftUpper.x][leftUpper.y + 1] = startPosValue;
}

void rotate(pii leftUpper, pii rightLower, int board[50][50]){
    while(leftUpper.x != rightLower.x){
        rotateLine(leftUpper, rightLower, board);

        leftUpper.x++; leftUpper.y++;
        rightLower.x--; rightLower.y--;
    }
}

int getMinRowSum(int board[50][50]){
    int minRowSum = INT_MAX;
    for(int i =0; i < n; i++){
        int curRowSum = 0;
        for(int j = 0; j < m; j++){
            curRowSum += board[i][j];
        }
        if(minRowSum > curRowSum) minRowSum = curRowSum;
    }

    return minRowSum;
}

int ans = INT_MAX;
void back(int depth, int board[50][50]){
    if(depth == k){
        int curMinRowSum = getMinRowSum(board);
        ans = min(ans, curMinRowSum);
    }else{
        for(int curRotate = 0; curRotate < k; curRotate++){
            if(selected[curRotate]) continue;
            selected[curRotate] = true;

            int temp[50][50];
            memcpy(temp, board, sizeof(temp));

            int curR = r[curRotate] - 1, curC = c[curRotate] - 1, curS = s[curRotate];
            pii leftUpper = {curR - curS, curC - curS};

            pii rightLower = {curR + curS, curC + curS};
            rotate(leftUpper, rightLower, temp);
            back(depth + 1, temp);

            selected[curRotate] = false;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    int board[50][50];

    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < k; i++){
        cin >> r[i] >> c[i] >> s[i];
    }

    back(0, board);
    cout << ans << "\n";
}