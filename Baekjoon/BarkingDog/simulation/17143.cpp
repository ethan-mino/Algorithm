#include <bits/stdc++.h>
using namespace std;

typedef struct {int x, y;} pos; // 좌표 정보를 나타내는 구조체
typedef struct{int dir, speed, size; pos p;}shark;  // 상어의 정보를 나타내는 구조체

shark s[100][100];
int dx[4] = {-1, 1, 0, 0};  // 위, 아래, 오른쪽, 왼쪽
int dy[4] = {0, 0, 1, -1};  // 위, 아래, 오른쪽, 왼쪽
int r, c, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> m; // 격자판의 크기, 상어의 수 입력 받음
    for(int i = 0; i < m; i++){ // 상어의 정보 입력 받음
        int r, c, sp, d, z; cin >> r >> c >> sp >> d >> z;
        s[r - 1][c - 1] = {d - 1, sp, z, {r - 1, c - 1}};
    }

    int catched = 0;
    for(int i = 0; i < c; i++){
        // 가장 가까운 상어를 잡는다
        for(int j = 0; j < r; j++){
            if(s[j][i].size != 0){  // 위에서부터 상어를 찾고, 잡음
               catched += s[j][i].size;
               s[j][i].size = 0; 
               break;
            }
        }

        shark ts[100][100]; // 이동한 상어를 저장하는 배열
        shark t = {0, 0, 0, {0, 0}};
        fill(&ts[0][0], &ts[99][100], t);   // ts를 0으로 채움

        // 상어를 이동시킨다
        for(int j = 0; j < r; j++){
            for(int k = 0; k < c; k++){
                shark sk = s[j][k];

                if(sk.size != 0){
                    while(sk.speed > 0){    // speed만큼 이동
                        pos nx = {sk.p.x + sk.speed * dx[sk.dir], sk.p.y + sk.speed * dy[sk.dir]};    // 다음 위치 (speed만큼 이동 시킴)
                        if(nx.x < 0 || nx.y < 0 || nx.x >= r || nx.y >= c){ // 격자판의 경계를 넘는 경우
                            if(nx.x < 0){   //  방향이 위 인 경우
                                sk.speed -= sk.p.x; // 0까지만 이동 시킴
                                sk.p.x = 0; // 0까지만 이동 시킴
                            }else if (nx.y < 0){    // 방향이 왼쪽인 경우
                                sk.speed -= sk.p.y;
                                sk.p.y = 0;
                            }else if(nx.x >= r){    // 방향이 아래인 경우
                                sk.speed -= (r - 1) - sk.p.x;
                                sk.p.x = r - 1;
                            }else { // 방향이 오른쪽인 경우
                                sk.speed -= (c - 1) - sk.p.y;
                                sk.p.y = c - 1;
                            } 

                            if(sk.dir % 2 == 0) sk.dir += 1;    // 방향을 바꿈
                            else sk.dir += -1;
                            continue;
                        }
                        // 격자판의 경계를 넘지 않는 경우
                        sk.p = nx;  // 상어를 이동시키고
                        sk.speed = 0; // 속력 감소
                    }

                    // 이동할 칸에 상어가 없거나, 이동할 칸의 상어보다 이동하는 상어의 크기가 더 큰 경우
                    if(ts[sk.p.x][sk.p.y].size == 0 
                    || (ts[sk.p.x][sk.p.y].size != 0 && ts[sk.p.x][sk.p.y].size < sk.size)){
                        sk.speed = s[j][k].speed;   // 상어의 speed 복구
                        ts[sk.p.x][sk.p.y] = sk; // 상어의 이동된 위치로 옮김
                    }  
                }
            }
        }
        memcpy(s, ts, sizeof(ts));  // s를 ts로 업데이트
    }
    cout << catched;
}

/*
5 5 2
1 1 8 1 2
2 2 7 3 2
*/