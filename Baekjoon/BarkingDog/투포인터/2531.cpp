#include <bits/stdc++.h>
using namespace std;

int s[30010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d, k, c; cin >> n >> d >> k >> c;
    for(int i =0 ; i < n; i++) cin >> s[i];

    int st = 0, en = 0; // // st는 처음 선택한 초밥의 번호, en은 마지막에 선택한 초밥의 번호
    int cnt = 1, kind = 1; // cnt는 선택한 초밥의 개수, kind는 초밥 종류의 개수
    
    map<int, int> m;    // 선택한 초밥들 각각의 개수
    m[s[st]] = 1;
    int ans = 0;

    while(true){
        while(cnt < k && !(cnt > 1 && st == (en + 1) % n)){
            en = (en + 1) % n; // 마지막에 선택한 초밥의 번호 증가
            if(m[s[en]] == 0) kind++;   // 처음 선택한 종류인 경우 Kind 증가
            m[s[en]]++; // 해당 초밥의 개수 증가
            cnt++;  // 선택한 초밥의 개수 증가
        }
        
        if(cnt == k) { // k개의 초밥을 연속해서 먹는 경우, 무료 초밥 제공
            if(m[c] == 0) kind++; // 무료 초밥이 새로운 종류인 경우 kind 증가
            m[c]++; // 무료 초밥의 개수 증가
        } 

        ans = max(ans, kind);

        m[s[st]]--; // 처음에 선택한 초밥의 개수 감소
        cnt--;  // 선택한 초밥의 개수 감소
        
        if(cnt < k && m[c] > 0) m[c]--; // 선택한 초밥의 개수를 줄이고, 개수가 k보다 작으면, 무료 초밥의 개수 감소
        if(m[s[st]] == 0) kind--;   // 처음에 선택한 초밥의 개수가 0이 된 경우, kind 감소
        if(s[st] != c && m[c] == 0) kind--; // 무료 초밥의 개수가 0이 된 경우, Kind 감소

        st = (st + 1) % n;  // 시작점 한 칸 이동
        if(st == 0) break;
    }
    cout << ans << "\n";
}   

/*
0 1 2 3
1 1 1 1
*/

/*
4 1 4 2
1 1 1 1

4 1 4 1
1 1 1 1
*/