// Created by 길민호 on 2022/08/15.

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define dir first
#define pos second
#define sharkNum first
#define time second
typedef pair<int, int> pii;

int n, m, k;
pii board[30][30];

int dx[4] = {-1, 1, 0, 0};  // 위, 아래, 왼쪽, 오른쪽
int dy[4] = {0, 0, -1, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    vector<pair<int, pii>> sharks(m);
    int prior[m][4][4];

    for(int i = 0; i < n; i++){
        for(int j = 0, s; j < n; j++){
            cin >> s;
            if(s > 0) {
                sharks[s - 1] = {0, {i, j}};    // * 상어의 번호는 0 ~ 4
                board[i][j] = {s - 1, k};   // * {냄새를 뿌린 상어의 번호, 냄새가 사리지기까지의 시간}
            }else{
                board[i][j] = {-1, 0};  // * 냄새를 뿌리지 않은 곳은 {-1, 0} 초기화
            }
        }
    }

    for(int i = 0; i < m; i++){ // 각 상어의 방향을 입력 받는다.
        cin >> sharks[i].dir;
        sharks[i].dir--;    // * 상어의 방향을 0 ~ 4로 맞춰줌
    }

    for(int i = 0; i < m; i++){ // 각 상어의 방향 우선순위를 입력 받는다.
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                cin >> prior[i][j][k];
                prior[i][j][k]--;
            }
        }
    }


    // * 1. 상어를 현재 방향의 우선 순위에 따라 인접한 칸 중 아무 냄새가 없는 칸으로 이동.
    // *    1-1. 만약 인접한 칸 중, 아무 냄새가 없는 칸이 없다면, 자신의 냄새가 있는 칸으로 이동
    // * 2. 이동한 후에 한 칸에 여러 마리의 상어가 남아 있으면, 가장 작은 번호를 가진 상어를 제외
    // * 3. 각 칸의 냄새의 남은 시간을 업데이트
    // ! 4. 각 상어가 이동한 칸에 냄새를 뿌림 (업데이트한 후에 냄새를 뿌려주어야 함.)

    int t = 0;
    while(t <= 1000){
        vector<int> remains;
        for(int i = 0; i < m; i++) if(sharks[i].dir != -1) remains.push_back(i);
        if(remains.size() == 1 && remains[0] == 0) break;

        // ! 모든 상어는 동시에 움직여야 함
        pii move[m];   // 각 상어가 이번 타임에 냄새를 뿌릴 칸
        int nxDir[m];   // 상어의 다음 방향
        for(int i =0; i < m; i++) move[i] = {-1, -1};

        for(int i = 0; i < m; i++){ // 각 상어가 움직임
            if(sharks[i].dir != -1){    // 쫒겨난 상어가 아니라면
                for(int j = 0; j < 4; j++){ // 우선순위에 따라 인접한 칸을 확인
                    int priorDir = prior[i][sharks[i].dir][j];
                    int nx = sharks[i].pos.x + dx[priorDir];
                    int ny = sharks[i].pos.y + dy[priorDir];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if(board[nx][ny].sharkNum != -1) continue; // 이미 상어가 냄새를 뿌린 곳이라면
                    move[i] = {nx, ny};
                    nxDir[i] = priorDir;
                    break;
                }
            }
        }

        for(int i = 0; i < m; i++){ // 각 상어가 움직임
            if(sharks[i].dir != -1  // 쫒겨난 상어가 아니고,
            && move[i].x == -1 && move[i].y == -1){ // 인접한 좌표가 모두 상어가 냄새를 뿌린 곳이었다면,
                for(int j = 0; j < 4; j++){ // 우선순위에 따라 인접한 칸을 확인
                    int priorDir = prior[i][sharks[i].dir][j];
                    int nx = sharks[i].pos.x + dx[priorDir];
                    int ny = sharks[i].pos.y + dy[priorDir];

                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if(board[nx][ny].sharkNum != i) continue; // 자신이 뿌린 냄새가 아니라면
                    move[i] = {nx, ny};
                    nxDir[i] = priorDir;
                    break;
                }
            }
        }

        for(int shark1 = 0; shark1 < m; shark1++){
            for(int shark2 = shark1 + 1; shark2 < m; shark2++){
                if(sharks[shark1].dir != -1 && sharks[shark2].dir != -1){   // 두 성어 모두 쫒겨난 상어가 아니라면
                    if(move[shark1].x == move[shark2].x
                       && move[shark1].y == move[shark2].y){
                        sharks[shark2].dir = -1;    // 두 상어가 같은 곳으로 이동한 경우, 낮은 번호를 가진 상어는 쫒겨남
                    }
                }
            }
        }

        for(int i =0; i < n; i++){  // 냄새의 남은 시간 update
            for(int j = 0; j < n; j++){
                if(board[i][j].time == 1) { // 1초 남은 경우
                    board[i][j].sharkNum = -1;  // 상어 번호를 -1로 설정
                    board[i][j].time = 0;   // 남은 시간을 0으로 설정
                }else{
                    board[i][j].time--; // 남은 시간을 1 줄임
                }
            }
        }

        for(int i = 0; i < m; i++){
            if(sharks[i].dir != -1){
                int nx = move[i].x;
                int ny = move[i].y;
                board[move[i].x][move[i].y] = {i, k};   // 해당 좌표에 상어가 냄새를 뿌림
                sharks[i] = {nxDir[i], {nx, ny}};
            }
        }
        t++;
    }

    // ! 단, 1,000초가 넘어도 다른 상어가 격자에 남아 있으면 -1을 출력
    if(t > 1000) cout << -1;
    else cout << t << "\n";
}