#include <bits/stdc++.h>
using namespace std;

int card1[20000003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c, a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        card1[a+10000000]++;
    }

    cin >> c;
    while(c--){
        cin >> a;
        cout << card1[a+10000000] << " ";
    }
}
