// #include <iostream>
// #include <vector>
// using namespace std;

// void bubbleSort(vector <int> &arr ){
//     for(int i =0;i<arr.size();i++){
//         for(int j =0;j<arr.size()-i-1;j++){
//             if(arr[j] > arr[j+1]){
//                 swap(arr[j] , arr[j+1]);
//             }
//         }
//     }
// }

// int main(){
//     vector <int> arr= {9,32,1,3,90,5};
//     bubbleSort(arr);
//     for (int i = 0; i < arr.size(); i++)
//     {
//         cout << arr[ i] << " ";
//     }
    
// }


#include<iostream>
#include <vector>
using namespace std;

void bubblesorry(vector<int> &arr){
    for(int i =0 ;i< arr.size();i++){
        for(int j = 0;j< arr.size()-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}

int main(){
    vector <int> arr = {5,3,2,7,0};
    bubblesorry(arr);
    for(int i =0 ;i<arr.size();i++){
        cout << arr[i] << " ";
    }
}