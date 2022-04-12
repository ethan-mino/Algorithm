#include <bits/stdc++.h>
using namespace std;

#define SIZE 2000010
vector<pair<int, string>> s;

int a[SIZE];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int c; cin >> c;
        a[c + 1000001]++;
    }
    sort(s.begin(), s.end());
    for(int i = 1; i < SIZE; i++){
        for(int j = 0; j < a[i]; j++) cout << i - 1000001 << "\n";
    }
}   
