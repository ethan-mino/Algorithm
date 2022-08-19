#include <bits/stdc++.h>
using namespace std;

int pos[1000010];
vector<int> temp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0 ; i < n; i++) {
        cin >> pos[i];
        temp.push_back(pos[i]);
    }
    
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for(int i = 0; i <n; i++) 
        cout << lower_bound(temp.begin(), temp.end(), pos[i]) - temp.begin() << " ";
}   
