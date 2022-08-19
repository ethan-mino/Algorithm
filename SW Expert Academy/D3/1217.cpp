#include <bits/stdc++.h>
using namespace std;

int d[1000];
int re(int x, int y){
    if(y == 0) return 1;
    else if(d[y]) return d[y];
    else{
        if(y&1) d[y] = x * re(x, y - 1);
        else d[y] = re(x, y/2) * re(x, y/2);
        return d[y];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    
    while(t <= 10){
        fill(d, d + 1000, 0);
        int i = 0; cin >> i;
        int x, y; cin >> x >> y;
        int ans = 1;
        cout << "#" << i << " " << re(x, y) << "\n";
        t++;
    }
}