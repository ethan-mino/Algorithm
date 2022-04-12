#include <bits/stdc++.h>
using namespace std;

int arr[1000001];

void merge(int s1, int e1, int s2, int e2){
    int c[1000001];

    int ap = s1, bp = s2, cp = 0; 
    while(ap != (e1 + 1) && bp != (e2 + 1)){
        if(arr[ap] > arr[bp]) c[cp++] = arr[bp++];  // a가 더 큰 경우
        else c[cp++]  = arr[ap++]; // b가 더 큰 경우
    }

    if(ap == (e1 + 1)) for(int i = bp; i < (e2 + 1); i++) c[cp++] = arr[i];
    else for(int i = ap; i < (e1 + 1); i++) c[cp++] = arr[i];

    for(int i = s1; i <= e2; i++) arr[i] = c[i - s1];
}

void merge_sort(int a, int b){
    if(a < b){
        int mid = (a + b) / 2;
        merge_sort(a, mid);
        merge_sort(mid + 1, b);
        merge(a, mid, mid + 1, b);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;    
    for(int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(0, n - 1);

    for(int i =0; i < n; i++) cout << arr[i] << "\n";
}   
