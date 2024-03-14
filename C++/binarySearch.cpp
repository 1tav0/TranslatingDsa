#include <iostream>
#include <vector>
#include <string>
using namespace std;

int binarySearch(vector<string> &arr, string target) {
  int left = 0;
  int right = arr.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int binarySearch(vector<int> &arr, int target) {
  int left = 0;
  int right = arr.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}
int helper(int low, int high, string target,vector<string> &list){
  int mid = low + (high + low) / 2;
  while(low<=high){
    if(list[mid] == target){
      return mid;
    }else if(list[mid] <= target){
      helper(mid + 1, high, target, list);
    }else{
      helper(low, mid - 1, target, list);
    }
  }
  return -1;
}

int helper(int low, int high, int target,vector<int> &list){
  while(low<=high){
    int mid = low + (high + low) / 2;
    if(list[mid] == target){
      return mid;
    }else if(list[mid] <= target){
      helper(mid + 1, high, target, list);
    }else{
      helper(low, mid - 1, target, list);
    }
  }
  return -1;
}

int binarySearchRecursive(vector<string> &list, string target){
  int low = 0;
  int right = list.size() - 1;
  return helper(low, right, target, list);
}
int binarySearchRecursive(vector<int> &list, int target){
  int low = 0;
  int right = list.size() - 1;
  return helper(low, right, target, list);
}

vector < string > sortlist(vector < string > & list){
  vector<string> ans;
  int n = list.size();
  for (int i = 0; i < n-1; i++){
    string s1 = list[i];
    string s2 = list[i + 1];
    for (char c = 'a'; c <= 'z'; c++){
      if(s1[c]<=s2[c]){
        ans.push_back(s1);
      }else{ //when they are equal
        ans.push_back(s2);
      }
    }
  }
  return ans;
}


int main(){
  vector<string> fruits = {"apples", "bananas", "bandanas", "blueberries", "plums", "zuchini"};

  vector<int> nums = {1,2,3,4,5,6,7};

  string targetFruit = "bandanas";

  //int result = binarySearch(nums, 5);

  int result = binarySearchRecursive(fruits, targetFruit);


  if (result != -1)
  {
    std::cout << "Fruit \"" << targetFruit << "\" found at index " << result << "." << std::endl;
    std::cout << "nums \"" << 5 << "\" found at index " << result << "." << std::endl;
    }
}
