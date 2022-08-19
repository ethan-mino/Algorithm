#include <bits/stdc++.h>
using namespace std;

int tree[1000010];
int n, m; 

long long length(int h){  // 절단기의 높이가 h일 때, 가져갈 수 있는 나무의 길이
    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(tree[i] - h > 0) sum += tree[i] - h;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> tree[i];

    int low = 0, high = *max_element(tree, tree + n);
    while(low < high){
        int mid = (high + low + 1) / 2;
        if(length(mid) >= m){    // 가져가려는 나무의 길이보다 긴 경우
            low = mid;
        }else{
            high = mid - 1; // 절단기의 높이를 높임
        }
    }
    cout << (high + low + 1) / 2 << "\n";
}   