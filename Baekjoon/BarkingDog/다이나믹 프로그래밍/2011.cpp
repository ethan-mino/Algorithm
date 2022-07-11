// Created by 길민호 on 2022/07/10.

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000
string s;
int d[5010]; // d[len]는 0번째 idx부터 길이가 len인 암호의 경우의 수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int size = s.size();

    if(s[0] == '0'){
        cout << 0; return 0;
    }

    d[0] = 1, d[1] = 1;
    for(int i = 2; i <= size; i++){
        // 현재 글자와 앞 글자를 연결했을 때, 10 ~ 26 사이의 숫자인 경우
        if(s[i - 1] > '0') d[i] = d[i - 1] % MOD;
        int n = 10 * (s[i - 2] - '0') + (s[i - 1] - '0');

        if(n >= 10 && n <= 26) {
            d[i] = (d[i] + d[i - 2]) % MOD;
        }
    }
    cout << d[size];
}

/*
0
-> 0

1010
-> 1

10
-> 1

123
-> 3

666666
-> 1

14
-> 2

51
-> 1
*/