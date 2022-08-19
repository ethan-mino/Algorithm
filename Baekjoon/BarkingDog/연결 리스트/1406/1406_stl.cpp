#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string content;
    cin >> content;

    list<char> list;

    for (auto c : content){
        list.push_back(c); 
    }
    auto cursor = list.end();

    int q;
    cin >> q;

    while(q--){
        char op;
        cin >> op;
        
        switch(op){
            case 'P' : 
            char input;
            cin >> input;
            list.insert(cursor, input);
            break;
            case 'B' :
            if(cursor != list.begin()) {
                cursor--;
                cursor = list.erase(cursor);
            }
            break;
            case 'L' : if(cursor != list.begin()) cursor--;;
            break;
            case 'D' : if(cursor != list.end()) cursor++;
            break;
        }
    }
    
    for (auto elem : list) cout << elem;
}
