// Created by SSAFY on 2022-09-16.

#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
typedef pair<int, int> pii;

bool selected[10];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int answer = INT_MAX;
map<int, vector<pii>> cardPos;

int cursorMove(pii cursor, pii dest, vector<vector<int>>& board){
    // 현재 커서 위치로부터 dest까지 움직이는데 필요한 최소한의 키 입력 수를 반환
    int vis[4][4];
    fill(&vis[0][0], &vis[3][4], 0);

    queue<pii> q;
    q.push(cursor);
    vis[cursor.x][cursor.y] = 1;

    while(!q.empty()){
        pii cur = q.front(); q.pop();

        for(int dir = 0; dir < 4; dir++){
            // 방향키만 눌러 이동하는 경우
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;

            if(vis[nx][ny] == 0){
                q.push({nx, ny});
                vis[nx][ny] = vis[cur.x][cur.y] + 1;
            }

            // ctrl + 방향키를 눌러 이동하는 경우
            pii ctrlCur = cur;
            while(true){
                int nx = ctrlCur.x + dx[dir];
                int ny = ctrlCur.y + dy[dir];

                if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4) break;
                ctrlCur = {nx, ny};

                if(board[ctrlCur.x][ctrlCur.y] != 0) break;
            }


            if(vis[ctrlCur.x][ctrlCur.y] != 0) continue;

            q.push(ctrlCur);
            vis[ctrlCur.x][ctrlCur.y] = vis[cur.x][cur.y] + 1;
        }
    }

    return vis[dest.x][dest.y] - 1;
}

// 커서의 위치부터 시작하여
// 카드를 제거하는 순서를 순열을 이용하여 선택
// 각 depth마다 카드를 뒤집고, 보드의 상태를 다음 depth에 전달
void permutation(int th, int cardCnt, int keyInputCnt, pii cursor, vector<vector<int>> board){
    if(th == cardCnt){
        answer = min(answer, keyInputCnt);
    }else if(keyInputCnt < answer){
        for(int curCardNum = 1; curCardNum <= cardCnt; curCardNum++){

            if(!selected[curCardNum]){
                selected[curCardNum] = true;

                vector<vector<int>> tempBoard(4, vector<int>(4));
                copy(board.begin(), board.end(), tempBoard.begin());

                // cursor -> m[curCardNum][0] -> m[curCardNum][1]
                // cursor -> m[curCardNum][1] -> m[curCardNum][0]
                pii firstCardPos = cardPos[curCardNum][0];
                pii secondCardPos = cardPos[curCardNum][1];

                vector<int> tmpKeyInputCnt = {cursorMove(cursor, firstCardPos, board) + cursorMove(firstCardPos, secondCardPos, board),
                                              cursorMove(cursor, secondCardPos, board) + cursorMove(secondCardPos, firstCardPos, board)};
                vector<pii> tmpCursor = {secondCardPos, firstCardPos};

                // curCardNum에 해당하는 카드 두 장을 제거
                for(auto cardPos : cardPos[curCardNum])
                    tempBoard[cardPos.x][cardPos.y] = 0;

                // curCardNum을 가진 카드 중 순서를 정하여 진행
                for(int cardOrder = 0; cardOrder < 2; cardOrder++){
                    permutation(th + 1, cardCnt, keyInputCnt + tmpKeyInputCnt[cardOrder] + 2, tmpCursor[cardOrder], tempBoard);
                }

                selected[curCardNum] = false;
            }
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(board[i][j] != 0)
                cardPos[board[i][j]].push_back({i, j});

    permutation(0, cardPos.size(), 0, {r, c}, board);
    return answer;
}