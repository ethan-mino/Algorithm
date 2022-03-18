#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[20][20];
int n, m, x, y, k, op;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

deque<int> col = {0, 0, 0, 0};  // 주사위 전개도의 2, 1, 5, 6에 해당
deque<int> row = {0, 0, 0, 0};  // 주사위 전개도의 4, 1, 3, 6에 해당

pair<int, int> rolling(pair<int, int> pos, int move){ // pos에서 move에 따라 주사위를 굴리는 함수
    int nx = pos.x + dx[move - 1]; int ny = pos.y + dy[move - 1]; // 주사위가 굴러갈 지도 위 위치
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) return pos; // 바깥으로 이동하려는 경우 명령을 무시

    if(move == 1){  // 동
        row.push_back(row.front()); 
        row.pop_front();
    }else if(move == 2){    // 서
        row.push_front(row.back()); 
        row.pop_back();
    }else if(move == 3){    // 남
        col.push_back(col.front()); 
        col.pop_front();
    }else if(move == 4){ // 북
        col.push_front(col.back()); 
        col.pop_back();
    }

    if(move == 1 || move == 2) {col[1] = row[1]; col[3] = row[3];} // 주사위 바닥면과 윗면 동기화
    else {row[1] = col[1]; row[3] = col[3];} // 주사위 바닥면과 윗면 동기화

    pos = {nx, ny}; // pos 업데이트

    
    if(board[pos.x][pos.y] == 0) {  // 이동한 칸에 쓰여있는 수가 0이면
        board[pos.x][pos.y] = row[1];   // 주사위의 바닥면의 수가 칸에 복사된다
    }else {  // 0이 아닌 경우에는 
        // 칸에 쓰여 있는 수가 주사위 바닥면으로 복사된다, 주사위 바닥면 동기화
        col[1] = board[pos.x][pos.y];   
        row[1] = board[pos.x][pos.y];   
        board[pos.x][pos.y] = 0;    // 칸에 쓰여 있는 수가 0이 된다
    }
    cout << row[3] << "\n"; // 주사위 윗면 출력

    return pos; // 주사위의 현재 위치 반환
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    pair<int, int> cur = {x, y};

    for(int i = 0; i < k; i++){
        cin >> op;
        cur = rolling(cur, op); // 각 이동에 따라 주사위를 굴림
    }
}   

/*
2 2 0 0 4
0 2
3 4
4 1 3 2
*/