// #include <iostream>
// #include <vector>
// using namespace std;

// void merge(vector <int> &arr , int st , int end ,int mid){
//     vector <int> temp;
//     int i = st;

//     int j = mid+1;
//     while(i <= mid && j <= end){
//         if(arr[i] < arr[j]){
//             temp.push_back(arr[i]);
//             i++;
//         }else{
//             temp.push_back(arr[j]);
//             j++;
//         }
//     }

//     while(i<=mid){
//         temp.push_back(arr[i]);
//         i++;
//     }
//     while(j<=end){
//         temp.push_back(arr[j]);
//         j++;
//     }
//     for(int k = 0 ;k < temp.size();k++){
//         arr[st+k] = temp[k];
//     }

// }
// void mergeSort(vector <int> & arr  , int st , int end){
//     if(st >= end) return ; /// only one element so array is sorted
//     int mid = st + ( end - st)/2;

//     mergeSort(arr , st , mid);
//     mergeSort(arr , mid+1 , end);
//     merge(arr , st , end ,mid);

// }

// int main(){
//     vector <int> arr = {8,5,5,3,1,0};
//     int st = 0;
//     int end = arr.size()-1;

//     mergeSort(arr , st , end);
//     for(int i = 0;i<arr.size();i++){
//         cout << arr[ i ] << "  ";
//     }
// }



#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr , int st , int end){
    vector<int> temp;
    int mid =  st  +(end - st)/2;
    int i = st;
    int j = mid+1;
    while(i<=mid && j<=end){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=mid){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i = 0;i <temp.size();i++){
        arr[st+i] =temp[i];
    }
}
void mergeSort(vector <int> &arr , int st, int end){

    if(st>=end) return;

    int mid = st+ (end - st)/2;
    mergeSort(arr , st , mid);
    mergeSort(arr , mid+1, end);

    merge(arr , st, end);

}

int main(){
    vector <int> arr = {8,3,1,0,5};
    int st = 0;
    int end = arr.size()-1;
    mergeSort(arr , st , end);
    for(int i =0 ;i<arr.size();i++){
        cout << arr[i] << " ";
    }
}