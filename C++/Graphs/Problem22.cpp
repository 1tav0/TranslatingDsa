#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution{
public:
  vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList){
    unordered_set<string> st(wordList.begin(), wordList.end());
    vector<string> vis;
    queue<vector<string>> q;
    q.push({beginWord});
    vis.push_back(beginWord);
    st.erase(beginWord);
    int level = 0;
    vector<vector<string>> ans;
    while(!q.empty()){
      vector<string> vec = q.front();
      q.pop();

      if(vec.size()>level){
        level++;
        for(auto it: vis){
          st.erase(it);
        }
      }
      string word = vec.back();
      if(word==endWord){
        if(ans.size()==0){
          ans.push_back(vec);
        }else if(ans[0].size()==vec.size()){
          ans.push_back(vec);
        }
      }

      for(int i=0; i<word.length(); i++){
        char original = word[i];
        for(char c='a'; c<='z'; c++){
          word[i] = c;
          if(st.count(word)>0){
            vec.push_back(word);
            q.push(vec);
            vis.push_back(word);
            vec.pop_back();
          }
        }
        word[i] = original;
      }
    }
    return ans;
  }
};

ostream& operator<<(ostream& os, vector<string> wordList){
  for(auto word: wordList){
    os << word << " ";
  }
  os << endl;
  return os;
}

ostream& operator<<(ostream& os, vector<vector<string>> ans){
  for(auto row: ans){
    for(auto word: row){
      os << word << "->";
    }
    os << endl;
  }
  return os;
}

int main(){
  int size = 0;
  cout << "Enter the size of the list: ";
  cin >> size;

  vector<string> wordList;
  for(int i=0; i<size; i++){
    cout << "Enter the word to add to wordList: ";
    string word;
    cin >> word;
    wordList.push_back(word);
  }

  cout << "The wordlist is: " << wordList;

  string startWord;
  string targetWord;
  cout << "What is the startWord? ";
  cin >> startWord;
  cout << "What is the targetWord? ";
  cin >> targetWord;

  Solution obj;
  vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
  cout << "Ways to get from " << startWord << " to " << targetWord << endl;
  cout << ans;

  return 0;
}
