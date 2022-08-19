#include <bits/stdc++.h>
using namespace std;

#define a first
#define b second

pair<int, int> arr[100000];

bool cmp(pair<int, int> x, pair<int, int> y){
    if(x.b == y.b){ return x.a < y.a;}
    else return x.b < y.b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c; cin >> c;
    for(int i = 0; i < c; i++)
        cin >> arr[i].a >> arr[i].b; 

    stable_sort(arr, arr + c, cmp);
    for(int i = 0; i < c; i++)
        cout << arr[i].a << " " << arr[i].b << "\n";
}