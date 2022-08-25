#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define EMPTY -2

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int board[30][30];
int n, m;

// * 격자를 반시계 방향으로 회전시키는 함수
void rotate(){
    int temp[30][30];

    for(int x =0 ; x < n; x++)
        for(int y =0 ; y < n; y++)
            temp[n - y - 1][x] = board[x][y];   // ! 반시계 회전
    memcpy(board, temp, sizeof(temp));  // * 회전된 격자를 board에 다시 저장
}


// * 격자에 중력을 작용시키는 함수
void gravity(){
    for(int x = n - 1; x >= 0; x--){    // ! 가장 밑부터 중력 작용
        for(int y = 0; y < n; y++){
            if(board[x][y] != EMPTY && board[x][y] != -1){  // * 무지개 블럭, 일반블록에만 중력 작용
                pair<int, int> cur = {x, y};
                while(true){    // * 격자판의 경계 또는 다른 블럭을 만날 때까지, 한 칸씩 아래칸을 쭉 탐색
                    pair<int, int> nx = {cur.x + 1, cur.y};
                    if(nx.x < 0 || nx.y < 0 || nx.x >= n || nx.y >= n || board[nx.x][nx.y] != EMPTY){   // * 한 칸 아래칸이 경계 또는 다른 블럭일 때 cur에 블럭을 옮겨줌
                        // ! cur.x, cur.y에 현래 위치의 값을 넣어놓고, 이전 위치에 빈 값을 넣는다면, 이동하지 않는 블럭에 empty가 저장됨
                        int temp = board[x][y];
                        board[x][y] = EMPTY;
                        board[cur.x][cur.y] = temp;
                        break;
                    }

                    cur = nx;   //  한 칸 아래 이동
                }
            }
        }
    }
}

void printBoard(){
    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == EMPTY) cout << "*\t";
            else cout << board[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
 ios::sync_with_stdio(0);
 cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    int score = 0;
    while(true){
        vector<pair<int, int>> pos; // 가장 큰 블록 그룹에 속한 블록의 위치
        int maxGroub = INT_MIN; // 크기가 가장 큰 블록 그룹
        int rainbowCnt = 0; // 가장 큰 블록 그룹의 무지개 블록 수
        pair<int, int> standardBlock = {-1, -1};    // 블록 그룸의 기준 블록의 좌표

        // * 가장 큰 블록 그룹을 찾는다.
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < n; j++){
                if(1 <= board[i][j] && board[i][j] <= m){ // * 일반 블록인 경우
                    queue<pair<int, int>> q;
                    int vis[30][30];
                    fill(&vis[0][0], &vis[29][30], 0);  // 방문 표시 배열 초기화

                    q.push({i, j});
                    vis[i][j] = 1;

                    int size = 1;   // * 현재 블록의 size, 1로 초기화
                    int curRainbowCnt = 0;  // 현재 블록의 무지개 블록 수
                    vector<pair<int, int>> curPos;  // * 그룹에 포함된 블록들의 좌표
                    pair<int, int> curStandardBlock = {i, j};   // ! 현재 그룹의 기준 블록, 시작점으로 초기화
                    curPos.push_back({i, j});

                    // * BFS 수행
                    while(!q.empty()){
                        pair<int, int> cur = q.front(); q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.x + dx[dir];
                            int ny = cur.y + dy[dir];

                            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                            // * 검은색 블록인 경우, 블록이 없는 경우
                            if(board[nx][ny] == -1 || board[nx][ny] == EMPTY || vis[nx][ny] != 0) continue;
                            // * 같은 색 블록이 아닌데, 무지개 블록이 아닌 경우
                            if(board[i][j] != board[nx][ny] && board[nx][ny] != 0) continue;

                            if(board[nx][ny] == 0) {    // * 무지개 블럭인 경우
                                curRainbowCnt++;
                            }else { // * 일반 블럭인 경우
                                if(curStandardBlock.x > nx){    // * 행이 더 작은 경우 UPDATE
                                    curStandardBlock = {nx, ny};
                                }else if(curStandardBlock.x == nx){ // * 행이 같은 경우, 열이 더 작다면 UPDATE
                                    if(curStandardBlock.y > ny)
                                        curStandardBlock = {nx, ny};
                                }
                            }

                            // * 그룹의 사이즈 증가, 그룹에 블록 추가, 방문 표시
                            size++;
                            q.push({nx, ny});
                            curPos.push_back({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }

                    if(size < 2) continue;  // ! 크기가 2보다 작으면 그룹 취급 X

                    // * 그룹 간 비교
                    bool swap = false;  // update가 필요한지 나타내는 flag
                    if(maxGroub < size){    // * 크기가 더 크면 update
                        swap = true;
                    }else if(maxGroub == size){ // * 크기가 같으면
                        // * 무지개 블록의 개수가 가장 많은 블록 그룹
                        if(rainbowCnt < curRainbowCnt){
                            swap = true;
                        }else if(rainbowCnt == curRainbowCnt){ // * 무지개 블록의 개수가 같다면,
                            // * 기준 블록의 행이 가장 큰 것을
                            if(standardBlock.x < curStandardBlock.x) swap = true;
                            else if(standardBlock.x == curStandardBlock.x)  // * 기준 블럭의 행이 같다면, 열이 더 큰 것을
                                if(standardBlock.y < curStandardBlock.y) swap = true;
                        }
                    }

                    if(swap){   // * update가 필요한 경우, 그룹 크기, 무지개 블럭의 개수, 그룹에 포함된 블록의 좌표, 기준 블럭의 좌표 업데이트
                        maxGroub = size;
                        rainbowCnt = curRainbowCnt;
                        pos = curPos;
                        standardBlock = curStandardBlock;
                    }
                }
            }
        }

        // ! 더이상 블록 그룹이 존재하지 않는 경우 break;
        if(maxGroub == INT_MIN) break;

        // * 찾은 블록 그룹에 속한 모든 블록을 제거한다.
        for(auto p : pos) board[p.x][p.y] = EMPTY;
        score += (int) pow(pos.size(), 2);

        cout << "remove\n";
        printBoard();

        cout << "gravity\n";
        // * 중력 작용
        gravity();
        printBoard();

        // * 반시계 방향으로 회전
        cout << "rotate\n";
        rotate();
        printBoard();

        // * 중력 작용
        cout << "gravity\n";
        gravity();
    }
    cout << score << "\n";
}

/*
5 1
0 1 1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-> 9
*/