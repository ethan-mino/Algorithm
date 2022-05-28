#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int BOARD_SIZE = 100;
char board[BOARD_SIZE][BOARD_SIZE];

bool isp(bool col, pair<int, int> st, int len){
    bool is = true;
    
    for(int i = 0; i < len / 2; i++){
        if(col){
            pair<int, int> end = {st.x + len - (i + 1), st.y};
            if(end.x >= BOARD_SIZE || board[st.x + i][st.y] != board[end.x][end.y]) is = false;
        }else{
            pair<int, int> end = {st.x, st.y + len - (i + 1)};
            if(end.y >= BOARD_SIZE || board[st.x][st.y + i] != board[end.x][end.y]) is = false;
        }
        if(!is) break;
    }
    return is;
}

// 1 2 3 4
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    vector<int> a;
    while(t <= 10){
        int ans = 0;
        int i = 0; cin >> i;
        for(int i = 0; i < BOARD_SIZE; i++)
            for(int j = 0; j < BOARD_SIZE; j++)
                cin >> board[i][j];
        
        for(int i = 0; i < BOARD_SIZE; i++){
            for(int j = 0; j < BOARD_SIZE; j++){
                for(int len = 1; len <= BOARD_SIZE; len++){
                    if(isp(true, {i, j}, len)) ans = max(ans, len);
                    if(isp(false, {i, j}, len)) ans = max(ans, len);
                }

            }
        }
        
        cout << "#" << t++ << " " << ans << "\n";
    }
}

/*

*/