#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

//Word Ladder I
class Solution{
public:
  int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        st.erase(startWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == targetWord) return steps;
            for(int i=0; i<word.length(); i++){
                char original = word[i];
                for(char c='a'; c<='z'; c++){
                    word[i] = c;
                    if(st.find(word)!=st.end()){
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};

ostream& operator<<(ostream& os, vector<string> wordList){
  for(auto& word: wordList){
    os << word << " ";
  }
  os << endl;
  return os;
}

int main(){
  int tests = 0;
  cout << "Enter the number of tests: ";
  cin >> tests;
  while(tests--){
    vector<string> wordList;
    int size = 0;
    cout << "Enter the size of the wordlist: ";
    cin >> size;
    for(int i=0; i<size; i++){
      string word = "";
      cout << "Enter the word to add to the wordList: ";
      cin >> word;
      wordList.push_back(word);
    }
    cout << "The wordList is: ";
    cout << wordList;

    string startWord;
    string targetWord;
    cout << "What is the startWord? ";
    cin >> startWord;
    cout << "What is the targetWord? ";
    cin >> targetWord;
    Solution obj;
    int ans = obj.wordLadderLength(startWord, targetWord, wordList);
    cout << "The length of the smallest transformation sequence from " << startWord << " -> " << targetWord << " is " << ans << endl;
    cout << "\n-------------------\n";
  }

  return 0;
}
