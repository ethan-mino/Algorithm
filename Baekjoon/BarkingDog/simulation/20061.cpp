// Created by 길민호 on 2022/08/14.

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int blocks[10][10];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int point = 0;  // point

// 1. 블럭을 놓는다.
// 2. 블럭을 파란색 타일로 이동시킨다.
//  2-1 어느 열이 가득찼는지 확인하고, 해당 열의 블록을 모두 제거한다.
//  2-2 해당 열의 왼쪽에 있는 블록을 모두 오른쪽으로 한 칸 이동시킨다.
//  2-3 0, 1열에 블록이 존재하는 지 확인하고, 존재하는 경우 맨 앞에서 해당 칸 만큼 제거하고, 0, 1칸의 블록 개수 만큼 이동시킨다.
//  2-4 2-1부터 반복한다. (만약 가득찬 열이 존재하지 않는 경우 3번을 진행한다.)
// 3. 블럭을 초록색 타일로 이동시킨다.

void pull(bool row, int st){    // st부터 한 칸씩 앞당기는 함수
    for(int i = st; i >= 4; i--){
        for(int j = 0; j < 4; j++){
            if(row) {
                blocks[i + 1][j] = blocks[i][j];
                blocks[i][j] = 0;
            }
            if(!row) {
                blocks[j][i + 1] = blocks[j][i];
                blocks[j][i] = 0;
            }
        }
    }
}

void remove(bool row, int line){    // line에 해당하는 열 또는 행을 제거하는 함수
    for(int j = 0; j < 4; j++){
        if(row) blocks[line][j] = 0;
        if(!row) blocks[j][line] = 0;
    }
}

// st부터 en까지 감소하면서 행 또는 열이 채워져 있는 지 확인하고, 해당 열 또는 행 번호를 반환하는 함수
int checkLine(bool row, int st, int en){
    for(int i = st; i >= en; i--){
        bool fill = true;
        for(int j = 0; j < 4; j++){
            if(row && blocks[i][j] == 0) fill = false;
            if(!row && blocks[j][i] == 0) fill = false;
        }
        if(fill) return i;
    }
    return -1;
}

// 연한색 보드에 블럭이 존재하는 지 확인하고, 블럭이 포함된 행 또는 열의 개수를 반환하는 함수
int checkSoft(bool row){
    int cnt = 0;
    for(int i = 4; i <= 5; i++){
        bool exist = false;
        for(int j = 0; j < 4; j++){
            if(row && blocks[i][j] == 1) exist = true;
            if(!row && blocks[j][i] == 1) exist = true;
        }
        if(exist) cnt++;
    }
    return cnt;
}

void move(int dir, vector<pair<int, int>> pos) {    // 1 * 1 블록을 dir 방향으로 이동시키는 함수
    int blockNums = pos.size(); // 1 * 1 블록의 개수

    // * pos의 블록을 각각 움직임
    while (true) {
        // ! 블록의 좌표를 실제로 수정해야하기 때문에 iterator 사용
        for (auto block = pos.begin(); block != pos.end(); block++) {
            int nx = block->x + dx[dir];
            int ny = block->y + dy[dir];

            // 블럭 중 하나라도 더이상 움직일 수 없는 경우 움직임을 멈춤
            if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10    // 보드를 벗어나거나
                || blocks[nx][ny] == 1) {   // 앞에 블럭이 있는 경우
                goto exit;
            }
            block->x = nx, block->y = ny;
        }
    }

    exit:
    bool row = (dir == 0);  // 초록색 보드인 경우 true, 파란색인 경우 false

    if(blockNums == 2){ // ! 2개의 블럭이 하나인 경우, 블럭들을 이동시킨 후, 위치를 조정해줌
        if(row && pos[0].y != pos[1].y && pos[0].x != pos[1].x){
            pos[0].x = min(pos[0].x, pos[1].x);
            pos[1].x = min(pos[0].x, pos[1].x);
        }
        if(!row && pos[0].x != pos[1].x && pos[0].y != pos[1].y){
            pos[0].y = min(pos[0].y, pos[1].y);
            pos[1].y = min(pos[0].y, pos[1].y);
        }
    }
    // 블럭들이 이동된 위치에 1을 기록
    for(auto p : pos) blocks[p.x][p.y] = 1;

    while(true){
        int line = checkLine(row, 9, 6);    // 채워져 있는 행 또는 열의 번호를 반환
        if(line == -1) break;   // 채워진 행 또는 열이 없는 경우

        point += 1; // 점수 1 획득

        remove(row, line);  // 해당 행 또는 열을 제거
        pull(row, line - 1);    // 한 칸씩 앞당김
    }

    int cnt = checkSoft(row);   // 연한색 타일에 블록이 올라가 있는 지 확인

    for(int i = 0; i < cnt; i++){   // 연한색 타일에 블록이 올라가 있는 행 또는 열의 개수만큼 반복
        remove(row, 9); // 가장 끝의 열 또는 행을 지움
        pull(row, 8);   // 한 칸씩 앞당김
    }
}

vector<pair<int, int>> put(int type, int x, int y){ // 블럭을 놓는다.
    vector<pair<int, int>> pos;
    pos.push_back({x, y});

    switch (type) {
        case 2 : pos.push_back({x, y + 1});
                 break;
        case 3 : pos.push_back({x + 1, y});
                 break;
    }

    return pos;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int t, x, y; cin >> t >> x >> y;
        vector<pair<int, int>> pos = put(t, x, y); // 블록을 빨간색 타일 위에 놓음

        // ! 가장 바깥에 있는 블록부터 옮기기 위해, 블록을 좌표에 따라 정렬
        sort(pos.begin(), pos.end(), greater<>());
        move(1, pos);   // 파란색 타일로 이동

        put(t, x, y);   // 블록을 빨간색 타일 위에 놓음
        move(0, pos);   // 초록색 타일로 이동
    }

    int cnt = 0;
    for(int i = 0; i < 10; i++)
        for(int j =0 ; j < 10; j++)
            if(blocks[i][j] == 1) cnt++;

    cout << point << "\n";
    cout << cnt << "\n";
}

/*
8
1 1 1
2 3 0
3 2 2
3 2 3
3 1 3
2 0 0
3 2 0
2 2 0

4
2 0 0
1 0 0
2 1 0
3 0 0

4
2 1 1
1 1 1
2 0 0
3 0 0

4
3 0 0
3 0 1
3 0 2
3 0 3
*/