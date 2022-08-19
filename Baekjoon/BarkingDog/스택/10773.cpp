#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> s;
    int k; cin >> k;

    for(int i = 0; i < k; i++){
        int n; cin >> n;
        if(n){
            s.push_back(n);
        }else{  //
            s.pop_back();
        }
    }
    cout << accumulate(s.begin(), s.end(), 0);
}
