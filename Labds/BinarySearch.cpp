#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int>&arr , int st , int end , int element){
    while(st<=end){
        int mid = st +(end-st)/2;
        if(arr[mid] ==  element){
            return mid;
        }
        if(arr[mid] < element){
            st = mid+1;
        }else{
            end = mid-1;
        }
    }
    return -1;
}
int main(){
    vector <int> arr  = { 1 ,2 ,3 ,4 ,5 ,6, 7};
    int st = 0 , end = arr.size()-1;
    int ans = BinarySearch(arr ,st ,end  ,7);
    cout << ans ;
}




// #include <iostream>
// #include <vector>
// using namespace std;

// int binarySearch(vector<int>&arr , int st,int end , int element){
//     while(st <= end){
//         int mid = st+(end - st)/2;
//         if(arr[mid] == element){
//             return mid;
//         }
//         if(element > arr[mid]){
//             st = mid=1;
//         }
//         else if(element < arr[mid]){
//             end = mid-1;
//         }
//     }
//     return -1;
// }

// int main(){
//     vector <int> arr =  {1,2,3,5,7,9,15};
//     int st =0;
//     int end = arr.size()-1;
//     int ans = binarySearch(arr , st, end , 9);
//     cout << ans;
// }