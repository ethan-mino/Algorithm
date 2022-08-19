#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m;
        int a[20000], b[20000];
        for(int i = 0; i < n; i++) cin >> a[i]; // A 생명체 입력 받음
        for(int i = 0; i < m; i++) cin >> b[i]; // B 생명체 입력 받음
        sort(a, a + n); sort(b, b + m);

        // start는 이전 생명체가 먹지 못했던 B 생명체의 idx
        // t = 전체 쌍의 개수
        // accu는 이전 생명체가 먹을 수 있는 먹이의 개수
        int start = 0, t = 0, accu = 0; 
        for(int i = 0; i < n; i++){
            int cur = start;
            while(cur < m && a[i] > b[cur]) cur++;
            // cur >=m 이거나 a <= b[cur]인 경우 while문 빠져나옴
            // cur - start는 먹이의 개수
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