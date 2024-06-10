#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
The car manufacturer Honda holds their distribution system in the form of a
tree (not necessarily binary). The root is the company itself, and every node
in the tree represents a car distributor that receives cars from the parent
node and ships them to its children nodes. The leaf nodes are car dealerships
that sell cars direct to consumers. In addition, every node holds an integer
that is the cost of shipping a car to it.

*/
struct Node {
    int cost;
    vector<Node*> children;
    Node(int cost) : cost(cost) {}
};

int getCheapestCost(Node* rootNode) {
    if (rootNode == NULL) return 0;

    // If there are no children, the cost is just the cost of the current node
    if (rootNode->children.empty()) return rootNode->cost;

    // Initialize the minimum cost to a large value
    int mini = 1e9;

    // Recursively find the minimum cost among all children
    for (auto* child : rootNode->children) {
        int childCost = getCheapestCost(child);
        mini = min(mini, childCost);
    }

    // Add the cost of the current node to the minimum cost of its children
    return mini + rootNode->cost;
}

int main() {
    Node* root = new Node(0);
    Node* child1 = new Node(5);
    Node* child2 = new Node(3);
    Node* child3 = new Node(6);
    Node* leaf1 = new Node(4);
    Node* child5 = new Node(2);
    Node* child6 = new Node(0);
    Node* leaf2 = new Node(1);
    Node* leaf3 = new Node(5);
    Node* child7 = new Node(1);
    Node* leaf4 = new Node(10);
    Node* leaf5 = new Node(1);

    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);

    child1->children.push_back(leaf1);
    child2->children.push_back(child5);
    child2->children.push_back(child6);

    child3->children.push_back(leaf2);
    child3->children.push_back(leaf3);

    child5->children.push_back(child7);
    child6->children.push_back(leaf4);

    child7->children.push_back(leaf5);

    int ans = getCheapestCost(root);
    cout << "Minimal Sales Path Cost: " << ans << endl;

    // Clean up allocated memory
    delete root;
    delete child1;
    delete child2;
    delete child3;
    delete child5;
    delete child6;
    delete child7;

    delete leaf1;
    delete leaf2;
    delete leaf3;
    delete leaf4;
    delete leaf5;

    return 0;
}
