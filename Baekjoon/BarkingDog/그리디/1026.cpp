// 소요 시간 : 5분

#include <bits/stdc++.h>
using namespace std;

int a[51], b[51];

bool cmp(int x, int y){return x > y;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i]; // a 입력 받음
    for(int i = 0; i < n; i++) cin >> b[i]; // b 입력 받음

    sort(a, a + n, cmp); sort(b, b + n);    // 배열 a, b 정렬 (a는 내림차순, b는 오름차순)
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += a[i] * b[i]; // B의 i번째로 큰 값과 A의 i번째로 작은 값을 곱해줌
    cout << ans << "\n";
}   