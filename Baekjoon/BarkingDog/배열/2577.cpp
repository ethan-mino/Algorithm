#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int mul = a * b * c;
    string str = to_string(mul);

    int arr[10] = {};
    
    for(auto c : str){
        arr[((int) c) - 48]++;
    }

    for(int i = 0; i < 10; i++){
        cout << arr[i] << "\n";
    }
}
