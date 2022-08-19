#include <bits/stdc++.h>
using namespace std;

int seq[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n; 
    for(int i = 0; i < n; i++) cin >> seq[i];

    int st = 0, en = 0; // st는 중복이 없는 구간의 시작점, en는 끝점 
    long long ans = 0; // 경우의 수 
    
    map<int, int> m;    // st ~ en까지의 수열에 포함된 수가 등장하는 횟수를 저장
    m[seq[st]] = 1;

    while(true){
        while(en < n - 1 && m[seq[en + 1]] == 0){   // seq[en + 1]가 기존 수열에 포함되지 않은 경우
            en++; m[seq[en]]++; // en의 길이를 늘려주고, seq[en]을 수열에 포함 시킴
        }
        if(st >= n || en >= n) break;
    
        ans += en - st + 1; // 경우의 수 증가
        m[seq[st]]--; st++; // seq[st]를 수열에서 제외시키고, st를 이동 시킴
    }
    cout << ans << "\n";
}   
