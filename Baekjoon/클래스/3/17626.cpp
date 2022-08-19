#include <bits/stdc++.h>
using namespace std;

int m[500001];  // 메모이제이션을 위한 배열

int recur(int n){
    if(n <= 1) return n;    // 1 또는 0인 경우 n을 반환
    else {
        if(m[n] == -1){ // 메모이제이션이 기록되지 않은 경우
            int ans = INT_MAX;
            for(int i = pow(n, 0.5); i >= 1; i--)   // 선택 가능한 숫자 선택
                ans = min(ans, 1 + recur(n - pow(i, 2)));
            m[n] = ans;
            return ans;
        }else return m[n];  // 기록된 경우 저장된 값을 반환
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    fill(m, m + 50001, -1);
    cout << recur(n);
}     