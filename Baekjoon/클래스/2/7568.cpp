#include <bits/stdc++.h>
using namespace std;

#define w first
#define h second

pair<int, int> arr[50];
int r[50];

bool cmp(const pair<int, pair<int, int>> p1, const pair<int, pair<int, int>> p2){
    if((p1.second.w == p2.second.w))
        return p1.second.h > p2.second.h;
    return (p1.second.w > p2.second.w);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].w >> arr[i].h;
    }

    for(int i = 0; i < n; i++){
        int r = 0;
        for(int j = 0; j < n; j++){
            if(arr[i].w < arr[j].w && arr[i].h < arr[j].h){
                r++;
            }
        }
        cout << r + 1 << " ";
    }
}