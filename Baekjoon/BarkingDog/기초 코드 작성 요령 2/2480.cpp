#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;

    if((a==b) && (b == c)){
        cout << 10000 + a * 1000 << "\n"        ;
    }else if(a != b && b != c && a != c){
        cout << max({a, b, c}) * 100 << "\n";
    }else{
        if(a == b)
            cout << 1000+(a * 100) << "\n";
        else if(b == c)
            cout << 1000+(b * 100) << "\n";
        else 
            cout << 1000+(c * 100) << "\n";
    }
    
}

/* 
    int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && b == c) cout << 10000 + a*1000;
    else if(a == b || a == c) cout << 1000 + a*100;
    else if(b == c) cout << 1000 + b*100;
    else cout << max({a,b,c}) * 100;
    }
*/

/*
    int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    if(a[0] == a[2]) cout << 10000 + a[0]*1000; // 세 수가 동일
    else if(a[0] == a[1] || a[1] == a[2]) cout << 1000 + a[1]*100; // 두 수가 동일
    else cout << a[2]*100;
    }
*/