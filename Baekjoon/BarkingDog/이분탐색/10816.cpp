/*
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

    map<int, int> cnt;
    for(int i = 0; i < n; i++) cnt[a[i]]++;
    for(int i = 0; i < m; i++) cout << cnt[b[i]] << " ";
    cout << "\n";
}   
*/

#include <bits/stdc++.h>
using namespace std;

int a[500010], b[500010];
int n, m; 

int lower_idx(int target){   // target을 넣을 수 있는 가장 왼쪽의 idx를 반환
    int left = 0, right = n;
    int mid = (left + right) / 2;

    while(left < right){
        mid = (left + right) / 2;
        if(a[mid] < target) left = mid + 1;
        else right = mid;
    }
    return (left + right) / 2;
}

int upper_idx(int target){   // target을 넣을 수 있는 가장 오른쪽의 idx를 반환
    int left = 0, right = n;
    int mid = (left + right) / 2;

    while(left < right){
        mid = (left + right) / 2;
        if(a[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return (left + right) / 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a, a + n);
    // for(int i = 0; i < m; i++)
    //     cout << upper_idx(b[i]) - lower_idx(b[i]) << " ";

    for(int i = 0; i < m; i++)
        cout << upper_bound(a, a + n , b[i]) - lower_bound(a, a + n, b[i]) << " ";

    cout << upper_bound(a, a + n, 10) - a<< " " << lower_bound(a,  a + n, 10) - a;
}   

/*
10
-10 -10 2 3 3 6 7 10 10 10
8
10 9 -5 2 3 4 5 -10

*/

/*
10
0     1 2 3 4 5 6  7  8  9
-10 -10 2 3 3 6 7 10 10 10
8
10 9 -5 2 3 4 5 -10
*/