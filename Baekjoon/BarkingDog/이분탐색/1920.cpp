#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a, a + n);

    for(int i = 0; i < m; i++){
        bool exist = false;
        int left = 0, right = n - 1, mid = (left + right) / 2;

        while(left <= right){
            mid = (left + right) / 2;

            if(a[mid] == b[i]){
                exist = true; break;
            }else if(a[mid] < b[i]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        cout << exist << "\n";
    }
}   