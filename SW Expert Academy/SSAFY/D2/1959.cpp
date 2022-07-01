#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[30], b[30];
    int t, n, m; cin >> t;
    int cur = 1;
    while(t--){
        cin >> n >> m;

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];

        int s = min(n, m);
        int l = max(n, m);

        int sum = INT_MIN;
        for(int st = 0; st <= l - s; st++){

            int temp = 0;
            for(int i = 0; i < s; i++){
                if(n > m){  // a가 더 긴 경우
                    temp += b[i] * a[st + i];
                }else{  // b가 더 긴 경우
                    temp += a[i] * b[st + i];
                }
            }
            sum = max(sum, temp);
        }
        cout << "#" << cur++ << " " << sum << "\n";
    }
}