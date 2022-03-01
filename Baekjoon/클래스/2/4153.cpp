#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        int a, b, c;
        cin >> a >> b >> c;

        if(!a && !b && !c){
            break;
        }else{
            string f = "wrong";
            string s = "right";
            
            if(a > b && a > c){
                if(pow(a, 2) == pow(b, 2) + pow(c, 2)) cout << s << "\n";
                else cout << f << "\n";
            }else if(b > a && b > c){
                if(pow(b, 2) == pow(a, 2) + pow(c, 2)) cout << s << "\n";
                else cout << f << "\n";
            }else if(c > b && c > a){
                if(pow(c, 2) == pow(b, 2) + pow(a, 2)) cout << s << "\n";
                else cout << f << "\n";
            }else{
                cout << s << "\n";
            }
        }
    }
}

