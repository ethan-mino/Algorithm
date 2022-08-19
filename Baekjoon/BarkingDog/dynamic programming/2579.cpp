#include <bits/stdc++.h>
using namespace std;

int s[301];    // 각 계단의 점수
int d[301][3];    // d[i] : i번째 계단까지 올라갈 때, 얻을 수 있는 최대 점수와 마지막에 연속된 계단의 개수
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i];
    
    d[1][1] = s[1]; 
    d[2][1] = s[2]; d[2][2] = s[1] + s[2];
    for(int i = 3; i <= n; i++){
        d[i][2] = s[i] + d[i - 1][1];    // 한 칸 전에서 오는 경우
        d[i][1] = s[i] + max(d[i - 2][1], d[i - 2][2]); // 두 칸 전에서 오는 경우
    }
    cout << max(d[n][1], d[n][2]) << "\n";
}   
