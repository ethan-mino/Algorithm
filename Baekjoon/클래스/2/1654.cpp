#include <bits/stdc++.h>
using namespace std;

int make(vector<int> & v, int length){
    int cnt = 0;

    for(auto c : v){
        cnt += c / length;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n, m = 0;
    cin >> k >> n;

    vector<int> v;
    for(int i = 0; i < k; i++){
        int c; cin >> c;
        if(m < c) m = c;
        v.push_back(c);
    }
    
    int L = 1, R = m + 1;
    int a;

    while(true){
        a = (L + R) / 2;
        int cnt = make(v, a);

        if(cnt > n){
            L = a;
        }else if(cnt < n){
            R = a;
        }else if(cnt == n){
            break;
        }
    }

    for(int i = a; i <= m; i++){
        
        int cnt = make(v, i);
        
        if(i == m){
            cout << i;
            break;
        }else if(cnt < n){
            cout << i - 1;
            break;
        }
    }
}