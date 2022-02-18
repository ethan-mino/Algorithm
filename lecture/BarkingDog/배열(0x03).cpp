#include <bits/stdc++.h>

using namespace std;

void insert(int idx, int num, int arr[], int& len){

  if (idx != len){
    for(int i = len - 1; i > idx; i--){
        arr[i] = arr[i - 1];
    }
  }
    
  arr[idx] = num;
  len++;
}

void erase(int idx, int arr[], int& len){

  if(idx != len){
    for(int i = idx; i < len; i++){
        arr[i] = arr[i + 1];
    }
  }

  len--;
}

void printArr(int arr[], int& len){
  for(int i = 0; i < len; i++) cout << arr[i] << ' ';
  cout << "\n\n";
}

void insert_test(){
  cout << "***** insert_test *****\n";
  int arr[10] = {10, 20, 30};
  int len = 3;
  insert(3, 40, arr, len); // 10 20 30 40
  printArr(arr, len);
  insert(1, 50, arr, len); // 10 50 20 30 40
  printArr(arr, len);
  insert(0, 15, arr, len); // 15 10 50 20 30 40
  printArr(arr, len);
}

void erase_test(){
  cout << "***** erase_test *****\n";
  int arr[10] = {10, 50, 40, 30, 70, 20};
  int len = 6;
  erase(4, arr, len); // 10 50 40 30 20
  printArr(arr, len);
  erase(1, arr, len); // 10 40 30 20
  printArr(arr, len);
  erase(3, arr, len); // 10 40 30
  printArr(arr, len);
}

int func2(int arr[], int n){
  int exist[101] = {};

  for (int i = 0; i < n; i++){
    if(exist[100 - arr[i]] == 1)
      return 1;
    exist[arr[i]] = 1;
  }

  return 0;
}

int main(void) {
  // insert_test();
  // erase_test();

  int arr1[] = {1, 52, 48};
  int arr2[] = {50, 42};
  int arr3[] = {4, 13, 63, 87};

  cout << func2(arr1, 3) << "\n";
  cout << func2(arr2, 2) << "\n";
  cout << func2(arr3, 4) << "\n";
}