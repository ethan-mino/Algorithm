#include <bits/stdc++.h>
using namespace std;

#define s first
#define e second

bool cmp(pair<int, int> a1, pair<int, int> a2){ 
    if(a1.e == a2.e) return a1.s < a2.s;
    return a1.e < a2.e;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    vector<pair<int, int>> a;
    for(int i = 0; i < n; i++){
        int s, e; cin >> s >> e;
        a.push_back({s, e});
    }

    sort(a.begin(), a.end(), cmp);  // 시작/종료 시간이 오름차순이 되도록 정렬

    int cnt = 1;
    pair<int, int> cur = a[0];  // 먼저, 가장 빨리 끝나는 회의를 선택
    for(auto iter = a.begin() + 1; iter != a.end(); iter++){
        pair<int, int> nx = (*iter);    // 다음으로 가장 빨리 끝나는 회의
        // 다음 회의의 시작 시간이 이전 회의의 종료 시간보다 더 크거나 같은 경우 선택
        if(nx.s >= cur.e) {cnt++; cur = nx;}    
    }
    cout << cnt;
}   