#include <bits/stdc++.h>
using namespace std;

map<char, char> l;
map<char, char> r;
map<char, char> p;
int n; 

void preorder(char cur){
    cout << cur << "";
    if(l[cur] != '.') preorder(l[cur]);
    if(r[cur] != '.') preorder(r[cur]);
}

void inorder(char cur){
    if(l[cur] != '.') inorder(l[cur]);
    cout << cur << "";
    if(r[cur] != '.') inorder(r[cur]);
}

void postorder(char cur){
    if(l[cur] != '.') postorder(l[cur]);
    if(r[cur] != '.') postorder(r[cur]);
    cout << cur << "";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        char pn, ln, rn;
        cin >> pn >> ln >> rn;
        l[pn] = ln;
        r[pn] = rn;
        p[ln] = pn;
        p[rn] = pn;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
}