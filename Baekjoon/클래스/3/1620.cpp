#include <bits/stdc++.h>
using namespace std;

#define name first
#define num second

vector<pair<string, int>> book1;
vector<pair<string, int>> book2;

bool cmp1(pair<string, int> p1, pair<string, int> p2){return p1.name < p2.name;}
bool cmp2(pair<string, int> p1, pair<string, int> p2){return p1.num < p2.num;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        pair<string, int> p;
        cin >> p.name; p.num = i;
        book1.push_back(p);
        book2.push_back(p);
    }

    sort(book1.begin(), book1.end(), cmp1); // 이름을 기준으로 정렬
    sort(book2.begin(), book2.end(), cmp2); // 번호를 기준으로 정렬

    while(m--){
        string input; cin >> input;
        int c = atoi(input.c_str());
        int mid, left = 0, right = n - 1;

        if(c != 0){    // 숫자인 경우
            while(left <= right){
                mid = (right + left) / 2;

                if(book2[mid].num < c){
                    left = mid + 1;
                }else if(book2[mid].num > c){
                    right = mid - 1;
                }else break;
            }
            cout << book2[mid].name << "\n";
        }else{  // 문자열인 경우
            while(left <= right){
                mid = (right + left) / 2;

                if(book1[mid].name < input){
                    left = mid + 1;
                }else if(book1[mid].name > input){
                    right = mid - 1;
                }else break;
            }
            cout << book1[mid].num << "\n";
        }
    }
}