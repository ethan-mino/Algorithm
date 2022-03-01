#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;    
    vector<int> v;

    for(int i = 0; i < n; i++){
        int c; cin >> c;
        v.push_back(c);
    }
    
    sort(v.begin(), v.end());
    
    cin >> m;

    for(int i = 0; i < m; i++){
        int c; cin >> c;
        int i1 = 0, i2 = v.size();

        while(true){
            int idx = (i1 + i2) / 2;

            if(v[idx] == c){
                cout << 1 << "\n";
                break;
            }
            else if(v[idx] > c){
                i2 = idx;
            }else{
                i1 = idx;
            }


            if(idx == (i1 + i2) / 2){
                cout << 0 << "\n";
                break;
            }
        }
    }
}
