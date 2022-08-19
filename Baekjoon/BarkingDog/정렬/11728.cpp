#include <bits/stdc++.h>
using namespace std;

int a[1000001], b[1000001], c[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int ap = 0, bp = 0, cp = 0; 
    while(ap != n && bp != m){
        if(a[ap] > b[bp]) c[cp++] = b[bp++];  // a가 더 큰 경우
        else c[cp++]  = a[ap++]; // b가 더 큰 경우
    }

    if(ap == n){
        for(int i = bp; i < m; i++) c[cp++] = b[i];
    }else{
        for(int i = ap; i < n; i++) c[cp++] = a[i];
    }

    for(int i = 0; i < (n + m); i++) cout << c[i] << " ";
    cout << "\n";
}   
