#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    while(n--){
        for(int i = n + 1; i > 0; i--)
            cout << "*";
        cout << "\n";
    }
}