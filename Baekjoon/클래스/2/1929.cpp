#include <bits/stdc++.h>
using namespace std;

bool prime[1000001] = {false, false, true, true, false, true, false, true};

void calPrime(int m){
    fill(prime, prime + 1000001, true);
    prime[0] = false; prime[1] = false; prime[4] = false; prime[6] = false; prime[8] = false; prime[9] = false;

    for(int i = 2; i <= m; i++){
        if(prime[i] == true){
            int n = 2;
            while(true){
                if(n * i <= m) {
                    prime[n * i] = false;
                }
                else break;
                n++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    calPrime(n);

    for(int i = m; i <= n; i++){
        if(prime[i]) cout << i << "\n";
    }
}
