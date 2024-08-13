//https://leetcode.cn/problems/implement-trie-ii-prefix-tree/
class Trie {
    struct Node {
        int pass;
        int end;
        unordered_map<int, Node*> next;
        Node() : pass(0), end(0) {};
    };
    Node* head;

public:
    Trie() : head(new Node()) {}

    void insert(string word) {
        if (word.length() < 1) {
            head->end++;
            return;
        }
        Node* cur = head;
        cur->pass++;
        for (int i = 0; i < word.length(); i++) {
            if (cur->next.find(word[i]) == cur->next.end()) {
                cur->next.insert(make_pair(word[i], new Node()));
            }
            cur = cur->next[word[i]];
            cur->pass++;
        }
        cur->end++;
    }

    int countWordsEqualTo(string word) {
        Node* cur = head;
        for (int i = 0; i < word.length(); i++) {
            if (cur->next.find(word[i]) == cur->next.end()) {
                return 0;
            }
            cur = cur->next[word[i]];
        }
        return cur->end;
    }

    int countWordsStartingWith(string prefix) {
        Node* cur = head;
        for (int i = 0; i < prefix.length(); i++) {
            if (cur->next.find(prefix[i]) == cur->next.end()) {
                return 0;
            }
            cur = cur->next[prefix[i]];
        }
        return cur->pass;
    }

    void erase(string word) {
        if (countWordsEqualTo(word) == 0) {
            return;
        }
        if (word.length() == 0) {
            head->end--;
            head->pass--;
            return;
        }
        Node* cur = head, * pre;
        cur->pass--;
        for (int i = 0; i < word.length(); i++) {
            pre = cur;
            cur = cur->next[word[i]];
            cur->pass--;
            if (cur->pass == 0) {
                pre->next.erase(word[i]);
            };
        }
        cur->end--;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */