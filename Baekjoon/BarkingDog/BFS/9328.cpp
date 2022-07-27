// Created by rlfalsgh95 on 2022-07-27.

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

char board[102][102];   // 평면도를 저장하는 배열
int vis[102][102];  // BFS에 사용되는 방문 표시 배열
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool is_capital(char c){    // 영문 대문자이면 true 반환
    if('A' <= c && c <= 'Z') return true;
    else return false;
}

bool is_small_letter(char c){ // 영문 소문자이면 true 반환
    if('a' <= c && c <= 'z') return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int h, w; cin >> h >> w;
        fill(&board[0][0], &board[100][101], '.');  // 가장 자리를 '.'으로 채워넣음

        // 평면도 입력 받음, 단, 가장자리는 '.'로 채워주었기 때문에
        // i, j는 1 ~ h, 1 ~ w에 입력 받음
        for(int i = 1; i <= h; i++)
            for(int j = 1; j <= w; j++)
                cin >> board[i][j];

        map<char, bool> has; // 가지고 있는 열쇠 벡터
        string str; cin >> str; //  이미 가지고 있는 열쇠 입력
        if(str != "0") for(int i = 0; i < str.size(); i++) has[str[i]] = 1; // 이미 가지고 있는 열쇠 저장

        int cnt = 0; // 획득한 문서의 개수
        bool end = false;   // 더이상 획득할 수 있는 문서가 없음을 나타내는 flag 변수
        while(!end){
            fill(&vis[0][0], &vis[100][101], 0);
            pair<int, int> st = {0, 0};

            queue<pair<int, int>> q;
            q.push({0, 0});
            vis[st.x][st.y] = 1;
            int key_cnt = 0;  // 개방한 문의 개수, 획득한 문의 개수

            for(int i = 0; i <= h + 1; i++){    // 평면도를 순회하면서, 현재 가지고 있는 열쇠로 열 수 있는 문을 개방함
                for(int j = 0; j <= w + 1; j++){
                    if(is_capital(board[i][j])  // 문이고, 해당 문을 열 수 있는 열쇠를 갖고 있는 경우
                    && has[board[i][j] + 32] == 1)
                        board[i][j] = '.';  // 문의 위치를 빈 공간으로 바꿈
                }
            }

            while(!q.empty()){
                pair<int, int> cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];

                    // 평면도를 벗어나는 경우 (추가한 가장자리도 평면도의 일부로 취급)
                    if(nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1) continue;
                    // 이미 방문했거나, 벽이거나, 열 수 없는 문인 경우
                    if(vis[nx][ny] != 0 || board[nx][ny] == '*' || is_capital(board[nx][ny])) continue;

                    if(board[nx][ny] == '$' // 문서이거나 열쇠인 경우
                    || is_small_letter(board[nx][ny])){
                        if(board[nx][ny] == '$') cnt++; // 문서인 경우 획득한 문서의 개수 증가
                        else {has[board[nx][ny]] = 1; key_cnt++;}    // 열쇠인 경우, 획득했다고 표시
                        board[nx][ny] = '.';    // 해당 위치를 빈 공간으로 표시
                    }

                    q.push({nx, ny});
                    vis[nx][ny] = vis[cur.x][cur.y] + 1;
                }
            }

            if(key_cnt == 0) end = true;   // 개방한 문도 없고, 순회 후, 획득한 열쇠도 없는 경우
        }
        cout << cnt << "\n";
    }
}