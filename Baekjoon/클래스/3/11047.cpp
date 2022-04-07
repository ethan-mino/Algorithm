#include <bits/stdc++.h>
using namespace std;

int n, k, ans = INT_MAX;
vector<int> coin;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i =0 ; i < n; i++){
        int c; cin >> c; coin.push_back(c);
    }

    int r = k, ans = 0;
    for(int i = coin.size() - 1; i >= 0; i--){  // 가치가 큰 동전부터 선택
        if(r >= coin[i]){   // 남은 가치가 현재 동전의 가치보다 크거나 같은 경우
            ans += (r / coin[i]);
            r -= (r / coin[i]) * coin[i];   // 현재 동전을 최대한 많이 선택
        }
    }

    cout << ans;
}   
