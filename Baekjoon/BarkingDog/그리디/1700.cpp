#include <bits/stdc++.h>
using namespace std;

int order[101];
int use[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 0; i < k; i++) cin >> order[i];

    if(n >= k){cout << 0 << "\n"; return 0;}    // 멀티탭의 구멍 개수가 기기의 총 사용횟수보다 작은 경우 0 출력
    int o_idx = 0, c_idx = 0;    // 마지막에 꽂힌 콘센트의 idx
    while(c_idx < n){   // 멀티탭에 가능한 모든 기기를 꽂음
        if(find(use, use + n, order[o_idx]) == use + n){
            use[c_idx] = order[o_idx];
            c_idx++;
        }
        o_idx++;
    }
    
    int ans = 0;

    // n은 멀티탭 구멍의 개수, k는 전기 용품의 사용 횟수
    for(int i = n; i < k; i++){
        int cur = order[i]; // 사용할 전기 용품

        if(find(use, use + n, cur) == use + n){ // 사용할 기기가 콘센트에 꼽혀있지 않은 경우
            // 콘센트에 꼽혀 있는 기기 중, 앞으로 사용하지 않거나, 가장 나중에 사용할 기기를 선택
            pair<int, int> m = {INT_MIN, INT_MIN};  // {기기를 다음에 사용할 순서, 기기가 꼽혀있는 콘센트 번호}

            for(int j = 0; j < n; j++){    // j는 콘센트 번호
                pair<int, int> c;    // {다음에 사용할 순서, 기기 번호}
                int pos = find(order + i, order + k, use[j]) - order;

                if(pos == k) c = {INT_MAX, j};  // 앞으로 사용하지 않는 경우
                else c = {pos, j};  // 앞으로 사용하는 경우

                if(c.first > m.first) m = c;    // 더 나중에 사용하는 기기인 경우
            }

            use[m.second] = cur;
            ans++;
        }
    }
    cout << ans << "\n";
}


/*
3 12
1 2 3 4 1 2 1 1 1 1 1 3
-> 2

3 4
1 2 3 4
-> 1

3 6
1 2 3 1 2 4
-> 1
*/