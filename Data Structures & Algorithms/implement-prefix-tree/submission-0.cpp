class TrieNode {
public:
    TrieNode *child[26];
    bool end;
    TrieNode() {
        for (int i = 0; i<26; i++) child[i] = nullptr;
        end = false;
    }
};

class PrefixTree {
    TrieNode *root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *tmp = root;
        for (auto c: word) {
            int i = c - 'a';
            if (!tmp->child[i]) tmp->child[i] = new TrieNode();
            tmp = tmp->child[i];
        }        
        tmp->end = true;
    }
    
    bool search(string word) {
        TrieNode *tmp = root;
        for (char c: word) {
            int i = c - 'a';
            if (!tmp->child[i]) return false;
            tmp = tmp->child[i];
        }
        return tmp->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode *tmp = root;
        for (char c: prefix) {
            int i = c - 'a';
            if (!tmp->child[i]) return false;
            tmp = tmp->child[i];
        }
        return true;
    }
};
