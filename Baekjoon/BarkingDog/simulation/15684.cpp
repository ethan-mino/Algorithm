#include <bits/stdc++.h>
using namespace std;

#define b first
#define a second

int board[30][10];  // board[b-1][a-1]은 b번과 b+1번을 연결하는 a번째 가로선의 유무
int n, m, h, ans = INT_MAX;

bool ladder(int board[][10]){
    for(int i = 0; i < h; i++)  // 두 가로선이 연속하는지 확인
        for(int j = 0; j < (n - 2); j++)
            if(board[i][j] == 1 && board[i][j + 1] == 1)
                return false;

    for(int i = 0; i < n; i++){
        pair<int, int> cur = {0, i};    // 사다리가 cur의 왼쪽 상단에 위치 한다고 가정
        while(true){
            if(cur.b < 0 || cur.a < 0 || cur.b >= h || cur.a >= n) break;   // 사다리를 벗어나는 경우 더이상 진행하지 않음
            
            if(board[cur.b][cur.a] == 1)   // 오른쪽 가로선이 존재하는 경우
                cur = {cur.b, cur.a + 1};   // 오른쪽으로 이동
            else if(cur.a - 1 >= 0 && cur.a - 1 < n && board[cur.b][cur.a - 1] == 1)    // 왼쪽 가로선이 존재하는 경우
                cur = {cur.b, cur.a - 1};   // 왼쪽으로 이동
            
            cur = {cur.b + 1, cur.a};   // 아래로 이동
        }
        if(cur.a != i) return false; // i번 세로선의 결과가 i가 아닌 경우
    }
    return true;    // 모든 세로선의 결과가 i번이 나왔으므로 true 반환
}

void back(int board[30][10], int line, int num){  // line은 세로선의 번호(0 ~ n-1), num은 남은 가로선의 개수
    if(num > 0 && line < n){    // 배치할 가로선이 남아있고, 존재하는 세로선인 경우
        for(int i = 0; i <= num; i++){  // line번과 line + 1번 라인을 잇는 가로선 i개를 선택
            vector<int> np; // Combination을 위한 벡터
            for(int j = 0; j < h - i; j++) np.push_back(0); // 가로선은 h개 가능
            for(int j = 0; j < i; j++) np.push_back(1); // 가로선 i개 선택

            do{
                int temp[30][10]; memcpy(temp, board, sizeof(temp));
                bool overlap = false; 

                for(int j = 0; j < np.size(); j++){ // 추가된 가로선이 기존에 있던 가로선(입력 받은 가로선)과 겹치는 지 확인
                    if(np[j] == 1){
                        if(temp[j][line] == 1) overlap = true;
                        else temp[j][line] = 1;
                    }
                }

                if(!overlap){   // 하나라도 겹치지 않는다면
                    // 사다리 타기 수행 결과 모든 세로선의 결과가 i가 나온 경우 ans를 업데이트
                    if(ladder(temp)) ans = min(ans, 3 - (num - i)); 
                    // 그렇지 않은 경우 남은 가로선의 개수를 줄이고, 다음 라인으로 옮김
                    else back(temp, line + 1, num - i);
                }
            }while(next_permutation(np.begin(), np.end())); // 현재 라인에서 가로선을 i개 선택하는 Combination의 각 경우의 수에 대해 반복
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> h;
    
    while(m--){
        int x, y; cin >> x >> y;
        board[x - 1][y - 1] = 1;    // 입력된 가로선을 배열에 표시
    }
    
    back(board, 0, 3);
    cout << ((ans == INT_MAX) ? -1 : ans);
}

