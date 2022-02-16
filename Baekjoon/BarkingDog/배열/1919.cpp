#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    int arr1[26] = {}, arr2[26] = {};
    int cnt = 0;

    for(auto c : str1){
        arr1[c - 'a']++;
    }

    for(auto c : str2){
        arr2[c - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        cnt += (arr1[i] > arr2[i]) ? arr1[i] - arr2[i] : arr2[i] - arr1[i];
    }
    cout << cnt;
}


/*
    int arr[2][26], res;
    string s1, s2;

    int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>s1>>s2;
    for(char c : s1)
        arr[0][c-'a']++;
    
    for(char c : s2)
        arr[1][c-'a']++;
    
    for(int i=0; i<26; i++)
        res += abs(arr[0][i]-arr[1][i]); // ******************
    
    cout << res;
    }
*/