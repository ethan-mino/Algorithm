#include <bits/stdc++.h>
using namespace std;

int seq[200010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> seq[i];

    int st =0, en = 0;
    map<int, int> m;
    m[seq[st]] = 1;

    int len = 0;
    while(true){
        while(m[seq[en + 1]] < k && en < n - 1){
            en++; m[seq[en]]++;
        }

        len = max(len, en - st + 1);
        if(st >= n || en >= n) break;
        m[seq[st]]--;
        st++;
    }

    cout << len << "\n";
}   