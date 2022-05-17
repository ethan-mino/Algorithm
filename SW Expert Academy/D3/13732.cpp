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
        for(int i = 0; i < n; i++){
            cin >> str;
            for(int j = 0; j < str.size(); j++)
                board[i][j] = str[j];
        }

        int pos[4] = {n + 1, n + 1, -1, -1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '#'){
                    pos[0] = min(pos[0], i);
                    pos[1] = min(pos[1], j);
                    pos[2] = max(pos[2], i);
                    pos[3] = max(pos[3], j);
                }
            }
        }

        bool square = true;
        if(pos[2] - pos[0] != pos[3] - pos[1]) square = false;
        for(int i = pos[0]; i <= pos[2]; i++){
            for(int j = pos[1]; j <= pos[3]; j++){
                if(board[i][j] != '#') square = false;
            }
        }

        if(square) cout << "#" << i++ << " yes" << "\n";
        else cout << "#" << i++ << " no" << "\n";
    }
}   
