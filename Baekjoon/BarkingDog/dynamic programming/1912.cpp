#include <bits/stdc++.h>
using namespace std;

int a[100001], d[100001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];    // 수열 입력 받음
    
    int ans = INT_MIN;
    for(int i = 0; i < n; ++i){
        d[i] = max(a[i], d[i-1] + a[i]);
        ans = max(ans, d[i]);
    }
    cout << ans;
}