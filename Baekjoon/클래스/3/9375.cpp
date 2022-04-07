#include <bits/stdc++.h>
using namespace std;

#define cnt first
#define kind second

int ans = 0;
vector<pair<int, string>> clothes;

// th - 1은 현재까지 선택한 의상의 개수, n은 선택 가능한 의상 종류의 개수, pre은 이전 단계에서 선택한 의상의 번호
int combination(int n, int r){
    if(n == r || r == 0) 
        return 1; 
    else 
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    while(n--){
        int m; cin >> m;
        clothes.clear();
        
        while(m--){
            string c, k; cin >> c >> k;
            bool exist = false;
            for(int i = 0; i < clothes.size(); i++)  if(clothes[i].kind == k) {exist = true; clothes[i].cnt++;}
            if(!exist) clothes.push_back({1, k});
        }

        ans = 0;
        for(int i = 1; i <= clothes.size(); i++){   // 옷의 종류 중 i개를 선택
            for(int j = 0; j <= clothes.size(); j++)
                ans += clothes[j].cnt * combination(clothes.size(), i) * i / clothes.size();
        //   cout << ans << "\n";
        }
        cout << ans << "\n";
    }
}   

// 30!
// 15! 15!
// 29 5 23 19 9 17 16
// 

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