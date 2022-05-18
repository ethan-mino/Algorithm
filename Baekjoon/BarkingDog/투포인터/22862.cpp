#include <bits/stdc++.h>
using namespace std;

int seq[1000010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> seq[i];
    
    int st = 0, en = 0; // 구간의 시작점과 끝점
    int cnt = (seq[st]&1) ? 1 : 0;  // 현재 구간의 홀수 개수
    int m = 0;    // 부분 수열 중 가장 긴 길이

    while(true){
        while(en < n - 1){  // en을 이동시킬 수 있는 경우
            if(seq[en + 1]&1) { // 다음 요소가 홀수인 경우
                if(cnt < k)  cnt++; // 홀수를 삭제할 수 있는 경우, 홀수를 포함시킴
                else break; // 홀수를 삭제할 수 없는 경우, en의 이동을 멈춤
            }
            en++;   // en을 이동시킴
        }

        if(st >= n || en >= n) break;
        m = max(m, en - st + 1 - cnt);  // 부분 수열의 가장 긴 길이

        if(seq[st]&1) cnt--;    // 구간의 시작점이 홀수인 경우, 홀수의 개수를 줄임
        st++;   // 시작점을 한 칸 이동 시킴
    }
    cout << m;
}   

/*
7 4
2 4 6 8 10 12 14
-> 7

4 0
1 3 5 7
-> 0
*/