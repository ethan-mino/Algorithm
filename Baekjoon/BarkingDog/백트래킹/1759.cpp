#include <bits/stdc++.h>
using namespace std;

int a[5] = {'a', 'e', 'i', 'o', 'u'};
bool isused[15];
char word[15];
char selected[15];

int l, c;

void back(int r, int th){
    if(th == l + 1){
        int num = 0;
        for(int i = 0; i < l; i++){
            for(auto c : a){
                if(c == selected[i]) num++;
            }
        }
        if(num >= 1 && l - num >= 2){
            for(int i = 0; i < l; i++) cout << selected[i];
            cout << "\n";
        }
    }else{
        for(int i = r; i < c; i++){
            if(!isused[i]){
                isused[i] = true; selected[th - 1] = word[i];
                back(i + 1, th + 1);
                isused[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;

    for(int i = 0; i < c; i++) cin >> word[i];
    sort(word, word + c);
    back(0, 1);
}