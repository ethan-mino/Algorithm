#include <bits/stdc++.h>
using namespace std;

int memory[101][101];
int64_t combination(int n, int m){
    if(n == m || m == 0) return 1;
    else {
        if(memory[n][m] == 0) {
            memory[n][m] = combination(n - 1, m - 1) + combination(n - 1, m);
        }
        return memory[n][m];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    cout << combination(n, m) << "\n";
}   