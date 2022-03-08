#include <bits/stdc++.h>
using namespace std;

bool isused1[15];   // 열에 대한 상태 배열
bool isused2[40];   // 우상향 대각선에 대한 상태 배열
bool isused3[40];   // 좌상향 대각선에 대한 상태 배열

int n, ans = 0;

void queen(int r){  // 해당 함수는 (N-r) × N인 체스판 위에 r번째 행부터 퀸 n - r개를 서로 공격할 수 없도록 놓는 경우의 수를 구하는 함수
    if(r == n){
        ans++;
    }else{
        for(int c = 0; c < n; c++){ // r은 행, c는 열
            if(!isused1[c] && !isused2[r + c] && !isused3[n - 1 + (r - c)]){
                isused1[c] = true;  // 열을 확인
                isused2[r + c] = true;  // 우상향 대각선을 확인
                isused3[n - 1 + (r - c)] = true;    // 좌상향 대각선을 확인
                queen(r + 1);
                isused1[c] = false;
                isused2[r + c] = false;
                isused3[n - 1 + (r - c)] = false; 
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    queen(0);
    cout << ans;
}