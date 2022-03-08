#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool used[10];

void back(int k){
    if(k == m){
        for(int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
    }else{
        for(int i = 1; i <= n; i++){
            if(!used[i]){
                used[i] = true; arr[k] = i;
                back(k+1);
                used[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    back(0);
}