/*
A string of brackets is considered correctly matched if every opening bracket in the string can be
paired up with a later closing bracket, and vice versa. For instance, “(())()” is correctly matched,
whereas “)(“ and “((” aren’t. For instance, “((” could become correctly matched by adding two closing
brackets at the end, so you’d return 2.

Given a string that consists of brackets, write a function bracketMatch that takes a bracket
string as an input and returns the minimum number of brackets you’d need to add to the input in
order to make it correctly matched.

Explain the correctness of your code, and analyze its time and space complexities.
*/

#include <iostream>
#include <string>

using namespace std;

int bracketMatch( const string& text )
{
  int n = text.length();
  int open = 0;
  int close = 0;
  for(auto it: text){
    if(it == '('){
      open++;
    }else if(it == ')'){
      if(open > 0){
        open--;
      }else{
        close++;
      }
    }
  }
  return open + close;
}

int main() {
  const string text = "(()";
  cout << bracketMatch(text);
  return 0;
}
