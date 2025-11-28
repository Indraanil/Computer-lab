// #include <iostream>
// #include <vector>
// using namespace std;
// int partition(vector <int> &arr , int st , int end){
//     int pivot  = arr[end];
//     int idx = st-1;
//     for(int i =st ;i<end;i++){
//         if(arr[i] <=  pivot){
//             idx++;
//             swap(arr[i] , arr[idx]);
//         }

//     }
//         swap(arr[end] , arr[idx+1]);

//     return idx+1;
// }

// void quickSort(vector <int> &arr , int st, int  end){
//     if(st < end) {
//         int pivotindex = partition(arr , st , end);
//         quickSort(arr, st, pivotindex-1);
//         quickSort(arr, pivotindex+1 , end);
//     }
// }
// int main(){
//     vector <int> arr = {8,4,2,133,2,0};
//     int st = 0 , end = arr.size()-1;
//     quickSort(arr , st , end);
//     for(int  i =0;i<arr.size();i++){
//         cout << arr[i] << " ";
//     }

// }




#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &arr , int st  , int end){
    int pivot = arr[end];
    int idx  = st-1;
    for(int i = st;i<end;i++){
        if(arr[i] <= pivot){
            idx++;
            swap(arr[i] , arr[idx]);
        }
    }
    swap(arr[idx+1] , arr[end]);
    return idx +1;

}
void quickSort(vector<int> &arr , int st , int end){
    if(st < end){
    int pivotindex = partition(arr , st , end);
    quickSort(arr , st , pivotindex-1);
    quickSort(arr,pivotindex+1,end);
  }
}
int main(){
    vector <int> arr  = {8,4,1,0,5};
    int st = 0;
    int end  = arr.size()-1;
    quickSort(arr , st, end);
    for(int i = 0;i<arr.size();i++){
        cout << arr[ i] << " ";
    }
}