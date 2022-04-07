#include <bits/stdc++.h>
using namespace std;

int accu[1024][1025];   // 누적 배열

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n; j++){
            int t, pre; cin >> t;
            if(j == 0) pre = 0; // 가장 왼쪽 원소는 0으로 채움
            else {
                pre = accu[i][j - 1];
                accu[i][j] = t + pre;
            }
        }
    }

    for(int i = 0; i < m; i++){
        int x1, y1, x2, y2, t = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int i = x1 - 1; i < x2; i++)
            t += accu[i][y2] - accu[i][y1 - 1]; // 우측 누적 - 좌측 누적
        cout << t << "\n";
    }
}   
