#include <bits/stdc++.h>
using namespace std;

long long stock[1000010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        fill(stock, stock + n, 0);
        for(int i = 0; i < n; i++) cin >> stock[i]; // 날 별 주가 입력 받음.

        int m[1000010];   // m[d]는 m[d]부터 m[n - 1]까지 중 가장 큰 수의 idx를 저장
        m[n - 1] = n - 1;
        for(int day = n - 2; day >= 0; day--){  // m 배열 채워줌
            if(stock[day] > stock[m[day + 1]]) m[day] = day;
            else m[day] = m[day + 1];
        }

        long long ans = 0;
        for(int day = 0; day < n; day++){
            if(stock[day] < stock[m[day]])  // stock[d] < stock[m]인 m이 존재하면, d일에 주식을 사고 m일에 주식을 판다.
                ans+= stock[m[day]] - stock[day];
        }
        cout << ans << "\n";
    }
}