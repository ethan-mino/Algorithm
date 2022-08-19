// 소요 시간 4분
#include <bits/stdc++.h>
using namespace std;

int a[500010], b[500010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(b, b + m);
    vector<int> ans;
    for(int i = 0; i < n; i++)
        if(!binary_search(b, b + m, a[i]))
            ans.push_back(a[i]);

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    if(ans.size() != 0) 
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}   