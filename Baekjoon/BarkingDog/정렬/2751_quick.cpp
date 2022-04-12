#include <bits/stdc++.h>
using namespace std;

int arr[1000001];

void swap(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void quick_sort(int start, int end){
    if(start < end){
        int pivot = arr[start];
        int left = start + 1, right = end;
        
        while(true){
            while(left <= right && arr[left] <= pivot) left++;
            while(left <= right && arr[right] >= pivot) right--;

            if(left >= right) break;
            swap(left, right);
        }

        swap(start, right);
        quick_sort(start, right - 1);
        quick_sort(right + 1, end);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;    
    for(int i = 0; i < n; i++) cin >> arr[i];
    quick_sort(0, n - 1);

    for(int i =0; i < n; i++) cout << arr[i] << "\n";
}   