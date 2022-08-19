#include <bits/stdc++.h>
using namespace std;

int ho[200010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c; cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> ho[i];
    
    sort(ho, ho + n);
    for(int i = 0; i < n; i++) cout << ho[i] << " ";
    cout << "\n";

    int m = INT_MIN;
    vector<int> t;
    // for(int i = 0; i < n; i++){
    //     for(int j = i + 1; j < n; j++){
    //         for(int k = j + 1; k < n; k++){
    //             for(int h = k + 1; h < n; h++){ // i, j, k, h
    //                 if(m <= min({ho[j] - ho[i], ho[k] - ho[j], ho[h] - ho[k]})){
    //                     m = min({ho[j] - ho[i], ho[k] - ho[j], ho[h] - ho[k]});
    //                     t = {ho[i], ho[j], ho[k], ho[h]};
    //                 }
    //             }
    //         }
    //     }
    // }

    // for(int i = 0; i < n; i++){
    //     for(int j = i + 1; j < n; j++){
    //         for(int k = j + 1; k < n; k++){
    //             if(m <= min({ho[j] - ho[i], ho[k] - ho[j]})){
    //                 m = min({ho[j] - ho[i], ho[k] - ho[j]});
    //                 t = {ho[i], ho[j], ho[k]};
    //             }
    //         }
    //     }
    // }

    // for(auto c : t) cout << c << " ";
    // cout << "\n";
}   

/*
5 3
1 2 4 8 9

15 4
1 2 4 8 9 16 18 21 22 31 33 41 42 44 47 


10
1 2 3 4 5 6 7 8 9 1000
*/