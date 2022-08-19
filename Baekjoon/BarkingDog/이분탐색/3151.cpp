// 소요 시간 : 40분
#include <bits/stdc++.h>
using namespace std;

int c[10010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> c[i];

    sort(c, c + n);
    
    long long ans = 0;
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){ // 두 수를 선택
            int s = c[i] + c[j];    // 두 수의 합
            int l = lower_bound(c + (j + 1), c + n, s * -1) - c;
            int u = upper_bound(c + (j + 1), c + n, s * -1) - c;
            ans += u - l;   // s * -1의 개수를 더해줌
        }
    }
    cout << ans;
}  