#include<iostream>
using namespace std;

int Binarysearch(int arr[],int size,int target) {
    int left = 0;
    int right = 0;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        }else {
            right = mid + 1;
        }
    }
    return -1;
}

int main() {
    int data[] = {12,23,34,56,78,89};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 89;
    int result = Binarysearch(data,size,target);
    if (result != -1) 
        cout << "element found at index : " << i << endl;
    else 
        cout << "element not found in array" << endl;
        return 0;
}