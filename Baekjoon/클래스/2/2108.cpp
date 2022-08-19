#include <bits/stdc++.h>
using namespace std;

#define freq first
#define v second

int arr[500000];

bool cmp(const pair<int, int> p1, const pair<int, int> p2){
    if(p1.freq == p2.freq) return p1.v < p2.v;
    else return p1.freq > p2.freq;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    pair<int, int> hist[8001];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    
    sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        hist[arr[i] + 4000].v = arr[i];
        hist[arr[i] + 4000].freq++;
    }

    sort(hist, hist + 8001, cmp);

    cout << round((double)accumulate(arr, arr + n, 0) / n) + 0<< "\n";
    cout << arr[n/ 2] << "\n";
    cout << ((hist[0].freq == hist[1].freq) ? hist[1].v : hist[0].v) << "\n";
    cout << arr[n - 1] - arr[0] << "\n";
}