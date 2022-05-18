#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
vector<bool> state(4000010, true);

vector<int> sieve(int n){
    // vector<bool>로 두면 1 bit로 최적화되어 공간도 적게 쓰고, cache hit rate가 증가되어 더 빨라짐
    state[1] = false;

    for (int i = 2; i * i <= n; i++){
        if (!state[i]) continue;
        for (int j = i * i; j <= n; j += i)
            state[j] = false;
    }

    for (int i = 2; i <= n; i++)
        if(state[i]) primes.push_back(i);
    return primes;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    if(n == 1) {cout << 0 << "\n"; return 0;}

    vector<int> primes = sieve(n);
    
    int st = 0, en = 0, sum = primes[0];
    int cnt = 0;    //  연속된 소수의 합으로 자연수를 나타낼 수 있는 경우의 수
    
    while(true){
        while(sum < n) sum += primes[++en];

        if(st >= primes.size() || en >= primes.size()) break;
        if(sum == n) cnt++;
        sum -= primes[st]; st++;
    }

    cout << cnt << "\n";
}   