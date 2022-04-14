#include <bits/stdc++.h>
using namespace std;

#define num first
#define pre second

pair<int, int> d[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    d[1] = {0, -1}; 
    for(int i = 2; i <= n; i++){
        d[i] = {d[i - 1].num + 1, i - 1};   
        // 3으로 나누어떨어지는 경우, 1 빼기 연산과 3으로 나누기 연산 중 더 적은 연산으로 1을 만들 수 있는 연산을 수행
        if(i % 3 == 0) if(d[i].num > d[i/3].num + 1) d[i] = {d[i/3].num + 1, i / 3};     
        // 2으로 나누어떨어지는 경우, 1 빼기 연산과 2로 나누기 연산 중 더 적은 연산으로 1을 만들 수 있는 연산을 수행
        if(i % 2 == 0) if(d[i].num > d[i/2].num + 1) d[i] = {d[i/2].num + 1, i / 2};
    }

    cout << d[n].num << "\n" << n << " ";
    int cur = n;
    // n부터 연산의 경로를 추적
    while(d[cur].pre != -1){
        cout << d[cur].pre << " ";
        cur = d[cur].pre;
    }
}   
