#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;
int selected[8];
bool isused[8];

void back(int th){
    if(th == m){
        for(int i = 0; i < m; i++) cout << selected[i] << " ";
        cout << "\n";
    }else{
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(!isused[i] && (v.size() == 0 || (v.size() > 0 && v.back() != arr[i]))){
                v.push_back(arr[i]);
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
    for(int i = 0; i < n; i++){
        int a; cin >> a; arr.push_back(a);
    } 

    sort(arr.begin(), arr.end());

    back(0);
}
