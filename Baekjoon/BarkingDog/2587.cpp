#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    vector<int> v;

    for(int i = 0; i < 5; i++){
        int n;
        cin >> n;
        
        v.push_back(n);
        sum += n;
    }

    sort(v.begin(), v.end());

    cout << sum / 5 << "\n";
    cout << v[2] << "\n";
}


/*
    int num[5], total;

    int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    for(int i = 0; i < 5; i++) cin >> num[i];
        
    // 평균
    for(int i = 0; i < 5; i++) total += num[i];
    cout << total / 5 << "\n";
        
    // 중앙값
    sort(num, num + 5);
    cout << num[2];
    }
*/