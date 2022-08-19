#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int time[1000];
    vector<int> np;

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> time[i];
    for(int i = 0; i < n; i++) np.push_back(i);
    
    sort(time, time + n);

    int s = time[np[0]];
    int a = time[np[0]];
    for(int i = 1; i < n; i++){
        s += a + time[np[i]];
        a += time[np[i]];
    }

    cout << s;
}