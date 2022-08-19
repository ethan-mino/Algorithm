#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    while(true){
        int c; cin >> c;
        bool flag = true;

        if(c == 0)
            break;
        else{
            int o, t, h, e, n;

            o = c / 10000 % 10;
            t = c / 1000 % 10;
            h = c / 100 % 10;
            e = c / 10 % 10;
            n = c % 10;

            if(c >= 10000){
                if(o != n || t != e) flag = false;                
            }else if(c >= 1000){
                if(t != n || h != e) flag = false;                
            } else if(c >= 100){
                if(h != n) flag = false;
            }else if(c >= 10){
                if(e != n) flag = false;
            }
        }

        if(flag) cout << "yes";
        else cout << "no";
        cout << "\n";
    };
}