#include <bits/stdc++.h>
using namespace std;

int board[2][100010];
int d[2][100010];   // d[i][j]는 d[0]부터 d[i]까지의 스티커를 선택했을 때, 스티커 점수의 최댓값 (단, d[i][j] 스티커는 반드시 선택) 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n; cin >> t;
    while(t--){
        fill(&board[0][0], &board[1][100000], 0);   // 2행 N열의 스티커 초기화
        
        cin >> n;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < n; j++)
                cin >> board[i][j]; // 각 스티커의 점수 입력 받음
        
        // 초기값 지정
        d[0][0] = board[0][0]; d[1][0] = board[1][0];
        d[0][1] = board[1][0] + board[0][1]; d[1][1] = board[0][0] + board[1][1];
        
        // 테이블 채우기
        for(int i = 2; i < n; i++){
            d[0][i] = max({d[0][i - 2], d[1][i - 2], d[1][i - 1]}) + board[0][i];
            d[1][i] = max({d[0][i - 2], d[1][i - 2], d[0][i - 1]}) + board[1][i];
        }
        
        cout << max(d[0][n - 1], d[1][n - 1]) << "\n";  // 결과 출력
    }
}   
/*
1
5
50 10 100 20 90
30 50 20 10 60
-> 300
*/