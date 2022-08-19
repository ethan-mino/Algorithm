#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n, m;
int board[500][500];

typedef struct {
    vector<pair<int, int>> pos; // 테트로미노를 구성하는 좌표
    int n, m;   // 테트로미노의 가로, 세로 길이
}tet;   // 테트로미노에 대한 정보

tet tets[5] = { 
    {{{0, 0}, {0, 1}, {0, 2}, {0, 3}}, 1, 4},   // - 테트로미노의 각 좌표 및 가로/세로 길이
    {{{0, 0}, {1, 0}, {2, 0}, {2, 1}}, 3, 2},   // L 테트로미노
    {{{0, 0}, {0, 1}, {1, 0}, {1, 1}}, 2, 2},   // ㅁ 테트로미노
    {{{0, 0}, {1, 0}, {1, 1}, {2, 1}}, 3, 2},   // z 테트로미노
    {{{0, 0}, {0, 1}, {0, 2}, {1, 1}}, 2, 3}    // ㅜ 테트로미노
};

// 원점을 start에 두고, 테트로미노를 두었을 때, 칸에 쓰여 있는 수들의 합을 계산하는 함수
int s(pair<int, int> start, vector<pair<int, int>>& pos){  
    int sum = 0;
    for(auto p : pos){
        int x = start.x + p.x; int y = start.y + p.y;   // 테트로미노의 각 좌표에 원점의 좌표를 더해줌
        // 테트로미노가 종이를 벗어나지 않는 경우, 해당 칸의 값을 더해줌
        if(x >= 0 && x < n && y >= 0 && y < m) sum += board[x][y];  
        // 테트로미노가 종이를 벗어나는 경우, int형의 가장 작은 값을 더해서 최댓값이 되지 않도록 함
        else sum += INT_MIN;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    int ans = 0;
    vector<pair<int, int>> tpos(4);
    int tn, tm;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){ // 각각의 좌표를 원점으로 잡음
            for(int k = 0; k < 5; k++){ // 각각의 테트로미노에 대해 반복
                for(int a = 0; a < 4; a++){ // 각각의 시계 방향 회전에 대해 반복
                    for(int symm = 0; symm < 2; symm++){    // 각각의 대칭에 대해 반복
                        copy(tets[k].pos.begin(), tets[k].pos.end(), tpos.begin()); 
                        tn = tets[k].n;
                        tm = tets[k].m;
                        for(int r = 0; r < a; r++){ // 각 좌표를 r번 90도 회전시킴
                            for(int p = 0; p < tpos.size(); p++){
                                int x = tpos[p].x;
                                tpos[p].x = tpos[p].y; tpos[p].y = (tn - 1) - x;
                            }
                            int temp = tn; tn = tm; tm = temp;  // 회전시킨 이후, n과 m 업데이트
                        }

                        if(symm == 1)   // symm이 1인 경우에만 대칭시켜봄
                            for(int p = 0; p < tpos.size(); p++)
                                tpos[p].y = (tm - 1) - tpos[p].y;

                        ans = max(ans, s({i, j}, tpos));    // 변환시킨 테트로미노를 (i, j)에 두고 칸에 쓰여 있는 수들의 합을 계산
                    }
                }
            }
        }
    }
    cout << ans;
}