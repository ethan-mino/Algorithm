#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m;
        int a[20000], b[20000];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        sort(a, a + n); sort(b, b + m);

        int start = 0, t = 0, accu = 0;
        for(int i = 0; i < n; i++){
            int cur = start;
            while(cur < m && a[i] > b[cur]) cur++;
            // cur >=m 이거나 a <= b[cur]인 경우
            // start ~ cur - 1는 잡아먹을 수 있음
            accu = accu + (cur - start);
            t += accu; start = cur;
        }
        cout << t << "\n";
    }
}  
 
/*
1
5 3
8 1 7 3 1
3 6 1
*/