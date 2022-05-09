#include <bits/stdc++.h>
using namespace std;

int rope[100010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for(int i = 0; i < n; i++) cin >> rope[i];  // 로프의 최대 중량 입력 받음
    sort(rope, rope + n);   // 최대 중량을 기준으로 정렬 수행
    int m = INT_MIN;

    for(int i = n - 1; i >= 0; i--){
        // 최대 중량이 높은 로프부터 k개의 로프를 선택했을 때
        // 들 수 있는 물체의 최대 중량이 가장 높은 것을 기록 

        int k = n - i;  // 선택한 로프의 개수
        m = max(m, k * rope[i]);    
    }
    cout << m << "\n";
}  

