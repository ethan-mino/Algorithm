#include <bits/stdc++.h>
using namespace std;

int d[1001][4]; // d[i][j]는 i번째 집의 색을 j로 칠할 때, 모든 집을 칠하는 비용의 최솟값
int c[1001][1001];  // c[i][j]는 i번째 집의 색을 j로 칠할 때의 비용
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 3; j++)
            cin >> c[i][j]; // 각 집을 빨강, 초록, 파랑으로 칠하는 비용

    for(int i = 1; i <= 3; i++) d[1][i] = c[1][i];  // 1번째 집의 색을 i으로 칠할 때의 비용(초기값)
    for(int i = 2; i <= n; i++){
        // i번째 집을 빨강으로 칠했을 때 모든 집을 칠하는 비용의 최솟값은, 
        // i - 1번째 집의 색을 초록 또는 파랑으로 칠했을 때, 모든 집을 칠하는 비용의 최솟값 + i번째 집을 빨강으로 칠하는 비용
        d[i][1] = c[i][1] + min(d[i - 1][2], d[i - 1][3]); 
        d[i][2] = c[i][2] + min(d[i - 1][1], d[i - 1][3]); // i번째 집을 초록으로 칠하는 경우
        d[i][3] = c[i][3] + min(d[i - 1][1], d[i - 1][2]); // i번째 집을 파랑으로 칠하는 경우
    }
    cout << min({d[n][1], d[n][2], d[n][3]});
}   
