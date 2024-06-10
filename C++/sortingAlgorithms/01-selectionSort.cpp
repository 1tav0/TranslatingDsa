#include<bits/stdc++.h>

using namespace std;
// tc - O(N2)
// sc - O(1)
class Solution
{
    public:
    int select(int arr[], int i, int n)
    {
        int miniIndex = i;
        for(int j=i+1; j<n; j++){
          if(arr[j] < arr[miniIndex]){
            miniIndex = j;
          }
        }
        return miniIndex;
    }

    void selectionSort(int arr[], int n)
    {
      for(int i=0; i<n-1; i++){
        int mini = select(arr, i, n);
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
      }
    }
};

void selection_sort(int arr[], int n) {
  // selection sort
  for (int i = 0; i < n - 1; i++) {
    int mini = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }
    //swap(arr[i], arr[j]);
    int temp = arr[mini]; // stores the actual mini element
    arr[mini] = arr[i]; // the mini we got at beginning is swapped to the back
    arr[i] = temp; // actual mini goes to the front

  cout << "After selection sort: " << "\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";

}
int main() {
  int arr[] = {13,46,24,52,20,9};
  int n = sizeof(arr) / sizeof(arr[0]);
   cout << "Before selection sort: " << "\n";
   for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  selection_sort(arr, n);
  return 0;
}
