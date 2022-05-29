#include <bits/stdc++.h>
using namespace std;

#define w first
#define v second
#define MAX 300010

multiset<pair<int, int>> gems;
multiset<int> avail; 
int bags[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;

    // 가장 가벼운 무게를 담을 수 있는 가방부터
    // 넣은 수 있는 보석 중 가장 가치가 큰 보석을 넣음
    for(int i = 0; i < n; i++){
        pair<int, int> gem;
        cin >> gem.w >> gem.v;
        gems.insert(gem);
    }

    for(int i = 0; i < k; i++) cin >> bags[i];  // 각 가방에 넣을 수 있는 최대 무게를 입력 받음
    
    sort(bags, bags + k);   // 가방을 오름차순 정렬

    long long ans = 0;

    for(int i = 0; i < k; i++){
        int cap = bags[i];  // 가방에 담을 수 있는 최대 무게
        auto upper = gems.upper_bound({cap, INT_MAX});  // 가방에 담을 수 있는 보석의 무게보다 무거운 보석 중에서 가장 가벼운 보석의 위치
        
        for(auto iter = gems.begin(); iter != upper;){  // 각 보석을 gems에서 제거하고, avail 이진 검색 트리에 삽입
            avail.insert((*iter).v);   // 단, 보석의 가치를 기준으로 정렬되도록 가치를 첫번째로 넣어줌
            iter = gems.erase(iter); // 보석을 gems에서 제거
        }

        if(avail.size() > 0){
            int m = *prev(avail.end());     // 넣을 수 있는 보석 중 가장 가치가 높은 보석을 가방에 넣음
            avail.erase(prev(avail.end())); // 해당 보석을 삭제
            ans += m;   // 제거된 보석의 가치를 더해줌
        }
    }

    cout << ans << "\n";
}

/*
1 1
100 100
10
-> 0

4 3
1 1
1000000 100000000
1000000 100000000 
1000000 100000000
1000000 1000000 1000000
-> 300000000
*/