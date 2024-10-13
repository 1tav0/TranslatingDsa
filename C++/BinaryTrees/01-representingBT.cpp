#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node *left;
  struct Node *right;

  Node(int data){
    data = data;
    left = right = NULL;
  }
};
// helper function to return a new Node with the given data
Node* newNode(int data){
  return new Node(data);
}

// function to create the binary tree using a queue
/*
Suppose we have the vector vec = {1, 2, 3, 4, 5, 6, 7}.
Here's how the function works:

1. Start with the root:

  root = newNode(1) is pushed into the queue.
  We enter the while loop.

2. Processing the root node (1):

  Node = q.front() retrieves the root node (1) and removes it from the queue.
  We create the left child (2) and push it into the queue.
  Then, we create the right child (3) and push it into the queue.
  Now, the queue contains [2, 3].

3. Processing the next level (nodes 2 and 3):

  The for loop runs twice since q.size() = 2 (two nodes at this level).
For Node 2:

  We pop node 2 and assign its left child (4) and right child (5), pushing both into the queue.
For Node 3:

We pop node 3 and assign its left child (6) and right child (7), pushing both into the queue.
Now, the queue contains [4, 5, 6, 7].

4. Processing the next level (nodes 4, 5, 6, 7):

Since there are no more elements in the vector, no more children are created.
The tree is complete.
*/
void createTree(Node* root, vector<int> &vec){
  queue<Node*> q;
  q.push(root);
  int ind = 1;

  while(!q.empty()){
    int cnt = q.size();

    for(int i=0; i<cnt; i++){
      Node* node = q.front();
      q.pop();

      if(ind < vec.size()){
        node->left = newNode(vec[ind]);
        q.push(node->left);
        ind++;
      }

      if(ind < vec.size()){
        node->right = newNode(vec[ind]);
        q.push(node->right);
        ind++;
      }
    }
  }
}



void printTree(Node* root){
  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    int level = q.size();

    for(int i=0; i<level; i++){
      Node* node = q.front();
      q.pop();

      cout << node->data << " ";

      if(node->left != NULL) q.push(node->left);
      if(node->right != NULL) q.push(node->right);

    }
    cout << endl;
  }
}

int main(){
  vector<int> vec = {1, 2, 3, 4, 5, 6, 7};

  // creating the root node
  Node *root = newNode(vec[0]);

  // creating the binary tree
  createTree(root, vec);

  cout << "Binary tree structure (Top-to-Bottom): " << endl;
  printTree(root);

  return 0;
}
