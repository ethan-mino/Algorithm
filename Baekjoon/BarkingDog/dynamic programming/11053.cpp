#include <bits/stdc++.h>
using namespace std;

int arr[1001], d[1001]; 
int n;
int longest(int start){
    if(d[start] != 0){
        return d[start];
    }else{
        int ans = INT_MIN;
        bool biggest = true;
        for(int i = n - 1; i > start; i--){
            if(arr[start] < arr[i]){
                biggest = false;
                ans = max(ans, longest(i));
            }
        }

        if(biggest) d[start] = 1;
        else d[start] = ans + 1;
        return d[start];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i =0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) longest(i);

    cout << *max_element(d, d + 1001);
}   
