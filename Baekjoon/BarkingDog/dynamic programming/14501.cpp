#include <bits/stdc++.h>
using namespace std;

#define duration first
#define cost second

pair<int, int> arr[1001];
int d[1001];
int n;

int coun(int day){  // day는 0 ~ n - 1
    if(d[day] != 0) return d[day];
    else{
        int m = INT_MIN;
        for(int start = n - 1; start >= day + arr[day].duration; start--){
            m = max(m, coun(start));
        }
        if(day + arr[day].duration > n) d[day] = 0;
        else if(m == INT_MIN) d[day] = arr[day].cost;
        else d[day] = m + arr[day].cost;
        return d[day];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        pair<int, int> t; 
        cin >> t.duration >> t.cost;
        arr[i] = t;
    }

    
    for(int i = 0; i < n; i++) coun(i);
    cout << *max_element(d, d + n);
}   
