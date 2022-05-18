#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

char board[30][30];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, i = 1; cin >> t;
    while(t--){
        int n; cin >> n;
        fill(&board[0][0], &board[29][30], 0);

        string str;
        for(int i = 0; i < n; i++){ // 격자 입력 받음
            cin >> str;
            for(int j = 0; j < str.size(); j++)
                board[i][j] = str[j];   
        }

        int pos[4] = {n + 1, n + 1, -1, -1};    // x의 최소 좌표, y의 최소 좌표, x의 최대 좌표, y의 최대 좌표

        for(int i = 0; i < n; i++){ 
            for(int j = 0; j < n; j++){     // x의 최소/최대 좌표, y의 최소/최대 좌표를 갱신함
                if(board[i][j] == '#'){ // 막혀있는 격자인 경우
                    pos[0] = min(pos[0], i);    // x의 최소 좌표
                    pos[1] = min(pos[1], j);    // y의 최소 좌표
                    pos[2] = max(pos[2], i);    // x의 최대 좌표
                    pos[3] = max(pos[3], j);    // y의 최대 좌표
                }
            }
        }

        bool square = true; // 격자판의 막혀있는 칸들이 하나의 정사각형을 이루는지 나타내는 flag 변수

        if(pos[2] - pos[0] != pos[3] - pos[1]) square = false;  // 가로, 세로 길이가 동일한지 확인
        for(int i = pos[0]; i <= pos[2]; i++){  // 정사각형의 내부가 막혀있는 격자로 채워져있는지 확인 
            for(int j = pos[1]; j <= pos[3]; j++)
                if(board[i][j] != '#') square = false;
        }

        cout << "#" << i++;
        if(square) cout << " yes"; else cout << " no";
        cout << "\n";
    }
}   
