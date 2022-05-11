#include <bits/stdc++.h>
using namespace std;

int a[500010], b[500010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a, a + n);
    for(int i = 0; i < m; i++)
        cout << binary_search(a, a + n, b[i]) << " ";
}   