#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution{
public:
  bool canFormLetter(string L, string N){
    // map to store the characters frequencies in L and N
    unordered_map<char, int> Lfreq, Nfreq;

    // count the frequencies of characters in L
    for(auto it: L){
      Lfreq[it]++;
    }
    // count the frequencies of characters in N
    for(auto it: N){
      Nfreq[it]++;
    }
    // check if string L can be formed from string N
    for(auto& it: Lfreq){
      char ch = it.first;
      int cnt = it.second;
      if(Nfreq[ch] < cnt){
        return false; // not enough characters in N to form L
      }
    }
    return true; // all characters in L can be formed from N
  }
};

int main(){
  string letter = "hello";
  string newspaper = "worldhello";

  Solution obj;
  bool ans = obj.canFormLetter(letter, newspaper);
  if(ans){
    cout << "The letter can be formed from the newspaper.";
  }else{
    cout << "The letter cannot be formed from the newspaper.";
  }
}
