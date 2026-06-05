class TrieNode {
public:
    TrieNode* child[26];
    bool end;
    TrieNode () {
        for (int i =0; i<26; i++) child[i] = nullptr;
        end = false;
    }
};

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *tmp = root;
        for (char c: word) {
            int i = c - 'a';
            if (!tmp->child[i]) tmp->child[i] = new TrieNode();
            tmp = tmp->child[i];
        }
        tmp->end = true;
    }
    
    bool dfs(int idx, string &word, TrieNode *node) {
        TrieNode *curr = node;
        for (int i = idx; i<word.size(); i++) {
            if (word[i] == '.') {
                for (int j = 0; j<26; j++) {
                    if (curr->child[j] && dfs(i+1, word, curr->child[j])) return true;
                }
                return false;
            }

            else {
                int x = word[i] - 'a';
                if (!curr->child[x]) return false;
                curr = curr->child[x];
            }
        }
        return curr->end;
    }
    bool search(string word) {
        return dfs(0, word, root);
    }
};
