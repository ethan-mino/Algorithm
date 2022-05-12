#include <bits/stdc++.h>
using namespace std;

long long c[5000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i =0 ; i < n; i++) cin >> c[i];

    long long m = LONG_MAX;
    vector<long long> t;

    sort(c, c + n);

    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            long long s1 = c[i] + c[j], s2 = s1 * -1;
            if(binary_search(c + (j + 1), c + n, s2)){
                cout << c[i] << " " << c[j] << " " << s2 << "\n";
                return 0;
            }else{
                int idx = lower_bound(c + (j + 1), c + n, s2) - c;

                if(j < idx - 1 && m > abs(s1 + c[idx - 1])){
                    m = abs(s1 + c[idx - 1]);
                    t = {c[i], c[j], c[idx - 1]};
                    sort(t.begin(), t.end());
                }

                if(idx < n && m > abs(s1 + c[idx])){
                    m = abs(s1 + c[idx]);
                    t = {c[i], c[j], c[idx]};
                    sort(t.begin(), t.end());
                }
            }
        }
    }
    for(auto c : t) cout << c << " ";
}  

/*
5
-2 6 -97 -6 99
*/