#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    int arr[100000];

    cin >> n >> x;

    int val;

    for (int i = 0; i < n; i++){
        cin >> val;
        if(val < x){
            cout << val << " ";
        }
    }
}