#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int pop[20][20], board[20][20]; // P는 각 구역의 인구 수를 나타냄, board는 각 칸의 선거구를 나타냄
int n;

// 좌표 p가 배열의 범위를 벗어나는지 확인하는 함수
bool in(pair<int, int> p){
    if(p.x < 0 || p.x >= n || p.y < 0 || p.y >= n) return false;
    else return true;
}

// 기준점이 s이고 경계의 길이가 d1, d2일 때, 좌표 p의 경계선 포함 여부를 반환 
bool edge(pair<int, int> s, pair<int, int> p, int d1, int d2){  
    int x = s.x, y = s.y, r = p.x, c = p.y;
    if((x-r == y-c && r <= x+d2 && c <= y+d2 && r >= x && c >= y) 
    || (r-x == y-c && r <= x+d1 && c >= y-d1 && r >= x && c <= y) 
    || (x+d1+d2-r == y-d1+d2-c && r >= x+d1 && c>= y-d1 && r <= x+d1+d2 && c <= y-d1+d2) 
    || x+d1+d2-r == c-(y-d1+d2) && r >= x+d2 && c <= y + d2 && r <= x+d1+d2 && c >= y-d1+d2){
        return true;
    }else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> pop[i][j];

    int ans = INT_MAX;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){ // 각각의 기준점에 대해 반복
            for(int d1 = 1; d1 <= n; d1++){
                for(int d2 = 1; d2 <= n; d2++){ // 각각의 d1,d2 쌍에 대해 반복
                    if(!in({x+d1, y-d1}) || !in({x+d2, y+d2}) || !in({x+d2+d1, y-d1+d2})) continue; // 경계선의 꼭짓점이 배열의 범위를 벗어나는 경우
                    int s[5] = {0, 0, 0, 0, 0}; // 각 선거구의 인구수 합 배열
                    fill(&board[0][0], &board[19][20], 0);

                    for(int r = 0; r < n; r++)
                        for(int c = 0; c < n; c++)
                            if(edge({x, y}, {r, c}, d1, d2))    // 경계선인 경우
                                board[r][c] = 5; 

                    for(int r = 0; r < n; r++){
                        for(int c = 0; c < n; c++){
                            if(edge({x, y}, {r, c}, d1, d2) && ((r <= x + d1 && c < y) || (r > x+d1 && c < y-d1+d2))){    // 경계선이고, 경계선의 왼쪽 부분인 경우
                                pair<int, int> cur = {r, c};
                                while(true){    // 오른쪽으로 한 칸씩 이동하면서 5를 저장, 경계선을 만나면 멈춤
                                    pair<int, int> nx = {cur.x, cur.y + 1};
                                    if(nx.y > n || board[nx.x][nx.y] == 5) break;
                                    else{board[nx.x][nx.y] = 5; cur = nx;}
                                }
                            }

                            if(board[r][c] == 0){   // 경계선이 아닌 경우
                                if(r < x+d1 && c<=y) {board[r][c] = 1; s[0]+=pop[r][c];}    // 1번 선거구인 경우
                                else if(r <= x+d2 && y < c) {board[r][c] = 2; s[1]+=pop[r][c];} // 2번 선거구인 경우
                                else if(x+d1 <= r&& c <y-d1+d2) {board[r][c] = 3; s[2]+=pop[r][c];} // 3번 선거구인 경우
                                else if(x+d2 < r && y-d1+d2 <= c) {board[r][c] = 4; s[3]+=pop[r][c];}   // 4번 선거구인 경우
                            }else{  // 5번 선거구인 경우
                                s[4] += pop[r][c];
                            }
                        }
                    }

                    int d = *max_element(s, s + 5) - *min_element(s, s + 5);    // 인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이
                    ans = min(ans, d);
                }
            }
        }
    }
    cout << ans;
}

/*
7
1 2 3 4 1 6 1
7 8 9 1 4 2 1
2 3 4 1 1 3 1
6 6 6 6 9 4 1
9 1 9 1 9 5 1
1 1 1 1 9 9 1
1 1 1 1 9 9 1
*/