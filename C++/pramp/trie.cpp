class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Method to insert a word into the trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    // Method to search for a word in the trie
    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    // Method to check if there is any word in the trie that starts with the given prefix
    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }
};


int main() {
    Trie trie;

    // Insert words into the trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    trie.insert("band");

    // Search for words
    cout << boolalpha; // To print boolean values as true/false
    cout << "Search 'apple': " << trie.search("apple") << endl; // true
    cout << "Search 'app': " << trie.search("app") << endl;     // true
    cout << "Search 'appl': " << trie.search("appl") << endl;   // false
    cout << "Search 'banana': " << trie.search("banana") << endl; // true
    cout << "Search 'band': " << trie.search("band") << endl;   // true
    cout << "Search 'ban': " << trie.search("ban") << endl;     // false

    // Check for prefixes
    cout << "StartsWith 'app': " << trie.startsWith("app") << endl; // true
    cout << "StartsWith 'ban': " << trie.startsWith("ban") << endl; // true
    cout << "StartsWith 'ba': " << trie.startsWith("ba") << endl;   // true
    cout << "StartsWith 'bana': " << trie.startsWith("bana") << endl; // true
    cout << "StartsWith 'bandit': " << trie.startsWith("bandit") << endl; // false

    return 0;
}
