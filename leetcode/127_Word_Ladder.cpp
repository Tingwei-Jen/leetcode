class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        //use bfs by queue or bidirectional bfs
        //https://www.youtube.com/watch?v=vWPCm69MSfs&pbjreload=10
        
        //return BFSmethod(beginWord, endWord, wordList);
        return bidirectionalBFS(beginWord, endWord, wordList);
        
    }
    // 用 bfs 遍歷節點第一層差一個字元 第二層差兩個字元..
    int BFSmethod(string beginWord, string endWord, vector<string>& wordList){
      
        unordered_set<string> wordDict(wordList.begin(), wordList.end());    //用set方便找string
        if(wordDict.count(endWord)==0) return 0;
        
        queue<string> toVisit;
        addNextWords(beginWord, wordDict, toVisit);
        
        int count = 1;
        while(!toVisit.empty()){
            count++;
            int num = toVisit.size();     //這一層有幾個節點
            for(int i=0; i<num; i++){
                string word = toVisit.front();
                toVisit.pop();
                if(word==endWord) return count;
                addNextWords(word, wordDict, toVisit);
            } 
        }
        return 0;                       //沒找到
        
    }
    void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit){
        
        //將找到的word 放入queue之後要visit 然後將word 從wordDict刪掉 以免之後再找回去
        wordDict.erase(word); 
        for(int i=0;i<word.size();i++){    //一次改一個位置 確認有沒有在wordDict裡面
            char temp = word[i];
            for(int j=0;j<26;j++){         //從a到z
                word[i] = j+'a';
                if(wordDict.find(word) != wordDict.end()){    //改過的字在字典裡
                    toVisit.push(word);                       //放到queue裡
                    wordDict.erase(word);                     //從wordDict刪掉 以免之後再找回去
                }
            }
            word[i] = temp;
        }
    }
    int bidirectionalBFS(string beginWord, string endWord, vector<string>& wordList){
        
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if(wordDict.count(endWord) == 0) return 0;
      
        unordered_set<string> head;         //因為要用find()   所以用unordered set 
        unordered_set<string> tail;         //但unordered_set只能用pointer 來尋訪
        unordered_set<string> *phead;
        unordered_set<string> *ptail;
        
        head.insert(beginWord);
        tail.insert(endWord);
        
        int count = 1;
        while(!head.empty() && !tail.empty()){
            
            count++;
            if(head.size()<tail.size()){       //從size較小的queue 開始增加 word
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }
            
            unordered_set<string> temp;
            for (auto itr = phead -> begin(); itr != phead -> end(); itr++) {
                string word = *itr;
                wordDict.erase(word);
                for (int i = 0; i < word.size(); i++) {
                    char letter = word[i];
                    for (int k = 0; k < 26; k++) {
                        word[i] = 'a' + k;
                        if (ptail -> find(word) != ptail -> end())         //發現在另一串裡面 return 
                            return count;
                        if (wordDict.find(word) != wordDict.end()) {       //字典裡有 放入queue
                            temp.insert(word);
                            wordDict.erase(word);
                        }
                    }
                    word[i] = letter;
                }                              
            }
            swap(*phead,temp);
        }
        
        return 0;   
    }
};
