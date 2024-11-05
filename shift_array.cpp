/* a demo code that demonstrates a driver function to show the rotation of an array using a pivot index */
#include<bits/stdc++.h>
using namespace std;

void rotateArray(int arr[], int rotation, int size){
  // Rotation should be dynamic (for eg: rotation = 7; this is equal to rotating one time 
  int finalShift = rotation % size; // if: rotation > size
  if(finalShift == 0){
    return; // return original array
  }

  /* step-1: capturing from pivot element to a temp array */
  int temp[size];
  int index = 0;

  for(int i = size - finalShift; i < size; i++){
    temp[index] = arr[i];
    index++;
  }

  /* step-2: shift elements from the main array */
  for(int i = size-1; i >= 0; i--){
    if(finalShift >=0){
      arr[i] = arr[i - finalShift];
    }
  }

  /* step-3: post shifting the elements of main array; returning the pivot elements from the temp array and placing them at start */
  for(int i = 0; i < finalShift; i++){
    arr[i] = temp[i];
  }
}


// driver code
int main(){
    int arr[] = {10,20,30,40,50,60};
    int size = sizeof(arr)/sizeof(arr[0]);
    int shift = 2;

    cout<<"=========== Sorted array: ==========="<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" "<<endl;
    }

    cout<<"=========== After rotation of " << shift << " elements: ==========="<<endl;
    rotateArray(arr, size, shift);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" "<<endl;
    }

    return 0;
}
