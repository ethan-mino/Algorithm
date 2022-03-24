#include <bits/stdc++.h>
using namespace std;
char alpha[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str; cin >> str;
    int ans = 0;
    for(int i = 0; i < str.size(); i++){
        for(int j = 0; j < 16; j++){
            if(alpha[j] == str[i]){
                ans += j * pow(16, str.size() - (i + 1));
                break;
            }
        }
    }
    cout << ans;
}
