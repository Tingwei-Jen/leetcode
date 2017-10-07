class TrieNode{
public:
    TrieNode(){
        child = vector<TrieNode*>(26, NULL);
        endOfWord = false;
    }
public:  
    vector<TrieNode*> child;        //a-z : 0-25    用vector 比較好用for loop 去遍歷
    bool endOfWord;  
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        
        TrieNode* cur = root;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(!cur->child[index]){                   //沒找到
                TrieNode* node = new TrieNode();
                cur->child[index] = node;
            }
            cur = cur->child[index];
        }
        cur->endOfWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(word, root, 0);
    }
   
    bool find(string word, TrieNode* node, int index){                  //recursive method
        
        if(!node) return false;
        if(index == word.size()) return node->endOfWord;
        if(word[index] != '.'){
            
            int i = word[index]-'a';
            return find(word, node->child[i], index+1); 
            
        } else {
            
            for(int j=0;j<26;j++){
                if(find(word, node->child[j], index+1)) return true;      //找'.' 下一個字符
            }
            return false;
        }
    }
    
    
private:
    TrieNode* root;
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
