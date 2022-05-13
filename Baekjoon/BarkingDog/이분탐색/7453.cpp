#include <bits/stdc++.h>
using namespace std;

int arr[4][5000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 4; j++)
            cin >> arr[j][i];

    vector<long long> v[2];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            v[0].push_back(arr[0][i] + arr[1][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            v[1].push_back(arr[2][i] + arr[3][j]);

    for(int i = 0; i < 2; i++)
        sort(v[i].begin(), v[i].end());
        
    long long ans = 0;
    for(int i = 0; i < v[0].size(); i++){
        int high = upper_bound(v[1].begin(), v[1].end(), v[0][i] * - 1) - v[1].begin();
        int low = lower_bound(v[1].begin(), v[1].end(), v[0][i] * - 1) - v[1].begin();

        ans += high - low;
    }

    cout << ans;
}   