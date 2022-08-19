#include <bits/stdc++.h>
using namespace std;

int seq[100010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s; cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> seq[i];

    int st = 0, en = 0, sum = seq[0];   // st는 구간의 시작점, en은 끝점, sum은 구간합
    while(sum < s) sum += seq[++en];    // st가 0일 때, sum >= S를 만족하는 en를 찾음
    int m = en - st + 1;    // m은 sum >= S인 구간인 최소 길이

    if(en >= n){    // S를 만드는 부분합이 존재하지 않을 경우
        cout << 0 << "\n";
    }else{
        while(true){
            sum -= seq[st]; st++;   // 시작점 이동
            if(sum < s)   // st번째 수를 선택하지 않았을 때, 구간합이 S보다 크거나 같지 않으면 en을 늘려감
                while(sum < s) sum += seq[++en];

            if(st >= n || en >= n) break;
            m = min(m, en - st + 1);
        }
        cout << m << "\n";
    }
}   


/*
3 100
1 2 3
-> 0

1 100
100
-> 1

2 103
100 3
-> 2
*/