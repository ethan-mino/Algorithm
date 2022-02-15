#include <bits/stdc++.h>

using namespace std;

void printArr(int arr[], int len){
    for(int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int freq[26] = {};  // OR fill(freq, freq + 6, 0)
    
    string word;
    cin >> word;

    int len = word.length();

    for(int i = 0; i < len; i++) freq[i - 'a']++; // for (auto c : word) freq[c - 'a']++;

    for(int i = 0; i < 26; i++) cout << freq[i] << " ";
}