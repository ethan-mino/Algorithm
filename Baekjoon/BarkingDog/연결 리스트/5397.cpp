#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--){
        string str;
        cin >> str;
        
        list<char> ll;
        auto cursor = ll.begin();

        for(auto c : str){
            switch(c){
                case '<' : 
                if(cursor != ll.begin()) cursor--; 
                break;

                case '>' : 
                if(cursor != ll.end()) cursor ++;
                break;

                case '-' : 
                if(cursor != ll.begin()){
                    cursor--;
                    cursor =ll.erase(cursor);
                }
                break;

                default : 
                    ll.insert(cursor, c);
            }
        }

        for(auto c : ll)
            cout << c;  
        cout << "\n";
    }
}