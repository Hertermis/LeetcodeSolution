//https://leetcode.cn/problems/QC3q1f/
class Trie {
    struct Node {
        int pass;
        int end;
        unordered_map<int, Node*> next;
        Node() : pass(0), end(0) {}
    };
    Node* head;

public:
    /** Initialize your data structure here. */
    Trie() { head = new Node(); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.length() < 1) {
            head->end++;
            return;
        }
        Node* cur = head;
        cur->pass++;
        for (int i = 0; i < word.length() - 1; i++) {
            if (cur->next.find(word[i]) == cur->next.end()) {
                cur->next.insert(make_pair(word[i], new Node()));
            }
            cur = cur->next[word[i]];
            cur->pass++;
        }
        if (cur->next.find(word[word.length() - 1]) == cur->next.end()) {
            cur->next.insert(make_pair(word[word.length() - 1], new Node()));
        }
        cur = cur->next[word[word.length() - 1]];
        cur->end++;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = head;
        for (int i = 0; i < word.length(); i++) {
            if (cur->next.find(word[i]) == cur->next.end()) {
                return false;
            }
            cur = cur->next[word[i]];
        }
        if (cur->end == 0) {
            return false;
        }
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        Node* cur = head;
        for (int i = 0; i < prefix.length(); i++) {
            if (cur->next.find(prefix[i]) == cur->next.end()) {
                return false;
            }
            cur = cur->next[prefix[i]];
        }
        if (cur->pass == 0 && cur->end == 0) {
            return false;
        }
        return true;
    }
};