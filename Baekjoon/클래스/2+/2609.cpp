#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    int s = min(a, b);
    int l = max(a, b);

    if(l % s == 0) return s;
    else return gcd(s, l % s);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << "\n" << lcm(a, b);
}