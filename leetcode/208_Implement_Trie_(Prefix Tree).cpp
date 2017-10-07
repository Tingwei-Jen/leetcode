class TrieNode{
public:
    TrieNode(){
        child = unordered_map<char, TrieNode*>();
        endOfWord = false;
    }
public:
    unordered_map<char, TrieNode*> child;                  //用來存儲這個TrieNode裡面有沒有某個char以及這個char指向的下一個TrieNode是誰
    bool endOfWord;                                  
    
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();                      //最一開始的TrieNode
    }
    
    
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        TrieNode* current = root;
        for(int i=0;i<word.size();i++){    
            if(current->child.find(word[i]) == current->child.end()){  //沒找到 創一個新的 把字符以及新的(下一個要指向的)node 放到current
                TrieNode* node = new TrieNode();
                current->child[word[i]] = node;  
                current = node;                                        //current 指向下一個node
            } else {                                                
                current = current->child[word[i]];                     //current 指向下一個node
            }
        }
        
        //make current nodes endOfWord as true
        current->endOfWord = true;
    }
    
    
    
    /** Returns if the word is in the trie. */
    /*bool search(string word) {
        
        TrieNode* current = root;
        for(int i=0;i<word.size();i++){
            if(current->child.find(word[i])==current->child.end())    //沒找到return false;
                return false; 
            else                                                      //找到就移動到下一個node
                current = current->child[word[i]];      
        }
        return current->endOfWord;
    }*/
    
    bool search(string word){
        return searchDFS(word, root, 0);   
    }
    bool searchDFS(string word, TrieNode* node, int index){
    
        if(index==word.size()) return node->endOfWord;
        if(node->child.find(word[index])==node->child.end()) 
            return false;
        
        return searchDFS(word, node->child[word[index]], index+1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        TrieNode* current = root;
        for(int i=0; i<prefix.size();i++){
            
            if(current->child.find(prefix[i]) == current->child.end())
                return false;
            else
                current = current->child[prefix[i]];
        }
        return true;
    }

private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
