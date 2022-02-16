#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int max = 0;
    int idx = 0;

    for(int i = 0; i < 9; i++){
        int n;
        cin >> n;
        if(max < n){
            max = n;
            idx = i + 1;
        }
    }
    cout << max << "\n" << idx;
}
