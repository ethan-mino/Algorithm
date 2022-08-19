#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, i = 1; cin >> t;
    while(t--){
        int n, d; cin >> n >> d;
        
        cout << "#" << i++ << " " << ceil((double)n / (2 * d + 1)) << "\n";
    }
    return 0;
}   