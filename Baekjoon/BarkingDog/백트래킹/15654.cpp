#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];
int selected[8];
bool isused[8];

void back(int th){
    if(th == m){
        for(int i = 0; i < m; i++) cout << selected[i] << " ";
        cout << "\n";
    }else{
        for(int i = 0; i < n; i++){
            if(!isused[i]){
                isused[i] = true; selected[th] = arr[i]; 
                back(th + 1);
                isused[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    back(0);
}