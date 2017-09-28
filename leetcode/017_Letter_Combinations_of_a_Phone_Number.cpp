class Solution {
public:
    vector<string> letterCombinations(string digits) {
    
        vector<string> res;
        if(digits.size()==0)
            return res;        
        string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        //addnumberDFS("", 0, digits, res, dict);
        addnumberBFS(digits, res, dict);
        
        return res;
        
    }
    
    //by recursion/DFS method
    void addnumberDFS(string curString, int curIndex, string digits, vector<string> &res, string dict[]){
        
        if(curIndex == digits.size()) {   //遞迴結束
            res.push_back(curString);
            return;
        } else {
            
            string str = dict[digits[curIndex] - '2'];                    // '2' = 50   (ASC|| table) 
            for(int i=0; i<str.size();i++){                              // if digit[0] = '2'  --> 50-50 = 0;
                
                curString.push_back(str[i]); 
                addnumberDFS(curString, curIndex+1, digits, res, dict);
                curString.pop_back();
            
            }
        }
    }
    
    
    void addnumberBFS(string digits, vector<string> &res, string dict[]){

        res.push_back("");
        
        for(int i=0; i<digits.size();i++){
            
            string str = dict[digits[i]-'2'];
            vector<string> temp;                              //存新加入的node
                
            for(int j=0;j<res.size(); j++){                   // 從queue拿出來的字元
                for(int k=0; k<str.size();k++) {              //從queue出來的字元 後面接了幾個node ex. "a" 後面接了 "ad""ae""af" 三個node
                
                    temp.push_back(res[j]+str[k]);  
                
                }
            }
            
            res = temp;
                
        }
    }
    
};
