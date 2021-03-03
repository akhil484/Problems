struct Trie_node{
    bool is_word = false;
    map<char, Trie_node*> children;
    Trie_node(bool _is_word):
        is_word(_is_word){
    };
};

class Trie {
private:
    Trie_node* Root;

public:
    Trie() {
        Root = new Trie_node(false);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie_node* cur_ptr = Root;
        Trie_node* temp;
        for(auto u : word){
            if(cur_ptr -> children.find(u) != cur_ptr -> children.end()){
                // exists current char
                // modify cur_ptr to cur char, go to next level
                cur_ptr = cur_ptr -> children.find(u) -> second;
            }
            else{
                // insert a node contains current char
                temp = new Trie_node(false);
                cur_ptr -> children.insert({u, temp});
                cur_ptr = temp;
            }
        }
		// cur_ptr is always pointing to the last character in the word
        cur_ptr -> is_word = true;
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie_node* cur = Root;
        for(auto u : word){
            if(cur -> children.find(u) == cur -> children.end()){
                return false;
            }
            else{
                cur = cur -> children.find(u) -> second;
            }
        }
        return cur -> is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie_node* cur = Root;
        for(auto u : prefix){
            if(cur -> children.find(u) == cur -> children.end()){
                return false;
            }
            else{
                cur = cur -> children.find(u) -> second;
            }
        }
        return true;// the only difference between two func.
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
