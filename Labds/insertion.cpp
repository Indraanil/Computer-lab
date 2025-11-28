// #include <iostream>
// #include <vector>
// using namespace std;

// void insertionSort(vector<int> &arr){
//     for(int i= 1;i<arr.size();i++){
//         int temp = arr[i];
//         int sort = i-1;
//         while(sort>=0 && arr[sort] > temp){
//             arr[sort+1] = arr[sort];
//             sort--;
//         }
//         arr[sort+1] = temp;
//     }
// }

// int main(){
//     vector <int> arr = {4,3,17,96,0};
//     insertionSort(arr);
//     for(int i =0 ;i<arr.size();i++){
//         cout << arr[ i ]  << "  ";
//     }

// }


#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector <int> &arr){
    for(int i=1;i<arr.size();i++){
        int j = i-1;
        int temp = arr[i];
        while(j>=0 && temp < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    
}
}
int main(){
    vector <int> arr = {4,3,17,96,0};
    insertionSort(arr);
    for(int i =0 ;i<arr.size();i++){
        cout << arr[ i ]  << "  ";
    }

}