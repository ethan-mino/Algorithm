#include <bits/stdc++.h>
using namespace std;

#define cnt first
#define kind second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    while(n--){
        int m; cin >> m;
        int ans = 1;

        map<string, int> clothes;

        while(m--){
            string c, k; cin >> c >> k;
            auto p = clothes.find(k);

            if(p == clothes.end()){
                clothes.insert({k, 1});
            }else p->second++;
        }
        
        for(auto c : clothes) ans *= (c.second + 1);
            
        cout << ans - 1 << "\n";
    }
}   

/*
1
3
hat headgear
sunglasses eyewear
turban headgear

1
3
mask face
sunglasses face
makeup face
*/