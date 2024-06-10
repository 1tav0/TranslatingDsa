#include <iostream>
#include <vector>
#include <string>
/*
Given an array of unique characters arr and a string str,
Implement a function getShortestUniqueSubstring that finds the smallest
substring of str containing all the characters in arr.
Return "" (empty string) if such a substring doesn’t exist.

input:  arr = ['x','y','z'], str = "xyyzyzyx"

output: "zyx"
*/
using namespace std;

vector<string> allSubs(string &s){
  vector<int> substrings;
  for (int i = 0; i < s.length(); i++) {
    for (int j = i + 1; j <= s.length(); j++) {
        substrings.push_back(s.substr(i, j - i));
    }
  }
  return substrings;
}


string getShortestUniqueSubstring( const vector<char>& arr, const string &str )
{
  string ans = "";
  int n = arr.size();
  for(int i=0; i<n; i++){
    char c = arr[i];

  }
}

int main() {
  return 0;
}

/*

arr = ['x','y','z'] - these are unique. you don't have to worry about satisfies multiples of each character

str = "xyyzyzyx"

arr = ['d'];

str = "ddddd"

["d", "dd", "ddd", "dddd", "ddddd"]

len = min(len, cnt);

output: "zyx"

str = "asdfg"

[a,s,d,f,g]

all_subs = ["a", "as", "asd", "asdf", "asdfg", "s", sd", "sdf", ........]
isValid helper function used to compare all subs in all_subs to arr.


*/

function getShortestUniqueSubstring(arr, str) {
  // define result's initial state
  // we're trying to return the window's string, not the size, so keep track of left and right to slice the string with later
  let resultLeft = 0;
  let resultRight = str.length;

  // count up the number of occurrences for each character in arr, AKA the number of occurrences needed in our window
  const neededCounter = new Map();
  for (const char of arr) {
    neededCounter.set(char, (neededCounter.get(char) || 0) + 1);
  }

  // keep track of how many character counts from neededCounter are satisfied in windowCounter
  // we need the number of counts satisfied in windowCounter to be equal to the number of counts in neededCounter for a substring to be considered valid
  let counts = neededCounter.size;
  let countsSatisfied = 0;

  // define initial state for window counting
  const windowCounter = new Map();
  let left = 0;
  let right = 0;

  // perform window counting
  // iterate through str with a left and a right pointer until the right pointer has gone out of bounds
  // move the right pointer to the right each iteration and then move the left to the right as long as the window is still valid during that iteration
  while (right < str.length) {
    // increase the right value's count in the windowCounter
    const rightVal = str[right];
    windowCounter.set(rightVal, (windowCounter.get(rightVal) || 0) + 1);

    // if the right value is in the neededCounter, we should check to see if the count is satisfied.
    // if it is, increment countsSatisfied
    if (
      neededCounter.has(rightVal) &&
      neededCounter.get(rightVal) === windowCounter.get(rightVal)
    ) {
      countsSatisfied += 1;
    }

    // While the substring is still valid, move the left pointer to the right, updating the result window and countsSatisfied accordingly
    while (countsSatisfied === counts) {
      const windowSize = right - left + 1;
      const resultWindowSize = resultRight - resultLeft + 1;
      if (windowSize < resultWindowSize) {
        resultLeft = left;
        resultRight = right;
      }

      let leftVal = str[left];
      if (
        neededCounter.has(leftVal) &&
        neededCounter.get(leftVal) === windowCounter.get(leftVal)
      ) {
        countsSatisfied -= 1;
      }
      windowCounter.set(leftVal, windowCounter.get(leftVal) - 1);
      left += 1;
    }

    right += 1;
  }

  // if the result window size is greater than str.length, the result window was never updated since the beginning, so return ""
  const resultWindowSize = resultRight - resultLeft + 1;
  if (resultWindowSize str.length) {
    return "";
  }

  //otherwise, return a slice of the string
  return str.slice(resultLeft, resultRight + 1);
