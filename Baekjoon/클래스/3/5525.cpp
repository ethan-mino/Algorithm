#include <bits/stdc++.h>
using namespace std;

char c[2] = {'I', 'O'};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; string str; 

    cin >> n >> m >> str;
    int ans = 0;
    int cur = 0, cnt = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == c[cur]){   // 현재 순서에 맞는 경우
            cnt++; cur = 1 - cur;   // 올바른 순서의 개수 증가, cur는 다음 순서
        }else{
            if(cnt >= 2*n + 1) ans += 1 + ((cnt - (2*n + 1)) / 2);  // Pn이 포함된 개수 증가
            if(str[i] == 'I') {cur = 1; cnt = 1;}   // I인 경우
            else {cur = 0; cnt = 0;}    // O인 경우
        }
    }
    if(cnt >= 2*n + 1) ans += 1 + ((cnt - (2*n + 1)) / 2);
    cout << ans;
}   

/*
1
3
IOI
*/