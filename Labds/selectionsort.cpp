#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector <int> &arr){
    int n = arr.size();
    for(int i = 0 ;i <n-1;i++){
        int minindex = i;
        for(int j = i+1 ; j <n;j++){
            if(arr[j] < arr[minindex]){
                minindex = j;
            }
        }
        swap(arr[i] , arr[minindex]);
    }
    
}
int main(){
    vector <int> arr = { 5,21,5,5,2};
    selectionSort(arr);
    for(int i =0;i <arr.size();i++){
        cout << arr[i] << " ";
    }
}