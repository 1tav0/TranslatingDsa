// #include <bits/stdc++.h>
#include <utility> //for pair
#include <iostream>
#include <vector>
#include <typeinfo>
#include <cstdlib> // for rand
#include <ctime> // for rand
#include <list>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

// std::pair<int,int> p;
void explainPair(){
  pair<int,int> p = {1,3};
  cout << "pair is: " << p.first << "," << p.second << endl;

  pair<int,pair<int,int>> p1 = {1, {3,4}};
  cout << "Pair with a pair is: " << p1.first << " " << p1.second.first << "," << p1.second.second << endl;

  pair<int,int> arr[3] = {{1,2}, {2,3}, {3,4}};
  for(int i=0; i<3; i++){
    cout << "Pairs in the array are: ";
    for(int j=0; j<1; j++){
      cout << arr[i].first << "," << arr[i].second;
    }
    cout << endl;
  }
}

/* ------------------------------------------------------------------ */

// std::vector<int> v;
void explainVector(){
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);

  cout << "1d vector values: ";
  for(auto val: v){
    cout << val << ",";
  }
  cout << endl;

  vector<pair<int,int>> vec;
  vec.push_back(make_pair(1,2));
  // vec.push_back({1,2}); // or v.push_back({1, 2}); in C++11 or later
  vec.emplace_back(1,3);

  cout << "pairs inside the vector are: " << endl;
  for(auto it: vec){
    for(int i=0; i<1; i++){
      cout << it.first << "," << it.second;
    }
    cout << endl;
  }

  vector<int> ds(5, 20);
  vector<int>::iterator it = ds.begin();
  cout << "Using the iterator in a vector with a while loop: " << endl;
  while(it != ds.end()){
    cout << *(it) << " ";
    ++it;
  }
  // v.erase(v.begin()+1);
  // v.erase(v.begin()+2, v.begin()+4); [start,end)
  cout << "\nUsing the iterator in a vector with a for loop starting from beginning: " << endl;
  for(auto it = v.begin(); it != v.end(); it++){
    cout << *(it) << " ";
  }

  cout << "\nUsing the iterator in a vector with a for loop starting from reverse without using rbegin & rend: " << endl;
  for(auto it = v.end()-1; it >= v.begin(); it--){
    cout << *(it) << " ";
  }

  cout << "\nUsing the iterator in a vector with a for loop starting from reverse: " << endl;
  for(auto it = v.rbegin(); it != v.rend(); it++){
    cout << *(it) << " ";
  }

  cout << "\nUsing the iterator in a vector with a for loop starting from beginning with rbegin & rend: " << endl;
  for(auto it = v.rend()-1; it >= v.rbegin(); it--){
    cout << *(it) << " ";
  }
  cout << endl;
  v.insert(v.begin(), 11);
  v.insert(v.begin()+1, 3, 0);
  cout << "Vector after using insert for new values: ";
  for(auto it: v){
    cout << it << " ";
  }
  cout << endl;

  v.insert(v.begin()+1, ds.begin(), ds.end());
  cout << "copying a whole vector at the beginning using insert: " << endl;
  for(auto it: v){
    cout << it << " ";
  }
  cout << endl;

  cout << "The size of the vector is: " << v.size() << endl;
  cout << "The last element is: " << v.back() << endl;
  cout << "Popping the last element: " << endl;
  v.pop_back();
  for(auto it: v){
    cout << it << " ";
  }
  cout << endl;
  // v1.swap(v2);
  // Set the seed for the random number generator
  srand(time(0));
  // Generate a random number between 1 and 100
  int num = rand()%100 + 1;
  // Generate a random number between 1 and 100
  /*let randomNumber = Math.floor(Math.random() * 100) + 1;*/
  /*
    Random random = new Random();
    int randomNumber = random.nextInt(100)+1;
  */
  cout << "random number is: " << num << endl;
  if(num%2==0){
    v.clear();
  }

  if(v.empty()){
    cout << "The vector is empty.";
  }else{
    cout << "The vector is not empty.";
  }
}

/* ------------------------------------------------------------------ */

// std::list<int> l;
void printList(list<int> arr){
  for(auto it: arr){
    cout << it << " ";
  }
  cout << endl;
}
void explainList(){
  list<int> ls;
  ls.push_back(2);
  ls.emplace_back(4);

  cout << "the list is:" << endl;
  printList(ls);

  ls.push_front(5);
  printList(ls);

  ls.emplace_front(8);
  printList(ls);

  // rest of functions for a list are similar to a std::vector<int> v;
  // begin, end, rbegin, rend, clear, insert, size, swap
}

// double-ended queue, supports insertion and deletion operations at both the beginning
// and the end in constant time, O(1)
void printDeque(deque<int> dq){
  // for(auto it = dq.begin(); it!=dq.end(); it++){
  //   cout << *(it) << " ";
  // }
  auto it = dq.begin();
  while(it != dq.end()){
    cout << *(it) << " ";
    it++;
  }
  cout << endl;
}
// std::deque<int> dq;
void explainDequeue(){
  deque<int> dq;
  dq.push_back(1);

  cout << "The deque is:" << endl;
  printDeque(dq);

  dq.emplace_back(2);
  cout << "Using emplace_back(2):" << endl;
  printDeque(dq);

  dq.push_front(4);
  cout << "Using push_front(4):" << endl;

  dq.emplace_front(3);
  cout << "Using emplace_front(3):" << endl;
  printDeque(dq);

  cout << "element in the back of the list: " << dq.back() << endl;
  cout << "element in the front of the list: " << dq.front() << endl;

  cout << "popping from back of deque with dq.pop_back():" << endl;
  dq.pop_back();
  printDeque(dq);
  cout << "popping from front of dequeue with dq.pop_front()" << endl;
  dq.pop_front();
  printDeque(dq);

  cout << "element in the back of the list: " << dq.back() << endl;
  cout << "element in the front of the list: " << dq.front() << endl;

  // the rest of the functions are the same as the std::vector<int> v;
  // begin, end, rend, rbegin, clear, insert, size, swap
}

/* ------------------------------------------------------------------ */

void printStack(stack<int> st){
  while(!st.empty()){
    int node = st.top();
    cout << node << endl;
    st.pop();
  }
  cout << endl;
}
void explainStack(){
  cout << "-----ALL operations happen in constant time O(1)------" << endl;
  stack<int> st;
  cout << "Pushing to the stack using push(n)" << endl;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  printStack(st);

  cout << "Pushing to the stack using emplace(n)" << endl;
  st.emplace(5);
  printStack(st);

  cout << "Node at the top of the stack is: " << st.top() << endl;
  cout << "Delete the top node from the st: " << endl;
  st.pop();
  printStack(st);

  cout << "The new node at the top of the stack is: " << st.top() << endl;
  cout << "The size of the stack is: " << st.size() << endl;
  cout << "is the stack empty: " << st.empty() << endl;

  stack<int> st1;
  cout << "-----Testing swap------" << endl;
  st1.push(9);
  st1.push(8);
  st1.push(7);
  st1.push(6);
  st1.push(5);
  cout << "old stack is: " << endl;
  printStack(st);
  cout << "New Stack is: " << endl;
  printStack(st1);

  cout << "We swap the stacks: " << endl;

  st.swap(st1);
  cout << "old stack is now: " << endl;
  printStack(st);
  cout << "New Stack is now: " << endl;
  printStack(st1);
}

/* ------------------------------------------------------------------ */

void printQueue(queue<int> q){
  while(!q.empty()){
    cout << q.front() << endl;
    q.pop();
  }
  cout << endl;
}

void explainQueue(){
  cout << "----ALL operations happen in constant time O(1)-----";
  queue<int> q;
  cout << "Is the q empty: " << q.empty() << endl;
  cout << "Pushing to the queue using push: " << endl;
  q.push(1);
  q.push(2);
  printQueue(q);

  cout << "Pushing to the queue using emplace: " << endl;
  q.emplace(4);
  printQueue(q);

  cout << "What is the last node: " << q.back() << endl;
  cout << "Adding 5 to the last node:" << endl;
  q.back() += 5;
  printQueue(q);

  cout << "What is the first node: " << q.front() << endl;
  cout << "Popping from the queue (FIFO): " << endl;
  q.pop();
  printQueue(q);

  cout << "Is the queue empty(): " << q.empty() << endl;
  cout << "-----Testing swap-----" << endl;
  queue<int> q1;
  q1.push(9);
  q1.push(8);
  q1.push(7);
  q1.push(6);
  cout << "The old q is: " << endl;
  printQueue(q);
  cout << "The new q is: " << endl;
  printQueue(q1);

  cout << "We swap the queues: " << endl;

  q.swap(q1);
  cout << "The old q is now: " << endl;
  printQueue(q);
  cout << "The new q is now: " << endl;
  printQueue(q1);
}

/* ------------------------------------------------------------------ */
// max heap
void printPQ(priority_queue<int> pq){
  while(!pq.empty()){
    cout << pq.top() << endl;
    pq.pop();
  }
  cout << endl;
}

void explainPQ(){
  priority_queue<int> pq;
  cout << "Pushing to my priority queue using push: " << endl;
  pq.push(5);
  pq.push(2);
  pq.push(8);
  pq.push(3);
  pq.push(19);
  pq.push(1);
  printPQ(pq);
}

int main(){
  // explainPair();
  // explainVector();
  // explainList();
  // explainDequeue();
  // explainStack();
  // explainQueue();
  explainPQ();
  return 0;
}
